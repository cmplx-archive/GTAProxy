#include "minhook/MinHook.h"
#include <stdint.h>

typedef void(__fastcall* netcat_insert_direct_t)(uint64_t catalog, uint64_t* key, uint64_t** item);
netcat_insert_direct_t netcat_insert_direct = NULL;

typedef size_t(__cdecl* strlen_t)(const char* str);
strlen_t builtin_strlen = NULL;

HMODULE g_hmod = NULL;
HANDLE g_uninject_thread = NULL;

uint64_t netcat_insert_dedupe_addr = 0;
uint64_t strlen_addr = 0;

// not-really-safe strlen
// comes with a built in "cache" for exactly one item
size_t strlen_cacher(char* str) {
	static char* start = NULL;
	static char* end = NULL;
	size_t len = 0;
	const size_t cap = 20000;

	// if we have a "cached" string and current pointer is within it
	if(start && str >= start && str <= end) {
		// calculate the new strlen
		len = end - str;

		// if we're near the end, unload self
		// we don't want to mess something else up
		if(len < cap / 2)
			MH_DisableHook((void*)strlen_addr);

		// super-fast return!
		return len;
	}

	// count the actual length
	// we need at least one measurement of the large JSON
	// or normal strlen for other strings
	len = builtin_strlen(str);

	// if it was the really long string
	// save it's start and end addresses
	if(len > cap) {
		start = str;
		end = str + len;
	}

	// slow, boring return
	return len;
}

// normally this checks for duplicates before inserting
// but to speed things up we just skip that and insert directly
char __fastcall netcat_insert_dedupe_hooked(uint64_t catalog, uint64_t* key, uint64_t* item) {
	// didn't bother reversing the structure
	uint64_t not_a_hashmap = catalog + 88;

	// no idea what this does, but repeat what the original did
	if(!(*(uint8_t(__fastcall**)(uint64_t*))(*item + 48))(item))
		return 0;

	// insert directly
	netcat_insert_direct(not_a_hashmap, key, &item);

	// remove hooks when the last item's hash is hit
	// and unload the .dll, we are done here :)
	if(*key == 0x7FFFD6BE) {
		MH_DisableHook((void*)netcat_insert_dedupe_addr);
	}

	return 1;
}

void init_patch() {
	// set up function hooks
	// addresses hardcoded for Steam version 2215/1.53
	uint64_t base_addr = (uint64_t)GetModuleHandleA(NULL);
	netcat_insert_dedupe_addr = base_addr + 0x10AA918;
	strlen_addr = base_addr + 0x17C01A0;

	netcat_insert_direct = (netcat_insert_direct_t)(base_addr + 0x5BB07C);

	MH_Initialize();

	MH_CreateHook((void*)strlen_addr, &strlen_cacher, (void**)&builtin_strlen);
	MH_CreateHook((void*)netcat_insert_dedupe_addr, &netcat_insert_dedupe_hooked, NULL);

	MH_EnableHook((void*)strlen_addr);
	MH_EnableHook((void*)netcat_insert_dedupe_addr);
}

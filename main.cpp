#undef UNICODE // gcc does not play well with Unicode.
#include <windows.h>
#define fileExists(name) ((GetFileAttributesA(name) != INVALID_FILE_ATTRIBUTES) && (GetLastError() != ERROR_FILE_NOT_FOUND))

const char* autoloadPath = "C:\\GTAProxy\\autoload.dll";

void setup();
int thread();

// BIG THANKS TO https://github.com/tostercx
// Developer who discovered this fix for loading times
void init_patch();

// autoloading
int delayloadThread() {
	Sleep(10000);
	init_patch();
	// delayload if exists
	if(fileExists(autoloadPath)) 
		LoadLibraryA(autoloadPath);
	return 1;
}

// bcause r* is retarded and loading the lib multiple times
bool initialized = false;

int WINAPI DllMain(HMODULE hModule, DWORD reason, void*) {
	if(reason = DLL_PROCESS_ATTACH && !initialized) {

		setup();

		// do whatever you want in the loaderthread
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)thread, 0, 0, 0);

		// thread for delayed autoloading
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)delayloadThread, 0, 0, 0);

		// credits easter egg
		if(GetAsyncKeyState(VK_CONTROL))
			MessageBoxA(0, "The GTAV LibLoader\nmade with love\nby cmplx", "GTAProxy", MB_ICONINFORMATION);

		initialized = true;
	}
	return 1;
}

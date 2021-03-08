#include "hook.h"
#define FileExists(name) ((GetFileAttributesA(name) != INVALID_FILE_ATTRIBUTES) && (GetLastError() != ERROR_FILE_NOT_FOUND))
#define SpawnThread(callback) CreateThread(0, 0, (LPTHREAD_START_ROUTINE)callback, 0, 0, 0)
#define KeyDown(key) (GetAsyncKeyState(key) & 0x8000)
#define MsgBox(text) MessageBoxA(0, text, "debug", 0)

const char* autoloadPath = "C:\\GTAProxy\\autoload.dll";

// BIG THANKS TO https://github.com/tostercx
// Developer who discovered this fix for loading times
void init_patch();

int thread() {
	while(1){

		// ctrl+l
		if(KeyDown(VK_CONTROL) && KeyDown(0x4C)){
			char szFile[MAX_PATH];
			OPENFILENAMEA ofn = {0};
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = "DLL to Load\0*.dll\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if(GetOpenFileNameA(&ofn)) 
				LoadLibraryA(ofn.lpstrFile);
			
		}

		Sleep(5);

	}
	return 1;
}

void attach(HMODULE hModule) {

	// do whatever you want in the loaderthread
	SpawnThread(thread);

	// thread for delayed autoloading
	SpawnThread([](void* data) -> unsigned long {
		Sleep(10000);
		init_patch();
		// delayload if exists
		if(FileExists(autoloadPath))
			LoadLibraryA(autoloadPath);
		return 1;
	});

	// credits easter egg
	if(KeyDown(VK_CONTROL))
		MessageBoxA(0, "The GTAV LibLoader\nmade with love\nby cmplx", "GTAProxy", MB_ICONINFORMATION);
}

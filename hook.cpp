#include <windows.h>

#define LIBNAME "bink2w64org.dll"

struct bink2w64_dll { 
	HMODULE dll;
	FARPROC OrignalBinkBufferBlit;
	FARPROC OrignalBinkBufferCheckWinPos;
	FARPROC OrignalBinkBufferClear;
	FARPROC OrignalBinkBufferClose;
	FARPROC OrignalBinkBufferGetDescription;
	FARPROC OrignalBinkBufferGetError;
	FARPROC OrignalBinkBufferLock;
	FARPROC OrignalBinkBufferOpen;
	FARPROC OrignalBinkBufferSetDirectDraw;
	FARPROC OrignalBinkBufferSetHWND;
	FARPROC OrignalBinkBufferSetOffset;
	FARPROC OrignalBinkBufferSetResolution;
	FARPROC OrignalBinkBufferSetScale;
	FARPROC OrignalBinkBufferUnlock;
	FARPROC OrignalBinkCheckCursor;
	FARPROC OrignalBinkClose;
	FARPROC OrignalBinkCloseTrack;
	FARPROC OrignalBinkControlBackgroundIO;
	FARPROC OrignalBinkControlPlatformFeatures;
	FARPROC OrignalBinkCopyToBuffer;
	FARPROC OrignalBinkCopyToBufferRect;
	FARPROC OrignalBinkDDSurfaceType;
	FARPROC OrignalBinkDX8SurfaceType;
	FARPROC OrignalBinkDX9SurfaceType;
	FARPROC OrignalBinkDoFrame;
	FARPROC OrignalBinkDoFrameAsync;
	FARPROC OrignalBinkDoFrameAsyncMulti;
	FARPROC OrignalBinkDoFrameAsyncWait;
	FARPROC OrignalBinkDoFramePlane;
	FARPROC OrignalBinkFreeGlobals;
	FARPROC OrignalBinkGetError;
	FARPROC OrignalBinkGetFrameBuffersInfo;
	FARPROC OrignalBinkGetGPUDataBuffersInfo;
	FARPROC OrignalBinkGetKeyFrame;
	FARPROC OrignalBinkGetPalette;
	FARPROC OrignalBinkGetPlatformInfo;
	FARPROC OrignalBinkGetRealtime;
	FARPROC OrignalBinkGetRects;
	FARPROC OrignalBinkGetSummary;
	FARPROC OrignalBinkGetTrackData;
	FARPROC OrignalBinkGetTrackID;
	FARPROC OrignalBinkGetTrackMaxSize;
	FARPROC OrignalBinkGetTrackType;
	FARPROC OrignalBinkGoto;
	FARPROC OrignalBinkIsSoftwareCursor;
	FARPROC OrignalBinkLogoAddress;
	FARPROC OrignalBinkNextFrame;
	FARPROC OrignalBinkOpen;
	FARPROC OrignalBinkOpenDirectSound;
	FARPROC OrignalBinkOpenMiles;
	FARPROC OrignalBinkOpenTrack;
	FARPROC OrignalBinkOpenWaveOut;
	FARPROC OrignalBinkOpenWithOptions;
	FARPROC OrignalBinkOpenXAudio2;
	FARPROC OrignalBinkPause;
	FARPROC OrignalBinkRegisterFrameBuffers;
	FARPROC OrignalBinkRegisterGPUDataBuffers;
	FARPROC OrignalBinkRequestStopAsyncThread;
	FARPROC OrignalBinkRestoreCursor;
	FARPROC OrignalBinkService;
	FARPROC OrignalBinkSetError;
	FARPROC OrignalBinkSetFileOffset;
	FARPROC OrignalBinkSetFrameRate;
	FARPROC OrignalBinkSetIO;
	FARPROC OrignalBinkSetIOSize;
	FARPROC OrignalBinkSetMemory;
	FARPROC OrignalBinkSetPan;
	FARPROC OrignalBinkSetSimulate;
	FARPROC OrignalBinkSetSoundOnOff;
	FARPROC OrignalBinkSetSoundSystem;
	FARPROC OrignalBinkSetSoundSystem2;
	FARPROC OrignalBinkSetSoundTrack;
	FARPROC OrignalBinkSetSpeakerVolumes;
	FARPROC OrignalBinkSetVideoOnOff;
	FARPROC OrignalBinkSetVolume;
	FARPROC OrignalBinkSetWillLoop;
	FARPROC OrignalBinkShouldSkip;
	FARPROC OrignalBinkStartAsyncThread;
	FARPROC OrignalBinkUseTelemetry;
	FARPROC OrignalBinkUseTmLite;
	FARPROC OrignalBinkWait;
	FARPROC OrignalBinkWaitStopAsyncThread;
	FARPROC OrignalRADTimerRead;
} bink2w64;

#define NAKED __attribute__((naked))
#define JMPProxy(name, address) NAKED void name() { asm volatile("jmp *%0" : : "r" (address)); }

extern "C"
{
	JMPProxy(FakeBinkBufferBlit, bink2w64.OrignalBinkBufferBlit)
	NAKED void FakeBinkBufferCheckWinPos() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferCheckWinPos)); }
	NAKED void FakeBinkBufferClear() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferClear)); }
	NAKED void FakeBinkBufferClose() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferClose)); }
	NAKED void FakeBinkBufferGetDescription() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferGetDescription)); }
	NAKED void FakeBinkBufferGetError() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferGetError)); }
	NAKED void FakeBinkBufferLock() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferLock)); }
	NAKED void FakeBinkBufferOpen() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferOpen)); }
	NAKED void FakeBinkBufferSetDirectDraw() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferSetDirectDraw)); }
	NAKED void FakeBinkBufferSetHWND() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferSetHWND)); }
	NAKED void FakeBinkBufferSetOffset() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferSetOffset)); }
	NAKED void FakeBinkBufferSetResolution() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferSetResolution)); }
	NAKED void FakeBinkBufferSetScale() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferSetScale)); }
	NAKED void FakeBinkBufferUnlock() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkBufferUnlock)); }
	NAKED void FakeBinkCheckCursor() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkCheckCursor)); }
	NAKED void FakeBinkClose() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkClose)); }
	NAKED void FakeBinkCloseTrack() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkCloseTrack)); }
	NAKED void FakeBinkControlBackgroundIO() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkControlBackgroundIO)); }
	NAKED void FakeBinkControlPlatformFeatures() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkControlPlatformFeatures)); }
	NAKED void FakeBinkCopyToBuffer() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkCopyToBuffer)); }
	NAKED void FakeBinkCopyToBufferRect() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkCopyToBufferRect)); }
	NAKED void FakeBinkDDSurfaceType() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkDDSurfaceType)); }
	NAKED void FakeBinkDX8SurfaceType() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkDX8SurfaceType)); }
	NAKED void FakeBinkDX9SurfaceType() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkDX9SurfaceType)); }
	NAKED void FakeBinkDoFrame() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkDoFrame)); }
	NAKED void FakeBinkDoFrameAsync() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkDoFrameAsync)); }
	NAKED void FakeBinkDoFrameAsyncMulti() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkDoFrameAsyncMulti)); }
	NAKED void FakeBinkDoFrameAsyncWait() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkDoFrameAsyncWait)); }
	NAKED void FakeBinkDoFramePlane() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkDoFramePlane)); }
	NAKED void FakeBinkFreeGlobals() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkFreeGlobals)); }
	NAKED void FakeBinkGetError() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetError)); }
	NAKED void FakeBinkGetFrameBuffersInfo() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetFrameBuffersInfo)); }
	NAKED void FakeBinkGetGPUDataBuffersInfo() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetGPUDataBuffersInfo)); }
	NAKED void FakeBinkGetKeyFrame() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetKeyFrame)); }
	NAKED void FakeBinkGetPalette() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetPalette)); }
	NAKED void FakeBinkGetPlatformInfo() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetPlatformInfo)); }
	NAKED void FakeBinkGetRealtime() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetRealtime)); }
	NAKED void FakeBinkGetRects() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetRects)); }
	NAKED void FakeBinkGetSummary() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetSummary)); }
	NAKED void FakeBinkGetTrackData() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetTrackData)); }
	NAKED void FakeBinkGetTrackID() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetTrackID)); }
	NAKED void FakeBinkGetTrackMaxSize() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetTrackMaxSize)); }
	NAKED void FakeBinkGetTrackType() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGetTrackType)); }
	NAKED void FakeBinkGoto() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkGoto)); }
	NAKED void FakeBinkIsSoftwareCursor() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkIsSoftwareCursor)); }
	NAKED void FakeBinkLogoAddress() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkLogoAddress)); }
	NAKED void FakeBinkNextFrame() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkNextFrame)); }
	NAKED void FakeBinkOpen() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkOpen)); }
	NAKED void FakeBinkOpenDirectSound() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkOpenDirectSound)); }
	NAKED void FakeBinkOpenMiles() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkOpenMiles)); }
	NAKED void FakeBinkOpenTrack() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkOpenTrack)); }
	NAKED void FakeBinkOpenWaveOut() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkOpenWaveOut)); }
	NAKED void FakeBinkOpenWithOptions() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkOpenWithOptions)); }
	NAKED void FakeBinkOpenXAudio2() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkOpenXAudio2)); }
	NAKED void FakeBinkPause() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkPause)); }
	NAKED void FakeBinkRegisterFrameBuffers() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkRegisterFrameBuffers)); }
	NAKED void FakeBinkRegisterGPUDataBuffers() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkRegisterGPUDataBuffers)); }
	NAKED void FakeBinkRequestStopAsyncThread() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkRequestStopAsyncThread)); }
	NAKED void FakeBinkRestoreCursor() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkRestoreCursor)); }
	NAKED void FakeBinkService() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkService)); }
	NAKED void FakeBinkSetError() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetError)); }
	NAKED void FakeBinkSetFileOffset() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetFileOffset)); }
	NAKED void FakeBinkSetFrameRate() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetFrameRate)); }
	NAKED void FakeBinkSetIO() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetIO)); }
	NAKED void FakeBinkSetIOSize() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetIOSize)); }
	NAKED void FakeBinkSetMemory() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetMemory)); }
	NAKED void FakeBinkSetPan() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetPan)); }
	NAKED void FakeBinkSetSimulate() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetSimulate)); }
	NAKED void FakeBinkSetSoundOnOff() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetSoundOnOff)); }
	NAKED void FakeBinkSetSoundSystem() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetSoundSystem)); }
	NAKED void FakeBinkSetSoundSystem2() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetSoundSystem2)); }
	NAKED void FakeBinkSetSoundTrack() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetSoundTrack)); }
	NAKED void FakeBinkSetSpeakerVolumes() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetSpeakerVolumes)); }
	NAKED void FakeBinkSetVideoOnOff() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetVideoOnOff)); }
	NAKED void FakeBinkSetVolume() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetVolume)); }
	NAKED void FakeBinkSetWillLoop() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkSetWillLoop)); }
	NAKED void FakeBinkShouldSkip() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkShouldSkip)); }
	NAKED void FakeBinkStartAsyncThread() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkStartAsyncThread)); }
	NAKED void FakeBinkUseTelemetry() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkUseTelemetry)); }
	NAKED void FakeBinkUseTmLite() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkUseTmLite)); }
	NAKED void FakeBinkWait() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkWait)); }
	NAKED void FakeBinkWaitStopAsyncThread() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalBinkWaitStopAsyncThread)); }
	NAKED void FakeRADTimerRead() { asm volatile("jmp *%0" : : "r" (bink2w64.OrignalRADTimerRead)); }
}

void setup(){

		bink2w64.dll = LoadLibraryA(LIBNAME);
		if (bink2w64.dll == 0){
			MessageBoxA(0, "Cannot load original library", "Proxy", MB_ICONERROR);
			ExitProcess(0);
		}

		bink2w64.OrignalBinkBufferBlit = GetProcAddress(bink2w64.dll, "BinkBufferBlit");
		bink2w64.OrignalBinkBufferCheckWinPos = GetProcAddress(bink2w64.dll, "BinkBufferCheckWinPos");
		bink2w64.OrignalBinkBufferClear = GetProcAddress(bink2w64.dll, "BinkBufferClear");
		bink2w64.OrignalBinkBufferClose = GetProcAddress(bink2w64.dll, "BinkBufferClose");
		bink2w64.OrignalBinkBufferGetDescription = GetProcAddress(bink2w64.dll, "BinkBufferGetDescription");
		bink2w64.OrignalBinkBufferGetError = GetProcAddress(bink2w64.dll, "BinkBufferGetError");
		bink2w64.OrignalBinkBufferLock = GetProcAddress(bink2w64.dll, "BinkBufferLock");
		bink2w64.OrignalBinkBufferOpen = GetProcAddress(bink2w64.dll, "BinkBufferOpen");
		bink2w64.OrignalBinkBufferSetDirectDraw = GetProcAddress(bink2w64.dll, "BinkBufferSetDirectDraw");
		bink2w64.OrignalBinkBufferSetHWND = GetProcAddress(bink2w64.dll, "BinkBufferSetHWND");
		bink2w64.OrignalBinkBufferSetOffset = GetProcAddress(bink2w64.dll, "BinkBufferSetOffset");
		bink2w64.OrignalBinkBufferSetResolution = GetProcAddress(bink2w64.dll, "BinkBufferSetResolution");
		bink2w64.OrignalBinkBufferSetScale = GetProcAddress(bink2w64.dll, "BinkBufferSetScale");
		bink2w64.OrignalBinkBufferUnlock = GetProcAddress(bink2w64.dll, "BinkBufferUnlock");
		bink2w64.OrignalBinkCheckCursor = GetProcAddress(bink2w64.dll, "BinkCheckCursor");
		bink2w64.OrignalBinkClose = GetProcAddress(bink2w64.dll, "BinkClose");
		bink2w64.OrignalBinkCloseTrack = GetProcAddress(bink2w64.dll, "BinkCloseTrack");
		bink2w64.OrignalBinkControlBackgroundIO = GetProcAddress(bink2w64.dll, "BinkControlBackgroundIO");
		bink2w64.OrignalBinkControlPlatformFeatures = GetProcAddress(bink2w64.dll, "BinkControlPlatformFeatures");
		bink2w64.OrignalBinkCopyToBuffer = GetProcAddress(bink2w64.dll, "BinkCopyToBuffer");
		bink2w64.OrignalBinkCopyToBufferRect = GetProcAddress(bink2w64.dll, "BinkCopyToBufferRect");
		bink2w64.OrignalBinkDDSurfaceType = GetProcAddress(bink2w64.dll, "BinkDDSurfaceType");
		bink2w64.OrignalBinkDX8SurfaceType = GetProcAddress(bink2w64.dll, "BinkDX8SurfaceType");
		bink2w64.OrignalBinkDX9SurfaceType = GetProcAddress(bink2w64.dll, "BinkDX9SurfaceType");
		bink2w64.OrignalBinkDoFrame = GetProcAddress(bink2w64.dll, "BinkDoFrame");
		bink2w64.OrignalBinkDoFrameAsync = GetProcAddress(bink2w64.dll, "BinkDoFrameAsync");
		bink2w64.OrignalBinkDoFrameAsyncMulti = GetProcAddress(bink2w64.dll, "BinkDoFrameAsyncMulti");
		bink2w64.OrignalBinkDoFrameAsyncWait = GetProcAddress(bink2w64.dll, "BinkDoFrameAsyncWait");
		bink2w64.OrignalBinkDoFramePlane = GetProcAddress(bink2w64.dll, "BinkDoFramePlane");
		bink2w64.OrignalBinkFreeGlobals = GetProcAddress(bink2w64.dll, "BinkFreeGlobals");
		bink2w64.OrignalBinkGetError = GetProcAddress(bink2w64.dll, "BinkGetError");
		bink2w64.OrignalBinkGetFrameBuffersInfo = GetProcAddress(bink2w64.dll, "BinkGetFrameBuffersInfo");
		bink2w64.OrignalBinkGetGPUDataBuffersInfo = GetProcAddress(bink2w64.dll, "BinkGetGPUDataBuffersInfo");
		bink2w64.OrignalBinkGetKeyFrame = GetProcAddress(bink2w64.dll, "BinkGetKeyFrame");
		bink2w64.OrignalBinkGetPalette = GetProcAddress(bink2w64.dll, "BinkGetPalette");
		bink2w64.OrignalBinkGetPlatformInfo = GetProcAddress(bink2w64.dll, "BinkGetPlatformInfo");
		bink2w64.OrignalBinkGetRealtime = GetProcAddress(bink2w64.dll, "BinkGetRealtime");
		bink2w64.OrignalBinkGetRects = GetProcAddress(bink2w64.dll, "BinkGetRects");
		bink2w64.OrignalBinkGetSummary = GetProcAddress(bink2w64.dll, "BinkGetSummary");
		bink2w64.OrignalBinkGetTrackData = GetProcAddress(bink2w64.dll, "BinkGetTrackData");
		bink2w64.OrignalBinkGetTrackID = GetProcAddress(bink2w64.dll, "BinkGetTrackID");
		bink2w64.OrignalBinkGetTrackMaxSize = GetProcAddress(bink2w64.dll, "BinkGetTrackMaxSize");
		bink2w64.OrignalBinkGetTrackType = GetProcAddress(bink2w64.dll, "BinkGetTrackType");
		bink2w64.OrignalBinkGoto = GetProcAddress(bink2w64.dll, "BinkGoto");
		bink2w64.OrignalBinkIsSoftwareCursor = GetProcAddress(bink2w64.dll, "BinkIsSoftwareCursor");
		bink2w64.OrignalBinkLogoAddress = GetProcAddress(bink2w64.dll, "BinkLogoAddress");
		bink2w64.OrignalBinkNextFrame = GetProcAddress(bink2w64.dll, "BinkNextFrame");
		bink2w64.OrignalBinkOpen = GetProcAddress(bink2w64.dll, "BinkOpen");
		bink2w64.OrignalBinkOpenDirectSound = GetProcAddress(bink2w64.dll, "BinkOpenDirectSound");
		bink2w64.OrignalBinkOpenMiles = GetProcAddress(bink2w64.dll, "BinkOpenMiles");
		bink2w64.OrignalBinkOpenTrack = GetProcAddress(bink2w64.dll, "BinkOpenTrack");
		bink2w64.OrignalBinkOpenWaveOut = GetProcAddress(bink2w64.dll, "BinkOpenWaveOut");
		bink2w64.OrignalBinkOpenWithOptions = GetProcAddress(bink2w64.dll, "BinkOpenWithOptions");
		bink2w64.OrignalBinkOpenXAudio2 = GetProcAddress(bink2w64.dll, "BinkOpenXAudio2");
		bink2w64.OrignalBinkPause = GetProcAddress(bink2w64.dll, "BinkPause");
		bink2w64.OrignalBinkRegisterFrameBuffers = GetProcAddress(bink2w64.dll, "BinkRegisterFrameBuffers");
		bink2w64.OrignalBinkRegisterGPUDataBuffers = GetProcAddress(bink2w64.dll, "BinkRegisterGPUDataBuffers");
		bink2w64.OrignalBinkRequestStopAsyncThread = GetProcAddress(bink2w64.dll, "BinkRequestStopAsyncThread");
		bink2w64.OrignalBinkRestoreCursor = GetProcAddress(bink2w64.dll, "BinkRestoreCursor");
		bink2w64.OrignalBinkService = GetProcAddress(bink2w64.dll, "BinkService");
		bink2w64.OrignalBinkSetError = GetProcAddress(bink2w64.dll, "BinkSetError");
		bink2w64.OrignalBinkSetFileOffset = GetProcAddress(bink2w64.dll, "BinkSetFileOffset");
		bink2w64.OrignalBinkSetFrameRate = GetProcAddress(bink2w64.dll, "BinkSetFrameRate");
		bink2w64.OrignalBinkSetIO = GetProcAddress(bink2w64.dll, "BinkSetIO");
		bink2w64.OrignalBinkSetIOSize = GetProcAddress(bink2w64.dll, "BinkSetIOSize");
		bink2w64.OrignalBinkSetMemory = GetProcAddress(bink2w64.dll, "BinkSetMemory");
		bink2w64.OrignalBinkSetPan = GetProcAddress(bink2w64.dll, "BinkSetPan");
		bink2w64.OrignalBinkSetSimulate = GetProcAddress(bink2w64.dll, "BinkSetSimulate");
		bink2w64.OrignalBinkSetSoundOnOff = GetProcAddress(bink2w64.dll, "BinkSetSoundOnOff");
		bink2w64.OrignalBinkSetSoundSystem = GetProcAddress(bink2w64.dll, "BinkSetSoundSystem");
		bink2w64.OrignalBinkSetSoundSystem2 = GetProcAddress(bink2w64.dll, "BinkSetSoundSystem2");
		bink2w64.OrignalBinkSetSoundTrack = GetProcAddress(bink2w64.dll, "BinkSetSoundTrack");
		bink2w64.OrignalBinkSetSpeakerVolumes = GetProcAddress(bink2w64.dll, "BinkSetSpeakerVolumes");
		bink2w64.OrignalBinkSetVideoOnOff = GetProcAddress(bink2w64.dll, "BinkSetVideoOnOff");
		bink2w64.OrignalBinkSetVolume = GetProcAddress(bink2w64.dll, "BinkSetVolume");
		bink2w64.OrignalBinkSetWillLoop = GetProcAddress(bink2w64.dll, "BinkSetWillLoop");
		bink2w64.OrignalBinkShouldSkip = GetProcAddress(bink2w64.dll, "BinkShouldSkip");
		bink2w64.OrignalBinkStartAsyncThread = GetProcAddress(bink2w64.dll, "BinkStartAsyncThread");
		bink2w64.OrignalBinkUseTelemetry = GetProcAddress(bink2w64.dll, "BinkUseTelemetry");
		bink2w64.OrignalBinkUseTmLite = GetProcAddress(bink2w64.dll, "BinkUseTmLite");
		bink2w64.OrignalBinkWait = GetProcAddress(bink2w64.dll, "BinkWait");
		bink2w64.OrignalBinkWaitStopAsyncThread = GetProcAddress(bink2w64.dll, "BinkWaitStopAsyncThread");
		bink2w64.OrignalRADTimerRead = GetProcAddress(bink2w64.dll, "RADTimerRead");
}
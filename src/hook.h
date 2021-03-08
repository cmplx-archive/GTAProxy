#ifndef PROXY_H
#define PROXY_H

#undef UNICODE // gcc does not play well with Unicode.
#include <windows.h>

#define LIBNAME "bink2w64org.dll"

// bcause r* is retarded and calling functions in the dll by GetProcAddr(LoadLibA("bink2w64.dll"), function)();
bool initialized = false;

// do in there whatever you want
void attach(HMODULE);

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
	JMPProxy(FakeBinkBufferCheckWinPos,bink2w64.OrignalBinkBufferCheckWinPos)
	JMPProxy(FakeBinkBufferClear,bink2w64.OrignalBinkBufferClear)
	JMPProxy(FakeBinkBufferClose,bink2w64.OrignalBinkBufferClose)
	JMPProxy(FakeBinkBufferGetDescription,bink2w64.OrignalBinkBufferGetDescription)
	JMPProxy(FakeBinkBufferGetError,bink2w64.OrignalBinkBufferGetError)
	JMPProxy(FakeBinkBufferLock,bink2w64.OrignalBinkBufferLock)
	JMPProxy(FakeBinkBufferOpen,bink2w64.OrignalBinkBufferOpen)
	JMPProxy(FakeBinkBufferSetDirectDraw,bink2w64.OrignalBinkBufferSetDirectDraw)
	JMPProxy(FakeBinkBufferSetHWND,bink2w64.OrignalBinkBufferSetHWND)
	JMPProxy(FakeBinkBufferSetOffset,bink2w64.OrignalBinkBufferSetOffset)
	JMPProxy(FakeBinkBufferSetResolution,bink2w64.OrignalBinkBufferSetResolution)
	JMPProxy(FakeBinkBufferSetScale,bink2w64.OrignalBinkBufferSetScale)
	JMPProxy(FakeBinkBufferUnlock,bink2w64.OrignalBinkBufferUnlock)
	JMPProxy(FakeBinkCheckCursor,bink2w64.OrignalBinkCheckCursor)
	JMPProxy(FakeBinkClose,bink2w64.OrignalBinkClose)
	JMPProxy(FakeBinkCloseTrack,bink2w64.OrignalBinkCloseTrack)
	JMPProxy(FakeBinkControlBackgroundIO,bink2w64.OrignalBinkControlBackgroundIO)
	JMPProxy(FakeBinkControlPlatformFeatures,bink2w64.OrignalBinkControlPlatformFeatures)
	JMPProxy(FakeBinkCopyToBuffer,bink2w64.OrignalBinkCopyToBuffer)
	JMPProxy(FakeBinkCopyToBufferRect,bink2w64.OrignalBinkCopyToBufferRect)
	JMPProxy(FakeBinkDDSurfaceType,bink2w64.OrignalBinkDDSurfaceType)
	JMPProxy(FakeBinkDX8SurfaceType,bink2w64.OrignalBinkDX8SurfaceType)
	JMPProxy(FakeBinkDX9SurfaceType,bink2w64.OrignalBinkDX9SurfaceType)
	JMPProxy(FakeBinkDoFrame,bink2w64.OrignalBinkDoFrame)
	JMPProxy(FakeBinkDoFrameAsync,bink2w64.OrignalBinkDoFrameAsync)
	JMPProxy(FakeBinkDoFrameAsyncMulti,bink2w64.OrignalBinkDoFrameAsyncMulti)
	JMPProxy(FakeBinkDoFrameAsyncWait,bink2w64.OrignalBinkDoFrameAsyncWait)
	JMPProxy(FakeBinkDoFramePlane,bink2w64.OrignalBinkDoFramePlane)
	JMPProxy(FakeBinkFreeGlobals,bink2w64.OrignalBinkFreeGlobals)
	JMPProxy(FakeBinkGetError,bink2w64.OrignalBinkGetError)
	JMPProxy(FakeBinkGetFrameBuffersInfo,bink2w64.OrignalBinkGetFrameBuffersInfo)
	JMPProxy(FakeBinkGetGPUDataBuffersInfo,bink2w64.OrignalBinkGetGPUDataBuffersInfo)
	JMPProxy(FakeBinkGetKeyFrame,bink2w64.OrignalBinkGetKeyFrame)
	JMPProxy(FakeBinkGetPalette,bink2w64.OrignalBinkGetPalette)
	JMPProxy(FakeBinkGetPlatformInfo,bink2w64.OrignalBinkGetPlatformInfo)
	JMPProxy(FakeBinkGetRealtime,bink2w64.OrignalBinkGetRealtime)
	JMPProxy(FakeBinkGetRects,bink2w64.OrignalBinkGetRects)
	JMPProxy(FakeBinkGetSummary,bink2w64.OrignalBinkGetSummary)
	JMPProxy(FakeBinkGetTrackData,bink2w64.OrignalBinkGetTrackData)
	JMPProxy(FakeBinkGetTrackID,bink2w64.OrignalBinkGetTrackID)
	JMPProxy(FakeBinkGetTrackMaxSize,bink2w64.OrignalBinkGetTrackMaxSize)
	JMPProxy(FakeBinkGetTrackType,bink2w64.OrignalBinkGetTrackType)
	JMPProxy(FakeBinkGoto,bink2w64.OrignalBinkGoto)
	JMPProxy(FakeBinkIsSoftwareCursor,bink2w64.OrignalBinkIsSoftwareCursor)
	JMPProxy(FakeBinkLogoAddress,bink2w64.OrignalBinkLogoAddress)
	JMPProxy(FakeBinkNextFrame,bink2w64.OrignalBinkNextFrame)
	JMPProxy(FakeBinkOpen,bink2w64.OrignalBinkOpen)
	JMPProxy(FakeBinkOpenDirectSound,bink2w64.OrignalBinkOpenDirectSound)
	JMPProxy(FakeBinkOpenMiles,bink2w64.OrignalBinkOpenMiles)
	JMPProxy(FakeBinkOpenTrack,bink2w64.OrignalBinkOpenTrack)
	JMPProxy(FakeBinkOpenWaveOut,bink2w64.OrignalBinkOpenWaveOut)
	JMPProxy(FakeBinkOpenWithOptions,bink2w64.OrignalBinkOpenWithOptions)
	JMPProxy(FakeBinkOpenXAudio2,bink2w64.OrignalBinkOpenXAudio2)
	JMPProxy(FakeBinkPause,bink2w64.OrignalBinkPause)
	JMPProxy(FakeBinkRegisterFrameBuffers,bink2w64.OrignalBinkRegisterFrameBuffers)
	JMPProxy(FakeBinkRegisterGPUDataBuffers,bink2w64.OrignalBinkRegisterGPUDataBuffers)
	JMPProxy(FakeBinkRequestStopAsyncThread,bink2w64.OrignalBinkRequestStopAsyncThread)
	JMPProxy(FakeBinkRestoreCursor,bink2w64.OrignalBinkRestoreCursor)
	JMPProxy(FakeBinkService,bink2w64.OrignalBinkService)
	JMPProxy(FakeBinkSetError,bink2w64.OrignalBinkSetError)
	JMPProxy(FakeBinkSetFileOffset,bink2w64.OrignalBinkSetFileOffset)
	JMPProxy(FakeBinkSetFrameRate,bink2w64.OrignalBinkSetFrameRate)
	JMPProxy(FakeBinkSetIO,bink2w64.OrignalBinkSetIO)
	JMPProxy(FakeBinkSetIOSize,bink2w64.OrignalBinkSetIOSize)
	JMPProxy(FakeBinkSetMemory,bink2w64.OrignalBinkSetMemory)
	JMPProxy(FakeBinkSetPan,bink2w64.OrignalBinkSetPan)
	JMPProxy(FakeBinkSetSimulate,bink2w64.OrignalBinkSetSimulate)
	JMPProxy(FakeBinkSetSoundOnOff,bink2w64.OrignalBinkSetSoundOnOff)
	JMPProxy(FakeBinkSetSoundSystem,bink2w64.OrignalBinkSetSoundSystem)
	JMPProxy(FakeBinkSetSoundSystem2,bink2w64.OrignalBinkSetSoundSystem2)
	JMPProxy(FakeBinkSetSoundTrack,bink2w64.OrignalBinkSetSoundTrack)
	JMPProxy(FakeBinkSetSpeakerVolumes,bink2w64.OrignalBinkSetSpeakerVolumes)
	JMPProxy(FakeBinkSetVideoOnOff,bink2w64.OrignalBinkSetVideoOnOff)
	JMPProxy(FakeBinkSetVolume,bink2w64.OrignalBinkSetVolume)
	JMPProxy(FakeBinkSetWillLoop,bink2w64.OrignalBinkSetWillLoop)
	JMPProxy(FakeBinkShouldSkip,bink2w64.OrignalBinkShouldSkip)
	JMPProxy(FakeBinkStartAsyncThread,bink2w64.OrignalBinkStartAsyncThread)
	JMPProxy(FakeBinkUseTelemetry,bink2w64.OrignalBinkUseTelemetry)
	JMPProxy(FakeBinkUseTmLite,bink2w64.OrignalBinkUseTmLite)
	JMPProxy(FakeBinkWait,bink2w64.OrignalBinkWait)
	JMPProxy(FakeBinkWaitStopAsyncThread,bink2w64.OrignalBinkWaitStopAsyncThread)
	JMPProxy(FakeRADTimerRead,bink2w64.OrignalRADTimerRead)
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

int WINAPI DllMain(HMODULE hModule, DWORD reason, void*) {
	if(reason = DLL_PROCESS_ATTACH && !initialized) {
		setup();
		attach(hModule);
		initialized = true;
	}
	return 1;
}

#endif
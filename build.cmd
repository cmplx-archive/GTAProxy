@echo off
set out=build/bink2w64.dll
set src=src/online_patch.cpp src/main.cpp src/proxy.def

g++ -shared -o %out% %src% -Lsrc/minhook -lminhook -lComdlg32 -fpermissive -lPsapi
if %errorlevel% EQU 1 (pause)
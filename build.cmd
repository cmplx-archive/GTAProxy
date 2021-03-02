@echo off
set out=bink2w64.dll
set src=online_patch.cpp hook.cpp loaderthread.cpp main.cpp bink2w64.def
set minhook=minhook\buffer.c minhook\hook.c minhook\trampoline.c minhook\hde\hde64.c minhook\hde\hde32.c

g++ -shared -o %out% %src% %minhook% -lComdlg32 -fpermissive
if %errorlevel% EQU 1 (pause)
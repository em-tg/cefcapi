@echo off

if not exist .\Release (
    call .\deps.bat
)

set CC=x86_64-w64-mingw32-gcc
set WARNINGS=-Wall -Wextra -Wpedantic -Wconversion -Wno-unused-parameter
set DBG_FLAGS=-g
set CFLAGS=%DBG_FLAGS% %WARNINGS% -isystem.\cef_extracted -I.
set LFLAGS=-L.\Release -lcef

set CFILES=.\examples\main_win.c

%CC% %CFLAGS% -o .\Release\cef_example.exe %CFILES% %LFLAGS%

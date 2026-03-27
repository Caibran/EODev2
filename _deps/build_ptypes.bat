@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
setlocal enabledelayedexpansion
set SRCDIR=C:\eodev_build\ptypes\src
set INCDIR=C:\eodev_build\ptypes\include
set OUTDIR=C:\eodev_build\ptypes_build
set LIBOUT=C:\eodev_build\ptypes.lib
if not exist "%OUTDIR%" mkdir "%OUTDIR%"
echo Building PTypes...
set CXXFLAGS=/c /EHsc /O2 /MDd /W2 /wd4996 /wd4267 /wd4244 /wd4018 /I"%INCDIR%" /D "WIN32" /D "_WINDOWS" /nologo
set EC=0
set SC=0
for %%f in (%SRCDIR%\*.cxx) do (
    if /I not "%%~nf"=="ptypes_test" (
        cl !CXXFLAGS! /Fo"%OUTDIR%\%%~nf.obj" "%%f" >nul 2>&1
        if errorlevel 1 (
            echo FAIL: %%~nf.cxx
            set /a EC+=1
            if exist "%OUTDIR%\%%~nf.obj" del /q "%OUTDIR%\%%~nf.obj"
        ) else (
            set /a SC+=1
        )
    )
)
echo Compiled !SC! ok, !EC! failed
if !SC! GTR 0 (
    lib /OUT:"%LIBOUT%" /NOLOGO %OUTDIR%\*.obj
    if exist "%LIBOUT%" ( echo SUCCESS ) else ( echo LIB_FAILED )
)

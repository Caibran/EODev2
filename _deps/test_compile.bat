@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
echo INCLUDE path test: %INCLUDE:~0,50%...
echo.
echo Attempting single file compile test...
cl /c /EHsc /O2 /MDd /W2 /I"c:\Users\gundr\Documents\Developer Brain\EODev2-master\_deps\ptypes\include" /D "WIN32" /D "_WINDOWS" /nologo /Fo"c:\Users\gundr\Documents\Developer Brain\EODev2-master\_deps\ptypes_build\pversion.obj" "c:\Users\gundr\Documents\Developer Brain\EODev2-master\_deps\ptypes\src\pversion.cxx"
echo Exit code: %ERRORLEVEL%

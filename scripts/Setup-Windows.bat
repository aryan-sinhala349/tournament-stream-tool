@echo off

py ./SetupPremake.py

pushd %~dp0\..\
REM call vendor\premake\bin\premake5.exe vs2022 --target=windows
popd
pause

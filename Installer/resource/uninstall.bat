@echo off
echo:
echo This will completely remove HotkeyMapper from your PC...
pause
echo:
echo Setting environment variables
set installdir=HotKeyMapper
set appmain=HotKeyMapper.exe
set apphelp=HotkeyHelper.exe
set batuninstall=uninstall.bat
echo Changing to current working directory...
cd /D "%~dp0"
echo Removing Start Menu links...
del /f /s /q "%userprofile%\Start Menu\Programs\HotkeyMapper.lnk" >NUL  2>NUL
del /f /s /q "%userprofile%\Start Menu\Programs\HotkeyMapper Uninstall.lnk" >NUL  2>NUL
echo Removing files at directory: %LOCALAPPDATA%\%installdir%\...
rd /s /q "%LOCALAPPDATA%\%installdir%\"  >NUL  2>NUL
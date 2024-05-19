@echo off
echo:
echo Installing Thinkpad Hotkey Mapper...

echo:
echo Setting environment variables
set resourcedir=resource
set installdir=HotKeyMapper
set appmain=HotKeyMapper.exe
set apphelp=HotkeyHelper.exe
set batuninstall=uninstall.bat
echo Changing to current working directory...
cd /D "%~dp0"
echo Creating Installation Directory at %LOCALAPPDATA%\%installdir%\...
if not exist "%LOCALAPPDATA%\%installdir%\" mkdir %LOCALAPPDATA%\%installdir%\  >NUL  2>NUL
echo Copying main app...
copy /Y "%resourcedir%\%appmain%" "%LOCALAPPDATA%\%installdir%\%appmain%"  >NUL  2>NUL
echo Copying helper executable...
copy /Y "%resourcedir%\%apphelper%" "%LOCALAPPDATA%\%installdir%\%apphelper%"  >NUL  2>NUL
echo Copying uninstall script...
copy /Y "%resourcedir%\%batuninstall%" "%LOCALAPPDATA%\%installdir%\%batuninstall%"  >NUL  2>NUL
echo Creating Start Menu links...
powershell "$s=(New-Object -COM WScript.Shell).CreateShortcut('%userprofile%\Start Menu\Programs\HotkeyMapper.lnk');$s.TargetPath='%LOCALAPPDATA%\%installdir%\%appmain%';$s.Save()"
powershell "$s=(New-Object -COM WScript.Shell).CreateShortcut('%userprofile%\Start Menu\Programs\HotkeyMapper Uninstall.lnk');$s.TargetPath='%LOCALAPPDATA%\%installdir%\%batuninstall%';$s.Save()"
echo:
echo Installation complete! You may now delete this folder.
echo:
pause
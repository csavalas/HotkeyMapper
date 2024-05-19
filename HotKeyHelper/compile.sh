windres resource.rc -o resource.o
gcc resource.o HotkeyHelper.cpp -lstdc++ -mwindows -DUNICODE -o HotkeyHelper.exe
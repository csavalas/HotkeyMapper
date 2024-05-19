// Virtual Key Reference:
// https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

#define WINVER 0x0500
#include <windows.h>
#include <string>
#include <bits/stdc++.h>
#include "resource.h"

#define TYPE_LENGTH 10
#define FOCUS_STEAL "steal_focus"
#define FOCUS_KEEP "keep_focus"
#define TYPE_KEY_SEQ "key_seq"
#define TYPE_KEY_COMBO "key_combo"

using namespace std;

HINSTANCE hInst;
vector<string> v;

BOOL shown = FALSE;

int DoInput() {
    char type[TYPE_LENGTH];
    strcpy(type, v[1].c_str());
    // Key Operations
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Key Sequence
    if ((!strcmp(TYPE_KEY_SEQ, type))) {
        for (int i = 2; i < v.size(); i++) {
            ip.ki.wVk = std::stoi(v[i], 0, 16);
            ip.ki.dwFlags = !KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        }
    // Key Combo
    } else {
        for (int i = 2; i < v.size(); i++) {
            ip.ki.wVk = std::stoi(v[i], 0, 16);
            ip.ki.dwFlags = !KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        }
        for (int i = 2; i < v.size(); i++) {
            ip.ki.wVk = std::stoi(v[i], 0, 16);
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        }
    }
    return 0;
}

BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_PAINT:
            if (!shown) {
                DoInput();
                shown = TRUE;
            } else {
                PostMessage(hwndDlg, WM_CLOSE, 0, 0);
            }
            return TRUE;

        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return TRUE;

        case WM_INITDIALOG:
            return TRUE;
    }
    return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
    string str = lpCmdLine;
    int start, end;
    start = end = 0;
    char dl = ' ';
    while ((start = str.find_first_not_of(dl, end)) != string::npos) {
        end = str.find(dl, start);
        v.push_back(str.substr(start, end - start));
    }
    hInst = hInstance;

    if ((!strcmp(FOCUS_STEAL, v[0].c_str()))) {
        return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
    }
    return DoInput();
}

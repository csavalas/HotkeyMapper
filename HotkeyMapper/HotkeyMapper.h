
// HotkeyMapper.h : main header file for the PROJECT_NAME application
//
#include "fstream"
#include "iostream"
#include <regex>

#pragma once

std::string convert_cstring(CString s);
void UpdateRegistry(CString key, std::string file, CString parameters, CString helper_prefix);
void ClearRegistry(CString key);
#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CHotkeyMapperApp:
// See HotkeyMapper.cpp for the implementation of this class
//

class CHotkeyMapperApp : public CWinApp
{
public:
	CHotkeyMapperApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CHotkeyMapperApp theApp;

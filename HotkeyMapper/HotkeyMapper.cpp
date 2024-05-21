
// HotkeyMapper.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "HotkeyMapper.h"
#include "HotkeyMapperDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

std::string convert_cstring(CString s) {
	std::wstring ws = std::wstring(s.GetString());
	return std::string(ws.begin(), ws.end());
}

void UpdateRegistry(LPSTR key, std::string file, CString parameters, CString helper_prefix) {
	//std::wstring ws = std::wstring(parameters.GetString());
	//std::string parameters_string = std::string(ws.begin(), ws.end());
	std::string parameters_string = convert_cstring(parameters);
	std::string helper_prefix_string = convert_cstring(helper_prefix);

	auto file_formatted =  std::regex_replace(file, std::regex(R"(\\)"), R"(\\)");
	auto parameters_formatted = std::regex_replace(parameters_string, std::regex(R"(\\)"), R"(\\)");

	std::string filename = (std::string(std::getenv("USERPROFILE")) + "\\tmp_hotkeymapper.reg").c_str();
	std::ofstream outfile;
	outfile.open(filename);
	outfile << "Windows Registry Editor Version 5.00\n\n";
	outfile << "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Lenovo\\ShortcutKey\\AppLaunch\\" << key << "]\n";
	outfile << "\"AppType\"=dword:00000001\n\n";
	outfile << "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Lenovo\\ShortcutKey\\AppLaunch\\" << key << "\\Desktop]\n";
	outfile << "\"File\"=\"" << file_formatted << "\"\n";
	outfile << "\"Parameters\"=\"" << helper_prefix_string << parameters_formatted << "\"\n\n";
	outfile << "[HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Teams]\n\n";
	outfile.close();
	system((std::string("regedit /s ") + std::string(filename)).c_str());
	system((std::string("del ") + std::string(filename)).c_str());
}

void ClearRegistry(LPSTR key) {
	std::string filename = (std::string(std::getenv("USERPROFILE")) + "\\tmp_hotkeymapper.reg").c_str();
	std::ofstream outfile;
	outfile.open(filename);
	outfile << "Windows Registry Editor Version 5.00\n\n";
	outfile << "[-HKEY_LOCAL_MACHINE\\SOFTWARE\\Lenovo\\ShortcutKey\\AppLaunch\\" << key << "]\n\n";
	outfile.close();
	system((std::string("regedit /s ") + std::string(filename)).c_str());
	system((std::string("del ") + std::string(filename)).c_str());
}

// CHotkeyMapperApp

BEGIN_MESSAGE_MAP(CHotkeyMapperApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CHotkeyMapperApp construction

CHotkeyMapperApp::CHotkeyMapperApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CHotkeyMapperApp object

CHotkeyMapperApp theApp;


// CHotkeyMapperApp initialization

BOOL CHotkeyMapperApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CHotkeyMapperDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


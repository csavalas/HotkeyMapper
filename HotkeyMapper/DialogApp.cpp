// DialogApp.cpp : implementation file
//

#include "pch.h"
#include "HotkeyMapper.h"
#include "afxdialogex.h"
#include "DialogApp.h"


// DialogApp dialog

IMPLEMENT_DYNAMIC(DialogApp, CDialog)

DialogApp::DialogApp(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_APP, pParent)
	, ValueAppParams(_T(""))
	, ValueApp(_T(""))
{

}

DialogApp::~DialogApp()
{
}

void DialogApp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_APP_PARAMS, ValueAppParams);
	DDX_Text(pDX, IDC_EDIT_APP, ValueApp);
}


BEGIN_MESSAGE_MAP(DialogApp, CDialog)
	ON_BN_CLICKED(IDC_BROWSE_APP, &DialogApp::OnClickedBrowseApp)
	ON_BN_CLICKED(ID_APPLY_APP, &DialogApp::OnClickedApplyApp)
END_MESSAGE_MAP()


// DialogApp message handlers


void DialogApp::OnClickedBrowseApp()
{
	const TCHAR szFilter[] = _T("Apps (*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("*"), NULL, OFN_OVERWRITEPROMPT, szFilter, this);
	if (dlg.DoModal() == IDOK)
	{
		ValueApp = dlg.GetPathName();
		UpdateData(false);
	}
}


void DialogApp::OnClickedApplyApp()
{
	if (!ValueApp.GetLength()) {
		MessageBoxA(NULL, "Must Select an app!", "Warning!", MB_OK);
	}
	else {
		OnOK();
	}
}


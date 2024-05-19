// DialogFile.cpp : implementation file
//

#include "pch.h"
#include "HotkeyMapper.h"
#include "afxdialogex.h"
#include "DialogFile.h"


// DialogFile dialog

IMPLEMENT_DYNAMIC(DialogFile, CDialog)

DialogFile::DialogFile(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_FILE, pParent)
	, ValueFile(_T(""))
{

}

DialogFile::~DialogFile()
{
}

void DialogFile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILE, ValueFile);
}


BEGIN_MESSAGE_MAP(DialogFile, CDialog)
	ON_BN_CLICKED(IDC_FILE_BROWSE, &DialogFile::OnClickedFileBrowse)
	ON_BN_CLICKED(ID_FILE_APPLY, &DialogFile::OnClickedFileApply)
END_MESSAGE_MAP()


// DialogFile message handlers




void DialogFile::OnClickedFileBrowse()
{
	const TCHAR szFilter[] = _T("Any file (*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("*"), NULL, OFN_OVERWRITEPROMPT, szFilter, this);
	if (dlg.DoModal() == IDOK)
	{
		ValueFile = dlg.GetPathName();
		UpdateData(false);
	}
}


void DialogFile::OnClickedFileApply()
{
	if (!ValueFile.GetLength()) {
		MessageBoxA(NULL, "Must Select a file!", "Warning!", MB_OK);
	}
	else {
		OnOK();
	}
}

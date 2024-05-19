// DialogURL.cpp : implementation file
//

#include "pch.h"
#include "HotkeyMapper.h"
#include "afxdialogex.h"
#include "DialogURL.h"


// DialogURL dialog

IMPLEMENT_DYNAMIC(DialogURL, CDialog)

DialogURL::DialogURL(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_URL, pParent)
	, ValueURL(_T(""))
{

}


DialogURL::~DialogURL()
{
}

void DialogURL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_URL, ControlURL);
	DDX_Text(pDX, IDC_EDIT_URL, ValueURL);
}


BEGIN_MESSAGE_MAP(DialogURL, CDialog)
	ON_BN_CLICKED(ID_URL_APPLY, &DialogURL::OnBnClickedUrlApply)
END_MESSAGE_MAP()


// DialogURL message handlers


void DialogURL::OnBnClickedUrlApply()
{
	UpdateData(true);
	if (!ValueURL.Find(L"https://", 0) || !ValueURL.Find(L"http://", 0)) {
		OnOK();
	}
	else {
		MessageBox(L"Must contain https:// or http:// prefix!", L"Error", MB_OK);
	}
}


BOOL DialogURL::OnInitDialog()
{
	CDialog::OnInitDialog();
	ValueURL = "https://";
	UpdateData(false);
	ControlURL.SetFocus();
	ControlURL.SetSel(-1);
	return FALSE;
}

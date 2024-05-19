#pragma once
#include "afxdialogex.h"


// DialogURL dialog

class DialogURL : public CDialog
{
	DECLARE_DYNAMIC(DialogURL)

public:
	DialogURL(CWnd* pParent = nullptr);   // standard constructor
	LPSTR key;
	virtual ~DialogURL();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_URL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedUrlApply();
	CEdit ControlURL;
	CString ValueURL;
	virtual BOOL OnInitDialog();
};

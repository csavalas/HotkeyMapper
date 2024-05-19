#pragma once
#include "afxdialogex.h"


// DialogApp dialog

class DialogApp : public CDialog
{
	DECLARE_DYNAMIC(DialogApp)

public:
	DialogApp(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DialogApp();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_APP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString ValueAppParams;
	CString ValueApp;
	afx_msg void OnClickedBrowseApp();
	afx_msg void OnClickedApplyApp();
};

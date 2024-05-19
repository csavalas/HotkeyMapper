#pragma once
#include "afxdialogex.h"


// DialogFile dialog

class DialogFile : public CDialog
{
	DECLARE_DYNAMIC(DialogFile)

public:
	DialogFile(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DialogFile();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FILE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString ValueFile;
	afx_msg void OnClickedFileBrowse();
	afx_msg void OnClickedFileApply();
};

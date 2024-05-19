#pragma once
#include "afxdialogex.h"


// DialogKeys dialog

class DialogKeys : public CDialog
{
	DECLARE_DYNAMIC(DialogKeys)

public:
	DialogKeys(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DialogKeys();
	CFont m_font;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_KEYS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedApplyKeys();
	afx_msg void OnClickedAddKey();
	CString ValueKeysSelected;
	virtual BOOL OnInitDialog();
	CComboBox ControlKeys;
	BOOL ValueStealFocus;
	int lastKey;
	afx_msg void OnSelchangeComboKeys();
};

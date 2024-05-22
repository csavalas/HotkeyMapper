#pragma once
#include "afxdialogex.h"
#define DETECT_STATE_INACTIVE 0
#define DETECT_STATE_WAITING 1
#define DETECT_STATE_CAPTURED 2

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
	CEdit ControlDetect;
	afx_msg void OnSetfocusEditDetectKey();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int DetectionState;
	CString DetectInstructions = L"Click here to detect a key by keystroke...";
	bool isCombo;
	afx_msg void OnClickedStealFocus();
};

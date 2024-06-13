
// HotkeyMapperDlg.h : header file
//


#pragma once

// CHotkeyMapperDlg dialog
class CHotkeyMapperDlg : public CDialogEx
{
// Construction
public:
	CHotkeyMapperDlg(CWnd* pParent = nullptr);	// standard constructor
	CFont m_font;
	CString getKeyCode();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOTKEYMAPPER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton9Url();
	afx_msg void OnClickedButton9File();
	afx_msg void OnClickedButton9App();
	afx_msg void OnClickedButton9KeySeq();
	afx_msg void OnClickedButton9KeyCombo();
	afx_msg void OnBnClickedButtonReset();
	CComboBox ControlFKeySelect;
	CComboBox ControlModelSelect;
	afx_msg void OnSelchangeComboModelSelect();
	afx_msg void OnSelchangeComboFKeySelect();
	virtual void OnCancel();
	afx_msg void OnClose();
};

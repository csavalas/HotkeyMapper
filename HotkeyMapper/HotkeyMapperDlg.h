
// HotkeyMapperDlg.h : header file
//


#pragma once

// CHotkeyMapperDlg dialog
class CHotkeyMapperDlg : public CDialogEx
{
// Construction
public:
	CHotkeyMapperDlg(CWnd* pParent = nullptr);	// standard constructor

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
	afx_msg void OnClickedButton10Url();
	afx_msg void OnClickedButton11Url();
	afx_msg void OnClickedButton9File();
	afx_msg void OnClickedButton11File();
	afx_msg void OnClickedButton10File();
	afx_msg void OnClickedButton9App();
	afx_msg void OnClickedButton10App();
	afx_msg void OnClickedButton11App();
	afx_msg void OnClickedButton9KeySeq();
	afx_msg void OnClickedButton10KeySeq();
	afx_msg void OnClickedButton11KeySeq();
	afx_msg void OnClickedButton9KeyCombo();
	afx_msg void OnClickedButton10KeyCombo();
	afx_msg void OnClickedButton11KeyCombo();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonReset();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

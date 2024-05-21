
// HotkeyMapperDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "HotkeyMapper.h"
#include "HotkeyMapperDlg.h"
#include "afxdialogex.h"
#include "DialogURL.h"
#include "DialogFile.h"
#include "DialogApp.h"
#include "DialogKeys.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()



// CHotkeyMapperDlg dialog



CHotkeyMapperDlg::CHotkeyMapperDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOTKEYMAPPER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHotkeyMapperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHotkeyMapperDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_9_URL, &CHotkeyMapperDlg::OnClickedButton9Url)
	ON_BN_CLICKED(IDC_BUTTON_10_URL, &CHotkeyMapperDlg::OnClickedButton10Url)
	ON_BN_CLICKED(IDC_BUTTON_11_URL, &CHotkeyMapperDlg::OnClickedButton11Url)
	ON_BN_CLICKED(IDC_BUTTON_9_FILE, &CHotkeyMapperDlg::OnClickedButton9File)
	ON_BN_CLICKED(IDC_BUTTON_11_FILE, &CHotkeyMapperDlg::OnClickedButton11File)
	ON_BN_CLICKED(IDC_BUTTON_10_FILE, &CHotkeyMapperDlg::OnClickedButton10File)
	ON_BN_CLICKED(IDC_BUTTON_9_APP, &CHotkeyMapperDlg::OnClickedButton9App)
	ON_BN_CLICKED(IDC_BUTTON_10_APP, &CHotkeyMapperDlg::OnClickedButton10App)
	ON_BN_CLICKED(IDC_BUTTON_11_APP, &CHotkeyMapperDlg::OnClickedButton11App)
	ON_BN_CLICKED(IDC_BUTTON_9_KEY_SEQ, &CHotkeyMapperDlg::OnClickedButton9KeySeq)
	ON_BN_CLICKED(IDC_BUTTON_10_KEY_SEQ, &CHotkeyMapperDlg::OnClickedButton10KeySeq)
	ON_BN_CLICKED(IDC_BUTTON_11_KEY_SEQ, &CHotkeyMapperDlg::OnClickedButton11KeySeq)
	ON_BN_CLICKED(IDC_BUTTON_9_KEY_COMBO, &CHotkeyMapperDlg::OnClickedButton9KeyCombo)
	ON_BN_CLICKED(IDC_BUTTON_10_KEY_COMBO, &CHotkeyMapperDlg::OnClickedButton10KeyCombo)
	ON_BN_CLICKED(IDC_BUTTON_11_KEY_COMBO, &CHotkeyMapperDlg::OnClickedButton11KeyCombo)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CHotkeyMapperDlg::OnBnClickedButtonReset)
END_MESSAGE_MAP()




// CHotkeyMapperDlg message handlers

BOOL CHotkeyMapperDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CHotkeyMapperDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHotkeyMapperDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHotkeyMapperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void DoURLModal(LPSTR key) {
	DialogURL DlgURL;
	if (DlgURL.DoModal() == 1) {
		UpdateRegistry(
			key,
			(LPSTR) (std::string(std::getenv("WINDIR")) + "\\explorer.exe").c_str(),
			DlgURL.ValueURL,
			CString("")
		);
		MessageBoxA(NULL, "Successfully applied changes!", "Information", MB_OK);
	}
}


void CHotkeyMapperDlg::OnClickedButton9Url()
{
	DoURLModal("Ex_96");
}


void CHotkeyMapperDlg::OnClickedButton10Url()
{
	DoURLModal("Ex_97");
}


void CHotkeyMapperDlg::OnClickedButton11Url()
{
	DoURLModal("Ex_98");
}


void DoFileModal(LPSTR key) {
	DialogFile DlgFile;
	if (DlgFile.DoModal() == 1) {
		UpdateRegistry(
			key,
			(LPSTR)(std::string(std::getenv("WINDIR")) + "\\explorer.exe").c_str(),
			DlgFile.ValueFile,
			CString("")
		);
		MessageBoxA(NULL, "Successfully applied changes!", "Information", MB_OK);
	}
}

void CHotkeyMapperDlg::OnClickedButton9File()
{
	DoFileModal("Ex_96");
}


void CHotkeyMapperDlg::OnClickedButton10File()
{
	DoFileModal("Ex_97");
}


void CHotkeyMapperDlg::OnClickedButton11File()
{
	DoFileModal("Ex_98");
}


void DoAppModal(LPSTR key) {
	DialogApp DlgApp;
	if (DlgApp.DoModal() == 1) {
		UpdateRegistry(
			key,
			convert_cstring(DlgApp.ValueApp),
			DlgApp.ValueAppParams,
			CString("")
		);
		MessageBoxA(NULL, "Successfully applied changes!", "Information", MB_OK);
	}
}

void CHotkeyMapperDlg::OnClickedButton9App()
{
	DoAppModal("Ex_96");
}


void CHotkeyMapperDlg::OnClickedButton10App()
{
	DoAppModal("Ex_97");
}


void CHotkeyMapperDlg::OnClickedButton11App()
{
	DoAppModal("Ex_98");
}


void DoKeysModal(LPSTR key, BOOL isCombo) {
	DialogKeys DlgKeys;
	if (DlgKeys.DoModal() == 1) {
		UpdateRegistry(
			key,
			(LPSTR)(std::string(std::getenv("localappdata")) + "\\HotkeyMapper\\HotkeyHelper.exe").c_str(),
			DlgKeys.ValueKeysSelected,
			CString(DlgKeys.ValueStealFocus ? "steal_focus " : "keep_focus ") + CString(isCombo ? "key_combo" : "key_seq")
		);
		MessageBoxA(NULL, "Successfully applied changes!", "Information", MB_OK);
	}
}


void CHotkeyMapperDlg::OnClickedButton9KeySeq()
{
	DoKeysModal("Ex_96", false);
}


void CHotkeyMapperDlg::OnClickedButton10KeySeq()
{
	DoKeysModal("Ex_97", false);
}


void CHotkeyMapperDlg::OnClickedButton11KeySeq()
{
	DoKeysModal("Ex_98", false);
}


void CHotkeyMapperDlg::OnClickedButton9KeyCombo()
{
	DoKeysModal("Ex_96", true);
}


void CHotkeyMapperDlg::OnClickedButton10KeyCombo()
{
	DoKeysModal("Ex_97", true);
}


void CHotkeyMapperDlg::OnClickedButton11KeyCombo()
{
	DoKeysModal("Ex_98", true);
}


HBRUSH CHotkeyMapperDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	return hbr;
}



void CHotkeyMapperDlg::OnBnClickedButtonReset()
{
	// TODO: Add your control notification handler code here
	if (MessageBoxA(NULL, "Reset F9-F11 keys to defaults?", "Warning", MB_YESNO) == IDYES) {
		ClearRegistry("Ex_96");
		ClearRegistry("Ex_97");
		ClearRegistry("Ex_98");
		MessageBoxA(NULL, "Successfully reset to defaults!", "Info", MB_OK);
	}
}



BOOL CHotkeyMapperDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	//if (pMsg->message == WM_SYSKEYDOWN) {
	//	OnOK();
	//}
	return CDialogEx::PreTranslateMessage(pMsg);
}

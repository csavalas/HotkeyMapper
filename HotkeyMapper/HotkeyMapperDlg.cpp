
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

#define modelsLength 2
CString models[modelsLength] = {
	L"Newer",
	L"Older",
};

#define FKeysLength 9
CString FKeys[FKeysLength][modelsLength + 1] = {
	{L"F4", L"Ex_1A", L"Ex_1A"},
	{L"F5", L"Ex_10", L"Ex_10"},
	{L"F6", L"Ex_0F", L"Ex_0F"},
	{L"F7", L"7", L"7"},
	{L"F8", L"5", L"5"},
	{L"F9", L"Ex_96", L"Ex_1C"},
	{L"F10", L"Ex_97", L"Ex_93"},
	{L"F11", L"Ex_98", L"Ex_94"},
	{L"F12", L"Ex_90", L"Ex_90"},
};



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
	DDX_Control(pDX, IDC_COMBO_F_KEY_SELECT, ControlFKeySelect);
	DDX_Control(pDX, IDC_COMBO_MODEL_SELECT, ControlModelSelect);
}

BEGIN_MESSAGE_MAP(CHotkeyMapperDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_URL, &CHotkeyMapperDlg::OnClickedButton9Url)
	ON_BN_CLICKED(IDC_BUTTON_FILE, &CHotkeyMapperDlg::OnClickedButton9File)
	ON_BN_CLICKED(IDC_BUTTON_APP, &CHotkeyMapperDlg::OnClickedButton9App)
	ON_BN_CLICKED(IDC_BUTTON_KEY_SEQ, &CHotkeyMapperDlg::OnClickedButton9KeySeq)
	ON_BN_CLICKED(IDC_BUTTON_KEY_COMBO, &CHotkeyMapperDlg::OnClickedButton9KeyCombo)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CHotkeyMapperDlg::OnBnClickedButtonReset)
	ON_CBN_SELCHANGE(IDC_COMBO_MODEL_SELECT, &CHotkeyMapperDlg::OnSelchangeComboModelSelect)
	ON_CBN_SELCHANGE(IDC_COMBO_F_KEY_SELECT, &CHotkeyMapperDlg::OnSelchangeComboFKeySelect)
	ON_WM_CLOSE()
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
	m_font.CreatePointFont(75, L"Courier New Bold");

	for (int i = 0; i < modelsLength; i++) {
		ControlModelSelect.AddString(models[i]);
	}
	ControlModelSelect.SetFont(&m_font);
	ControlModelSelect.SetCueBanner(L"Select a model...");


	for (int i = 0; i < FKeysLength; i++) {
		ControlFKeySelect.AddString(FKeys[i][0]);
	}
	ControlFKeySelect.SetFont(&m_font);
	ControlFKeySelect.SetCueBanner(L"Select an F-key...");
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

void CHotkeyMapperDlg::OnCancel()
{
	//CDialogEx::OnCancel();
}

void CHotkeyMapperDlg::OnClose()
{
	CDialogEx::OnCancel();
	//CDialogEx::OnClose();
}

CString CHotkeyMapperDlg::getKeyCode() {
	return FKeys[ControlFKeySelect.GetCurSel()][ControlModelSelect.GetCurSel() + 1];
}

void DoURLModal(CString key) {
	DialogURL DlgURL;
	if (DlgURL.DoModal() == 1) {
		UpdateRegistry(
			key,
			(LPSTR)(std::string(std::getenv("WINDIR")) + "\\explorer.exe").c_str(),
			DlgURL.ValueURL,
			CString("")
		);
		MessageBoxA(NULL, "Successfully applied changes!", "Information", MB_OK);
	}
}

void CHotkeyMapperDlg::OnClickedButton9Url()
{
	DoURLModal(getKeyCode());
}


void DoFileModal(CString key) {
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
	DoFileModal(getKeyCode());
}

void DoAppModal(CString key) {
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
	DoAppModal(getKeyCode());
}


void DoKeysModal(CString key, BOOL isCombo) {
	DialogKeys DlgKeys;
	DlgKeys.isCombo = isCombo;
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
	DoKeysModal(getKeyCode(), false);
}


void CHotkeyMapperDlg::OnClickedButton9KeyCombo()
{
	DoKeysModal(getKeyCode(), true);
}



void CHotkeyMapperDlg::OnBnClickedButtonReset()
{
	if (MessageBoxA(NULL, "Clear customization?", "Warning", MB_YESNO) == IDYES) {
		ClearRegistry(getKeyCode());
		MessageBoxA(NULL, "Successfully cleared!", "Info", MB_OK);
	}
}


void CHotkeyMapperDlg::OnSelchangeComboModelSelect()
{
	UpdateData(TRUE);
	if (ControlModelSelect.GetCurSel() > -1) {
		//ControlModelSelect.EnableWindow(false);
		ControlFKeySelect.EnableWindow(true);
		//ControlFKeySelect.SetFocus();
	}
}


void CHotkeyMapperDlg::OnSelchangeComboFKeySelect()
{
	UpdateData(TRUE);
	if (ControlFKeySelect.GetCurSel() > -1) {
		if (ControlFKeySelect.GetCurSel() == 1
		|| ControlFKeySelect.GetCurSel() == 2) {
			GetDlgItem(IDC_BETA_WARNING)->ShowWindow(SW_SHOW);
		}
		else {
			GetDlgItem(IDC_BETA_WARNING)->ShowWindow(SW_HIDE);
		}
		GetDlgItem(IDC_BUTTON_URL)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_FILE)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_APP)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_KEY_SEQ)->EnableWindow(true);
		//GetDlgItem(IDC_BUTTON_KEY_SEQ)->SetFocus();
		GetDlgItem(IDC_BUTTON_KEY_COMBO)->EnableWindow(true);	
		GetDlgItem(IDC_BUTTON_RESET)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_RESET)->SetWindowTextW(L"Clear customization for " + FKeys[ControlFKeySelect.GetCurSel()][0]);
	}
}


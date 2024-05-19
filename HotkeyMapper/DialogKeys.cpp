// DialogKeys.cpp : implementation file
//

#include "pch.h"
#include "HotkeyMapper.h"
#include "afxdialogex.h"
#include "DialogKeys.h"


#define KeyCodesLength 260
CString KeyCodes[KeyCodesLength][2] = {
{L"0x01", L"Left mouse button          (0x01)"},
{L"0x02", L"Right mouse button         (0x02)"},
{L"0x03", L"Control-break processing   (0x03)"},
{L"0x04", L"Middle mouse button        (0x04)"},
{L"0x05", L"X1 mouse button            (0x05)"},
{L"0x06", L"X2 mouse button            (0x06)"},
{L"0x07", L"Reserved                   (0x07)"},
{L"0x08", L"BACKSPACE key              (0x08)"},
{L"0x09", L"TAB key                    (0x09)"},
{L"0x0A", L"Reserved                   (0x0A)"},
{L"0x0B", L"Reserved                   (0x0B)"},
{L"0x0C", L"CLEAR key                  (0x0C)"},
{L"0x0D", L"ENTER key                  (0x0D)"},
{L"0x0E", L"Unassigned                 (0x0E)"},
{L"0x0F", L"Unassigned                 (0x0F)"},
{L"0x10", L"SHIFT key                  (0x10)"},
{L"0x11", L"CTRL key                   (0x11)"},
{L"0x12", L"ALT key                    (0x12)"},
{L"0x13", L"PAUSE key                  (0x13)"},
{L"0x14", L"CAPS LOCK key              (0x14)"},
{L"0x15", L"IME Kana mode              (0x15)"},
{L"0x15", L"IME Hangul mode            (0x15)"},
{L"0x16", L"IME On                     (0x16)"},
{L"0x17", L"IME Junja mode             (0x17)"},
{L"0x18", L"IME final mode             (0x18)"},
{L"0x19", L"IME Hanja mode             (0x19)"},
{L"0x19", L"IME Kanji mode             (0x19)"},
{L"0x1A", L"IME Off                    (0x1A)"},
{L"0x1B", L"ESC key                    (0x1B)"},
{L"0x1C", L"IME convert                (0x1C)"},
{L"0x1D", L"IME nonconvert             (0x1D)"},
{L"0x1E", L"IME accept                 (0x1E)"},
{L"0x1F", L"IME mode change request    (0x1F)"},
{L"0x20", L"SPACEBAR                   (0x20)"},
{L"0x21", L"PAGE UP key                (0x21)"},
{L"0x22", L"PAGE DOWN key              (0x22)"},
{L"0x23", L"END key                    (0x23)"},
{L"0x24", L"HOME key                   (0x24)"},
{L"0x25", L"LEFT ARROW key             (0x25)"},
{L"0x26", L"UP ARROW key               (0x26)"},
{L"0x27", L"RIGHT ARROW key            (0x27)"},
{L"0x28", L"DOWN ARROW key             (0x28)"},
{L"0x29", L"SELECT key                 (0x29)"},
{L"0x2A", L"PRINT key                  (0x2A)"},
{L"0x2B", L"EXECUTE key                (0x2B)"},
{L"0x2C", L"PRINT SCREEN key           (0x2C)"},
{L"0x2D", L"INS key                    (0x2D)"},
{L"0x2E", L"DEL key                    (0x2E)"},
{L"0x2F", L"HELP key                   (0x2F)"},
{L"0x30", L"0 key                      (0x30)"},
{L"0x31", L"1 key                      (0x31)"},
{L"0x32", L"2 key                      (0x32)"},
{L"0x33", L"3 key                      (0x33)"},
{L"0x34", L"4 key                      (0x34)"},
{L"0x35", L"5 key                      (0x35)"},
{L"0x36", L"6 key                      (0x36)"},
{L"0x37", L"7 key                      (0x37)"},
{L"0x38", L"8 key                      (0x38)"},
{L"0x39", L"9 key                      (0x39)"},
{L"0x3A", L"Undefined                  (0x3A)"},
{L"0x3B", L"Undefined                  (0x3B)"},
{L"0x3C", L"Undefined                  (0x3C)"},
{L"0x3D", L"Undefined                  (0x3D)"},
{L"0x3E", L"Undefined                  (0x3E)"},
{L"0x3F", L"Undefined                  (0x3F)"},
{L"0x40", L"Undefined                  (0x40)"},
{L"0x41", L"A key                      (0x41)"},
{L"0x42", L"B key                      (0x42)"},
{L"0x43", L"C key                      (0x43)"},
{L"0x44", L"D key                      (0x44)"},
{L"0x45", L"E key                      (0x45)"},
{L"0x46", L"F key                      (0x46)"},
{L"0x47", L"G key                      (0x47)"},
{L"0x48", L"H key                      (0x48)"},
{L"0x49", L"I key                      (0x49)"},
{L"0x4A", L"J key                      (0x4A)"},
{L"0x4B", L"K key                      (0x4B)"},
{L"0x4C", L"L key                      (0x4C)"},
{L"0x4D", L"M key                      (0x4D)"},
{L"0x4E", L"N key                      (0x4E)"},
{L"0x4F", L"O key                      (0x4F)"},
{L"0x50", L"P key                      (0x50)"},
{L"0x51", L"Q key                      (0x51)"},
{L"0x52", L"R key                      (0x52)"},
{L"0x53", L"S key                      (0x53)"},
{L"0x54", L"T key                      (0x54)"},
{L"0x55", L"U key                      (0x55)"},
{L"0x56", L"V key                      (0x56)"},
{L"0x57", L"W key                      (0x57)"},
{L"0x58", L"X key                      (0x58)"},
{L"0x59", L"Y key                      (0x59)"},
{L"0x5A", L"Z key                      (0x5A)"},
{L"0x5B", L"Left Windows key           (0x5B)"},
{L"0x5C", L"Right Windows key          (0x5C)"},
{L"0x5D", L"Applications key           (0x5D)"},
{L"0x5E", L"Reserved                   (0x5E)"},
{L"0x5F", L"Computer Sleep key         (0x5F)"},
{L"0x60", L"Numeric keypad 0 key       (0x60)"},
{L"0x61", L"Numeric keypad 1 key       (0x61)"},
{L"0x62", L"Numeric keypad 2 key       (0x62)"},
{L"0x63", L"Numeric keypad 3 key       (0x63)"},
{L"0x64", L"Numeric keypad 4 key       (0x64)"},
{L"0x65", L"Numeric keypad 5 key       (0x65)"},
{L"0x66", L"Numeric keypad 6 key       (0x66)"},
{L"0x67", L"Numeric keypad 7 key       (0x67)"},
{L"0x68", L"Numeric keypad 8 key       (0x68)"},
{L"0x69", L"Numeric keypad 9 key       (0x69)"},
{L"0x6A", L"Multiply key               (0x6A)"},
{L"0x6B", L"Add key                    (0x6B)"},
{L"0x6C", L"Separator key              (0x6C)"},
{L"0x6D", L"Subtract key               (0x6D)"},
{L"0x6E", L"Decimal key                (0x6E)"},
{L"0x6F", L"Divide key                 (0x6F)"},
{L"0x70", L"F1 key                     (0x70)"},
{L"0x71", L"F2 key                     (0x71)"},
{L"0x72", L"F3 key                     (0x72)"},
{L"0x73", L"F4 key                     (0x73)"},
{L"0x74", L"F5 key                     (0x74)"},
{L"0x75", L"F6 key                     (0x75)"},
{L"0x76", L"F7 key                     (0x76)"},
{L"0x77", L"F8 key                     (0x77)"},
{L"0x78", L"F9 key                     (0x78)"},
{L"0x79", L"F10 key                    (0x79)"},
{L"0x7A", L"F11 key                    (0x7A)"},
{L"0x7B", L"F12 key                    (0x7B)"},
{L"0x7C", L"F13 key                    (0x7C)"},
{L"0x7D", L"F14 key                    (0x7D)"},
{L"0x7E", L"F15 key                    (0x7E)"},
{L"0x7F", L"F16 key                    (0x7F)"},
{L"0x80", L"F17 key                    (0x80)"},
{L"0x81", L"F18 key                    (0x81)"},
{L"0x82", L"F19 key                    (0x82)"},
{L"0x83", L"F20 key                    (0x83)"},
{L"0x84", L"F21 key                    (0x84)"},
{L"0x85", L"F22 key                    (0x85)"},
{L"0x86", L"F23 key                    (0x86)"},
{L"0x87", L"F24 key                    (0x87)"},
{L"0x88", L"Reserved                   (0x88)"},
{L"0x89", L"Reserved                   (0x89)"},
{L"0x8A", L"Reserved                   (0x8A)"},
{L"0x8B", L"Reserved                   (0x8B)"},
{L"0x8C", L"Reserved                   (0x8C)"},
{L"0x8D", L"Reserved                   (0x8D)"},
{L"0x8E", L"Reserved                   (0x8E)"},
{L"0x8F", L"Reserved                   (0x8F)"},
{L"0x90", L"NUM LOCK key               (0x90)"},
{L"0x91", L"SCROLL LOCK key            (0x91)"},
{L"0x92", L"OEM specific               (0x92)"},
{L"0x92", L"OEM specific               (0x92)"},
{L"0x92", L"OEM specific               (0x92)"},
{L"0x92", L"OEM specific               (0x92)"},
{L"0x92", L"OEM specific               (0x92)"},
{L"0x93", L"Unassigned                 (0x93)"},
{L"0x94", L"Unassigned                 (0x94)"},
{L"0x95", L"Unassigned                 (0x95)"},
{L"0x96", L"Unassigned                 (0x96)"},
{L"0x97", L"Unassigned                 (0x97)"},
{L"0x98", L"Unassigned                 (0x98)"},
{L"0x99", L"Unassigned                 (0x99)"},
{L"0x9A", L"Unassigned                 (0x9A)"},
{L"0x9B", L"Unassigned                 (0x9B)"},
{L"0x9C", L"Unassigned                 (0x9C)"},
{L"0x9D", L"Unassigned                 (0x9D)"},
{L"0x9E", L"Unassigned                 (0x9E)"},
{L"0x9F", L"Unassigned                 (0x9F)"},
{L"0xA0", L"Left SHIFT key             (0xA0)"},
{L"0xA1", L"Right SHIFT key            (0xA1)"},
{L"0xA2", L"Left CONTROL key           (0xA2)"},
{L"0xA3", L"Right CONTROL key          (0xA3)"},
{L"0xA4", L"Left ALT key               (0xA4)"},
{L"0xA5", L"Right ALT key              (0xA5)"},
{L"0xA6", L"Browser Back key           (0xA6)"},
{L"0xA7", L"Browser Forward key        (0xA7)"},
{L"0xA8", L"Browser Refresh key        (0xA8)"},
{L"0xA9", L"Browser Stop key           (0xA9)"},
{L"0xAA", L"Browser Search key         (0xAA)"},
{L"0xAB", L"Browser Favorites key      (0xAB)"},
{L"0xAC", L"Browser Start and Home key (0xAC)"},
{L"0xAD", L"Volume Mute key            (0xAD)"},
{L"0xAE", L"Volume Down key            (0xAE)"},
{L"0xAF", L"Volume Up key              (0xAF)"},
{L"0xB0", L"Next Track key             (0xB0)"},
{L"0xB1", L"Previous Track key         (0xB1)"},
{L"0xB2", L"Stop Media key             (0xB2)"},
{L"0xB3", L"Play/Pause Media key       (0xB3)"},
{L"0xB4", L"Start Mail key             (0xB4)"},
{L"0xB5", L"Select Media key           (0xB5)"},
{L"0xB6", L"Start Application 1 key    (0xB6)"},
{L"0xB7", L"Start Application 2 key    (0xB7)"},
{L"0xB8", L"Reserved                   (0xB8)"},
{L"0xB9", L"Reserved                   (0xB9)"},
{L"0xBA", L";: key                     (0xBA)"},
{L"0xBB", L"+ key                      (0xBB)"},
{L"0xBC", L", key                      (0xBC)"},
{L"0xBD", L"- key                      (0xBD)"},
{L"0xBE", L". key                      (0xBE)"},
{L"0xBF", L"/? key                     (0xBF)"},
{L"0xC0", L"`~ key                     (0xC0)"},
{L"0xC1", L"Reserved                   (0xC1)"},
{L"0xC2", L"Reserved                   (0xC2)"},
{L"0xC3", L"Reserved                   (0xC3)"},
{L"0xC4", L"Reserved                   (0xC4)"},
{L"0xC5", L"Reserved                   (0xC5)"},
{L"0xC6", L"Reserved                   (0xC6)"},
{L"0xC7", L"Reserved                   (0xC7)"},
{L"0xC8", L"Reserved                   (0xC8)"},
{L"0xC9", L"Reserved                   (0xC9)"},
{L"0xCA", L"Reserved                   (0xCA)"},
{L"0xCB", L"Reserved                   (0xCB)"},
{L"0xCC", L"Reserved                   (0xCC)"},
{L"0xCD", L"Reserved                   (0xCD)"},
{L"0xCE", L"Reserved                   (0xCE)"},
{L"0xCF", L"Reserved                   (0xCF)"},
{L"0xD0", L"Reserved                   (0xD0)"},
{L"0xD1", L"Reserved                   (0xD1)"},
{L"0xD2", L"Reserved                   (0xD2)"},
{L"0xD3", L"Reserved                   (0xD3)"},
{L"0xD4", L"Reserved                   (0xD4)"},
{L"0xD5", L"Reserved                   (0xD5)"},
{L"0xD6", L"Reserved                   (0xD6)"},
{L"0xD7", L"Reserved                   (0xD7)"},
{L"0xD8", L"Reserved                   (0xD8)"},
{L"0xD9", L"Reserved                   (0xD9)"},
{L"0xDA", L"Reserved                   (0xDA)"},
{L"0xDB", L"[ key                      (0xDB)"},
{L"0xDC", L"| key                      (0xDC)"},
{L"0xDD", L"] key                      (0xDD)"},
{L"0xDE", L"' key                      (0xDE)"},
{L"0xDF", L"miscellaneous characters   (0xDF)"},
{L"0xE0", L"Reserved                   (0xE0)"},
{L"0xE1", L"OEM specific               (0xE1)"},
{L"0xE2", L"<> keys or | keys          (0xE2)"},
{L"0xE3", L"OEM specific               (0xE3)"},
{L"0xE4", L"OEM specific               (0xE4)"},
{L"0xE5", L"IME PROCESS key            (0xE5)"},
{L"0xE6", L"OEM specific               (0xE6)"},
{L"0xE7", L"The VK_PACKET key          (0xE7)"},
{L"0xE8", L"Unassigned                 (0xE8)"},
{L"0xE9", L"OEM specific               (0xE9)"},
{L"0xEA", L"OEM specific               (0xEA)"},
{L"0xEB", L"OEM specific               (0xEB)"},
{L"0xEC", L"OEM specific               (0xEC)"},
{L"0xED", L"OEM specific               (0xED)"},
{L"0xEE", L"OEM specific               (0xEE)"},
{L"0xEF", L"OEM specific               (0xEF)"},
{L"0xF0", L"OEM specific               (0xF0)"},
{L"0xF1", L"OEM specific               (0xF1)"},
{L"0xF2", L"OEM specific               (0xF2)"},
{L"0xF3", L"OEM specific               (0xF3)"},
{L"0xF4", L"OEM specific               (0xF4)"},
{L"0xF5", L"OEM specific               (0xF5)"},
{L"0xF6", L"Attn key                   (0xF6)"},
{L"0xF7", L"CrSel key                  (0xF7)"},
{L"0xF8", L"ExSel key                  (0xF8)"},
{L"0xF9", L"Erase EOF key              (0xF9)"},
{L"0xFA", L"Play key                   (0xFA)"},
{L"0xFB", L"Zoom key                   (0xFB)"},
{L"0xFC", L"Reserved                   (0xFC)"},
{L"0xFD", L"PA1 key                    (0xFD)"},
{L"0xFE", L"Clear key                  (0xFE)"},
};


// DialogKeys dialog

IMPLEMENT_DYNAMIC(DialogKeys, CDialog)

DialogKeys::DialogKeys(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_KEYS, pParent)
	, ValueKeysSelected(_T(""))
	, ValueStealFocus(FALSE)
{

}

DialogKeys::~DialogKeys()
{
}

void DialogKeys::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, ID_KEYS_SELECTED, ValueKeysSelected);
	DDX_Control(pDX, IDC_COMBO_KEYS, ControlKeys);
	DDX_Check(pDX, IDC_STEAL_FOCUS, ValueStealFocus);
}


BEGIN_MESSAGE_MAP(DialogKeys, CDialog)
	ON_BN_CLICKED(ID_APPLY_KEYS, &DialogKeys::OnClickedApplyKeys)
	ON_BN_CLICKED(IDC_ADD_KEY, &DialogKeys::OnClickedAddKey)
	ON_CBN_SELCHANGE(IDC_COMBO_KEYS, &DialogKeys::OnSelchangeComboKeys)
END_MESSAGE_MAP()


// DialogKeys message handlers


void DialogKeys::OnClickedApplyKeys()
{
	UpdateData(TRUE);
	if (lastKey != ControlKeys.GetCurSel()) {

		// For
		CString key(KeyCodes[ControlKeys.GetCurSel()][1]);
		for (int i = key.GetLength() - 1; i >= 0; i--) {
			if (key[i] == '(') {
				for (int j = i - 1; j >= 0; j--) {
					if (key[j] != ' ') {
						key = key.Mid(0, j + 1);
						break;
					}
				}
				break;
			}
		}

		if (MessageBox(CString("You selected '") + key + CString("' without adding it! Add that key before applying changes?"), L"Question!", MB_YESNO) == IDYES) {
			ValueKeysSelected = ValueKeysSelected + L" " + KeyCodes[ControlKeys.GetCurSel()][0];
			UpdateData(false);
			OnOK();
		}
		else if (!ValueKeysSelected.GetLength()) {
			MessageBoxA(NULL, "Must add at least one key!", "Warning!", MB_OK);
		}
		else {
			OnOK();
		}
	}
	else if (!ValueKeysSelected.GetLength()) {
		MessageBoxA(NULL, "Must add at least one key!", "Warning!", MB_OK);
	}
	else {
		OnOK();
	}
}


void DialogKeys::OnClickedAddKey()
{
	UpdateData(true);
	lastKey = ControlKeys.GetCurSel();
	if (ControlKeys.GetCurSel() > -1) {
		ValueKeysSelected = ValueKeysSelected + L" " + KeyCodes[ControlKeys.GetCurSel()][0];
		UpdateData(false);
	}
	else {
		MessageBoxA(NULL, "Please make a selection", "Info", MB_OK);
	}
}


BOOL DialogKeys::OnInitDialog()
{
	CDialog::OnInitDialog();
	for (int i = 0; i < KeyCodesLength; i++) {
		ControlKeys.AddString(KeyCodes[i][1]);
	}
	m_font.CreatePointFont(75, L"Courier New Bold");
	ControlKeys.SetFont(&m_font);
	ValueStealFocus = TRUE;
	UpdateData(FALSE);
	lastKey = -1;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void DialogKeys::OnSelchangeComboKeys()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}

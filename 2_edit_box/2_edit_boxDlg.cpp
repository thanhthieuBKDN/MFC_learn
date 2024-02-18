
// 2_edit_boxDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "2_edit_box.h"
#include "2_edit_boxDlg.h"
#include "afxdialogex.h"

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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy2editboxDlg dialog



CMy2editboxDlg::CMy2editboxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY2_EDIT_BOX_DIALOG, pParent)
	, _rad_sum(FALSE)
	, _edt_sub(FALSE)
	, _edt_mul(FALSE)
	, _edt_div(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2editboxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_VAL1, _edt_val_1);
	DDX_Control(pDX, IDC_EDIT_VAL2, _edt_val2);
	DDX_Control(pDX, IDC_EDIT_VAL3, _edt_val3);
	DDX_Control(pDX, IDC_BUTTON_CAL, _btn_cal);
	DDX_Radio(pDX, IDC_RADIO_SUM, _rad_sum);
	//DDX_Radio(pDX, IDC_SUB, _edt_sub);
	DDX_Radio(pDX, IDC_RADIO_MUL, _edt_mul);
	DDX_Radio(pDX, IDC_RADIO_DIV, _edt_div);
}

BEGIN_MESSAGE_MAP(CMy2editboxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CAL, &CMy2editboxDlg::OnBnClickedButtonCal)
END_MESSAGE_MAP()


// CMy2editboxDlg message handlers

BOOL CMy2editboxDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy2editboxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy2editboxDlg::OnPaint()
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
HCURSOR CMy2editboxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2editboxDlg::OnBnClickedButtonCal()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString str_val1 = _T("");
	CString str_val2 = _T("");
	CString str_val3 = _T("");
	_edt_val_1.GetWindowText(str_val1);
	_edt_val2.GetWindowText(str_val2);

	int val1 = _tstof(str_val1);
	int val2 = _tstof(str_val2);
	int ret = 0;
	if (_rad_sum == 1)
	{
		ret = val1 + val2;
	}
	CString strRetl;
	strRetl.Format(_T("%d"), ret);
	_edt_val3.SetWindowText(strRetl);
	UpdateData(FALSE);





}

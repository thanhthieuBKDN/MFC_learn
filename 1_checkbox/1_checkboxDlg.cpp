
// 1_checkboxDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "1_checkbox.h"
#include "1_checkboxDlg.h"
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
public:
	
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


// CMy1checkboxDlg dialog



CMy1checkboxDlg::CMy1checkboxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY1_CHECKBOX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1checkboxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_CPP, _cb_cpp);
	DDX_Control(pDX, IDC_CHECK_CSHAPE, cb_c_shape);
	DDX_Control(pDX, IDC_CHECK_JAVA, _cb_java);
}

BEGIN_MESSAGE_MAP(CMy1checkboxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMy1checkboxDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy1checkboxDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy1checkboxDlg::OnBnShow)
	ON_BN_CLICKED(IDC_CHECK_CPP, &CMy1checkboxDlg::OnBnClickedCheckCpp)
END_MESSAGE_MAP()


// CMy1checkboxDlg message handlers

BOOL CMy1checkboxDlg::OnInitDialog()
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

void CMy1checkboxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1checkboxDlg::OnPaint()
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
HCURSOR CMy1checkboxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMy1checkboxDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CMy1checkboxDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}


void CMy1checkboxDlg::OnBnShow()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int cpp = _cb_cpp.GetCheck();
	int cshape = cb_c_shape.GetCheck();	
	int cjava = _cb_java.GetCheck();

	CString str_cpp = _T("");
	CString str_sharp = _T("");
	CString str_java = _T("");

	if (cpp == 1) str_cpp = _T("CPP");
	if (cshape == 1) str_sharp = _T(" C Sharep");
	if (cjava == 1) str_java = _T("java");

	CString str_info = _T(" he can used: ");
	str_info += str_cpp + str_sharp + str_java;

	AfxMessageBox(str_info);
}


void CMy1checkboxDlg::OnBnClickedCheckCpp()
{
	// TODO: Add your control notification handler code here
	_cb_java.SetCheck(1);
	UpdateData(FALSE);

}

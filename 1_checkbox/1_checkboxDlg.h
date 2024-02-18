
// 1_checkboxDlg.h : header file
//

#pragma once


// CMy1checkboxDlg dialog
class CMy1checkboxDlg : public CDialogEx
{
// Construction
public:
	CMy1checkboxDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY1_CHECKBOX_DIALOG };
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
	CButton _cb_cpp;
	CButton cb_c_shape;
	CButton _cb_java;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnShow();
	afx_msg void OnBnClickedCheckCpp();
};

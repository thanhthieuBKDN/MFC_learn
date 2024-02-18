
// 2_edit_boxDlg.h : header file
//

#pragma once


// CMy2editboxDlg dialog
class CMy2editboxDlg : public CDialogEx
{
// Construction
public:
	CMy2editboxDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY2_EDIT_BOX_DIALOG };
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
	CEdit _edt_val_1;
protected:
	CEdit _edt_val2;
	CEdit _edt_val3;
	CButton _btn_cal;
public:
	BOOL _rad_sum;
	BOOL _edt_sub;
	BOOL _edt_mul;
	BOOL _edt_div;
	afx_msg void OnBnClickedButtonCal();
};

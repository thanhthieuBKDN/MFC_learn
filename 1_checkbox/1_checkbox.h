
// 1_checkbox.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy1checkboxApp:
// See 1_checkbox.cpp for the implementation of this class
//

class CMy1checkboxApp : public CWinApp
{
public:
	CMy1checkboxApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy1checkboxApp theApp;

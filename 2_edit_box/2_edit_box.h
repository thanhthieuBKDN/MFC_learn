
// 2_edit_box.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy2editboxApp:
// See 2_edit_box.cpp for the implementation of this class
//

class CMy2editboxApp : public CWinApp
{
public:
	CMy2editboxApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy2editboxApp theApp;

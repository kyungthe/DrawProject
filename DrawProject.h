
// DrawProject.h : DrawProject ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDrawProjectApp:
// �� Ŭ������ ������ ���ؼ��� DrawProject.cpp�� �����Ͻʽÿ�.
//

class CDrawProjectApp : public CWinApp
{
public:
	CDrawProjectApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawProjectApp theApp;


// XJH_Draw.h : XJH_Draw Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CXJH_DrawApp:
// �йش����ʵ�֣������ XJH_Draw.cpp
//

class CXJH_DrawApp : public CWinApp
{
public:
	CXJH_DrawApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CXJH_DrawApp theApp;

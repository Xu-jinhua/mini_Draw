// PolyHelpDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XJH_Draw.h"
#include "PolyHelpDialog.h"
#include "afxdialogex.h"


// PolyHelpDialog �Ի���

IMPLEMENT_DYNAMIC(PolyHelpDialog, CDialogEx)

PolyHelpDialog::PolyHelpDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_POLYHELPDIALOG, pParent)
{

}

PolyHelpDialog::~PolyHelpDialog()
{
}

void PolyHelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PolyHelpDialog, CDialogEx)
	ON_COMMAND(ID_32777, &PolyHelpDialog::On32777)
END_MESSAGE_MAP()


// PolyHelpDialog ��Ϣ�������


void PolyHelpDialog::On32777()
{
	// TODO: �ڴ���������������
}

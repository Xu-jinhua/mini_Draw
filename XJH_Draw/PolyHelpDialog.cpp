// PolyHelpDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "XJH_Draw.h"
#include "PolyHelpDialog.h"
#include "afxdialogex.h"


// PolyHelpDialog 对话框

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


// PolyHelpDialog 消息处理程序


void PolyHelpDialog::On32777()
{
	// TODO: 在此添加命令处理程序代码
}

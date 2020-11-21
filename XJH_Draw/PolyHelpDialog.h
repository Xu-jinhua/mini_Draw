#pragma once


// PolyHelpDialog 对话框

class PolyHelpDialog : public CDialogEx
{
	DECLARE_DYNAMIC(PolyHelpDialog)

public:
	PolyHelpDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PolyHelpDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POLYHELPDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32777();
};

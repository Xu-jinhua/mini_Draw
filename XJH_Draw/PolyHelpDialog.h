#pragma once


// PolyHelpDialog �Ի���

class PolyHelpDialog : public CDialogEx
{
	DECLARE_DYNAMIC(PolyHelpDialog)

public:
	PolyHelpDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PolyHelpDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POLYHELPDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32777();
};

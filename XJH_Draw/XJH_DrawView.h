
// XJH_DrawView.h : CXJH_DrawView ��Ľӿ�
//

#pragma once

#include <vector>
#include <algorithm>

#include "CFigure.h"
#include "CLine.h"
#include "CEllipse.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CPolyline.h"


using namespace std;

//��ȫɾ��
#define SAFEDELETE(p)  {if(p){delete p; p=NULL;}}

class CXJH_DrawView : public CView
{
protected: // �������л�����
	vector<CFigure *> m_FigArray;

	UINT		m_CurrentTool; //ͼ������

	CXJH_DrawView();
	DECLARE_DYNCREATE(CXJH_DrawView)

	// ����
public:
	CXJH_DrawDoc* GetDocument() const;

	// ����
public:

	// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// ʵ��
public:
	virtual ~CXJH_DrawView();

	///////////////////////////////////////////
private:
	int m_Dragging;
	CFigure *pFigure = NULL;
	CPoint m_PointOld;
	CPoint m_PointOrigin;
	CPoint m_PointFirst;	//����ͼ�еĵ�һ����
	CPoint m_PointLast;	//����ͼ������
	CPoint m_arrayP[255];	//�洢����ͼ�����е�
	int m_PolyCount = 0;		//���ߵĵ�ļ���



#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLine();
	afx_msg void OnCircle();
	afx_msg void OnEllipse();
	afx_msg void OnPolygon();
	afx_msg void OnRect();
	afx_msg void OnFreehand();
	afx_msg void OnPolygonHelp();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//	afx_msg void OnAfxIdsAppTitle();
};

#ifndef _DEBUG  // XJH_DrawView.cpp �еĵ��԰汾
inline CXJH_DrawDoc* CXJH_DrawView::GetDocument() const
{
	return reinterpret_cast<CXJH_DrawDoc*>(m_pDocument);
}
#endif


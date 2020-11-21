
// XJH_DrawView.h : CXJH_DrawView 类的接口
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

//安全删除
#define SAFEDELETE(p)  {if(p){delete p; p=NULL;}}

class CXJH_DrawView : public CView
{
protected: // 仅从序列化创建
	vector<CFigure *> m_FigArray;

	UINT		m_CurrentTool; //图形类型

	CXJH_DrawView();
	DECLARE_DYNCREATE(CXJH_DrawView)

	// 特性
public:
	CXJH_DrawDoc* GetDocument() const;

	// 操作
public:

	// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 实现
public:
	virtual ~CXJH_DrawView();

	///////////////////////////////////////////
private:
	int m_Dragging;
	CFigure *pFigure = NULL;
	CPoint m_PointOld;
	CPoint m_PointOrigin;
	CPoint m_PointFirst;	//折线图中的第一个点
	CPoint m_PointLast;	//折线图中最后点
	CPoint m_arrayP[255];	//存储折线图中所有点
	int m_PolyCount = 0;		//折线的点的计数



#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
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

#ifndef _DEBUG  // XJH_DrawView.cpp 中的调试版本
inline CXJH_DrawDoc* CXJH_DrawView::GetDocument() const
{
	return reinterpret_cast<CXJH_DrawDoc*>(m_pDocument);
}
#endif


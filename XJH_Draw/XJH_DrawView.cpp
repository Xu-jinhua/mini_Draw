
// XJH_DrawView.cpp : CXJH_DrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "XJH_Draw.h"
#endif

#include "XJH_DrawDoc.h"
#include "XJH_DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CXJH_DrawView

IMPLEMENT_DYNCREATE(CXJH_DrawView, CView)

BEGIN_MESSAGE_MAP(CXJH_DrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CXJH_DrawView::OnLine)
	ON_COMMAND(ID_32772, &CXJH_DrawView::OnCircle)
	ON_COMMAND(ID_32773, &CXJH_DrawView::OnEllipse)
	ON_COMMAND(ID_32774, &CXJH_DrawView::OnPolygon)
	ON_COMMAND(ID_32775, &CXJH_DrawView::OnRect)
	ON_COMMAND(ID_32776, &CXJH_DrawView::OnFreehand)
	ON_COMMAND(ID_32777, &CXJH_DrawView::OnPolygonHelp)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//	ON_WM_CONTEXTMENU()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	//	ON_COMMAND(AFX_IDS_APP_TITLE, &CXJH_DrawView::OnAfxIdsAppTitle)
END_MESSAGE_MAP()

// CXJH_DrawView 构造/析构

CXJH_DrawView::CXJH_DrawView()
{
	// TODO: 在此处添加构造代码
	m_Dragging = 0;
	m_CurrentTool = 1;

}

CXJH_DrawView::~CXJH_DrawView()
{
	for (int i = 0; i < m_FigArray.size(); i++)
	{
		SAFEDELETE(m_FigArray.at(i));
	}
}

BOOL CXJH_DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CXJH_DrawView 绘制

void CXJH_DrawView::OnDraw(CDC* pDC)
{
	CXJH_DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < m_FigArray.size(); i++)
	{
		m_FigArray.at(i)->Draw(pDC);
	}
}


// CXJH_DrawView 打印

BOOL CXJH_DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CXJH_DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CXJH_DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CXJH_DrawView 诊断

#ifdef _DEBUG
void CXJH_DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CXJH_DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CXJH_DrawDoc* CXJH_DrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXJH_DrawDoc)));
	return (CXJH_DrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CXJH_DrawView 消息处理程序



void CXJH_DrawView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	m_CurrentTool = 1;
}


void CXJH_DrawView::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	m_CurrentTool = 2;
}


void CXJH_DrawView::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_CurrentTool = 3;
}


void CXJH_DrawView::OnPolygon()
{
	// TODO: 在此添加命令处理程序代码
	m_CurrentTool = 4;
}


void CXJH_DrawView::OnRect()
{
	// TODO: 在此添加命令处理程序代码
	m_CurrentTool = 5;
}


void CXJH_DrawView::OnFreehand()
{
	// TODO: 在此添加命令处理程序代码
	m_CurrentTool = 6;
}

void CXJH_DrawView::OnPolygonHelp()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(NULL, TEXT("左键点击绘制多边形，右键点击闭合多边形"));
}


void CXJH_DrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_PointOrigin = point;
	m_PointOld = point;
	m_Dragging = 1;

	//多边形第一个点初始化
	if (m_PolyCount == 0)
	{
		m_PointFirst = point;
		m_arrayP[m_PolyCount++] = point;
	}
	//图形数组
	CFigure *pFigure = NULL;
	pFigure = new CLine(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
	m_FigArray.push_back(pFigure);

	CView::OnLButtonDown(nFlags, point);
}


void CXJH_DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
	if (!m_Dragging)
		return;

	CClientDC ClientDC(this);
	ClientDC.SelectStockObject(NULL_BRUSH);

	CFigure *pFigure = NULL;

	//鼠标抬起时不同按钮的不同功能
	switch (m_CurrentTool)
	{
	case 1:
		ClientDC.SetROP2(R2_NOT);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(m_PointOld);
		pFigure = new CLine(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
	case 3:
		ClientDC.SetROP2(R2_NOT);
		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		pFigure = new CEllipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
	case 5:
		ClientDC.SetROP2(R2_NOT);
		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		pFigure = new CRectangle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
	case 4:
		//MessageBox(NULL, TEXT("左键点击绘制多边形，右键点击闭合多边形"));
		m_arrayP[m_PolyCount++] = point;
		m_PointLast = point;
		pFigure = new CPolyline(m_arrayP, m_PolyCount);
		if (m_PolyCount > 1)	//点超过1个时，画折线
		{
			ClientDC.Polyline(m_arrayP, m_PolyCount);
			pFigure = new CPolyline(m_arrayP, m_PolyCount);
		}
		break;
	case 6:
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(point);
		pFigure = new CLine(m_PointOrigin.x, m_PointOrigin.y,
			point.x, point.y);
		break;
	case 2:
		//		ClientDC.SetROP2(R2_NOT);
		//		radius = sqrt((m_Y2 - m_Y1) * (m_Y2 - m_Y1) + (m_X2 - m_X1) * (m_X2 - m_X1)) / 2;
		//		center.x = (m_X1 + m_X2) / 2;
		//		center.y = (m_Y1 + m_Y2) / 2;
		//		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		pFigure = new CCircle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
	}

	ClientDC.SetROP2(R2_COPYPEN);
	pFigure->Draw(&ClientDC);

	m_FigArray.push_back(pFigure);
	m_Dragging = 0;

}


//void CXJH_DrawView::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
//{
//	// TODO: 在此处添加消息处理程序代码
//}


void CXJH_DrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!m_Dragging)
		return;

	CClientDC ClientDC(this);
	ClientDC.SelectStockObject(NULL_BRUSH);

	//鼠标移动时不同按钮的不同功能
	switch (m_CurrentTool)
	{
	case 1:			//画直线
		ClientDC.SetROP2(R2_NOT);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(m_PointOld);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(point);
		break;
	case 3:			//画椭圆
		ClientDC.SetROP2(R2_NOT);
		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
	case 5:			//画矩形
		ClientDC.SetROP2(R2_NOT);
		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
	case 4:			//画多边形
		if (m_PolyCount != 0)
		{
			ClientDC.SetROP2(R2_NOT);
			ClientDC.MoveTo(m_PointLast);
			ClientDC.LineTo(point);
			ClientDC.MoveTo(m_PointLast);
			ClientDC.LineTo(point);		//绘制当前的临时线
		}
		else
		{
			ClientDC.SetROP2(R2_NOT);
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(m_PointOld);		//擦去上一次的线
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(point);		//绘制当前的临时线
		}
		m_PointOld = point;
		break;
	case 6:			//画自由曲线
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(point);
		m_PointOrigin = point;
		break;
	case 2:			//画圆
//		ClientDC.SetROP2(R2_NOT);
//		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
//		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		ClientDC.SetROP2(R2_NOT);
		//勿动,危
		//		pFigure = new CCircle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		CPoint center;	//圆心
		int radius;	//半径
		radius = sqrt((m_PointOld.x - m_PointOrigin.x) * (m_PointOld.x - m_PointOrigin.x) + (m_PointOld.y - m_PointOrigin.y) * (m_PointOld.y - m_PointOrigin.y)) / 2;
		center.x = (m_PointOrigin.x + m_PointOld.x) / 2;
		center.y = (m_PointOrigin.y + m_PointOld.y) / 2;
		ClientDC.Ellipse(center.x - radius, center.y - radius, center.x + radius, center.y + radius);

		radius = sqrt((point.x - m_PointOrigin.x) * (point.x - m_PointOrigin.x) + (point.y - m_PointOrigin.y) * (point.y - m_PointOrigin.y)) / 2;
		center.x = (m_PointOrigin.x + point.x) / 2;
		center.y = (m_PointOrigin.y + point.y) / 2;
		ClientDC.Ellipse(center.x - radius, center.y - radius, center.x + radius, center.y + radius);
		//		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
		break;
	}

	m_PointOld = point;
	CView::OnMouseMove(nFlags, point);
}

//按下右键
void CXJH_DrawView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC ClientDC(this);
	ClientDC.SelectStockObject(NULL_BRUSH);
	CPolyline *pFigure = NULL;

	//多边形的封口：按鼠标右键
	switch (m_CurrentTool)
	{
	case 4:
		if (m_PolyCount != 0)
		{
			m_arrayP[m_PolyCount++] = point;
			ClientDC.Polygon(m_arrayP, m_PolyCount);
			pFigure = new CPolyline(m_arrayP, m_PolyCount);
			m_PolyCount = 0;
		}
		break;
	}
	CView::OnRButtonDown(nFlags, point);
}


void CXJH_DrawView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonUp(nFlags, point);
}


//void CXJH_DrawView::OnAfxIdsAppTitle()
//{
//	// TODO: 在此添加命令处理程序代码
//}

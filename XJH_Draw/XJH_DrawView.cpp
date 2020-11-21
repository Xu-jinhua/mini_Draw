
// XJH_DrawView.cpp : CXJH_DrawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CXJH_DrawView ����/����

CXJH_DrawView::CXJH_DrawView()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CXJH_DrawView ����

void CXJH_DrawView::OnDraw(CDC* pDC)
{
	CXJH_DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < m_FigArray.size(); i++)
	{
		m_FigArray.at(i)->Draw(pDC);
	}
}


// CXJH_DrawView ��ӡ

BOOL CXJH_DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CXJH_DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CXJH_DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CXJH_DrawView ���

#ifdef _DEBUG
void CXJH_DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CXJH_DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CXJH_DrawDoc* CXJH_DrawView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXJH_DrawDoc)));
	return (CXJH_DrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CXJH_DrawView ��Ϣ�������



void CXJH_DrawView::OnLine()
{
	// TODO: �ڴ���������������
	m_CurrentTool = 1;
}


void CXJH_DrawView::OnCircle()
{
	// TODO: �ڴ���������������
	m_CurrentTool = 2;
}


void CXJH_DrawView::OnEllipse()
{
	// TODO: �ڴ���������������
	m_CurrentTool = 3;
}


void CXJH_DrawView::OnPolygon()
{
	// TODO: �ڴ���������������
	m_CurrentTool = 4;
}


void CXJH_DrawView::OnRect()
{
	// TODO: �ڴ���������������
	m_CurrentTool = 5;
}


void CXJH_DrawView::OnFreehand()
{
	// TODO: �ڴ���������������
	m_CurrentTool = 6;
}

void CXJH_DrawView::OnPolygonHelp()
{
	// TODO: �ڴ���������������
	MessageBox(NULL, TEXT("���������ƶ���Σ��Ҽ�����պ϶����"));
}


void CXJH_DrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_PointOrigin = point;
	m_PointOld = point;
	m_Dragging = 1;

	//����ε�һ�����ʼ��
	if (m_PolyCount == 0)
	{
		m_PointFirst = point;
		m_arrayP[m_PolyCount++] = point;
	}
	//ͼ������
	CFigure *pFigure = NULL;
	pFigure = new CLine(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
	m_FigArray.push_back(pFigure);

	CView::OnLButtonDown(nFlags, point);
}


void CXJH_DrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonUp(nFlags, point);
	if (!m_Dragging)
		return;

	CClientDC ClientDC(this);
	ClientDC.SelectStockObject(NULL_BRUSH);

	CFigure *pFigure = NULL;

	//���̧��ʱ��ͬ��ť�Ĳ�ͬ����
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
		//MessageBox(NULL, TEXT("���������ƶ���Σ��Ҽ�����պ϶����"));
		m_arrayP[m_PolyCount++] = point;
		m_PointLast = point;
		pFigure = new CPolyline(m_arrayP, m_PolyCount);
		if (m_PolyCount > 1)	//�㳬��1��ʱ��������
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
//	// TODO: �ڴ˴������Ϣ����������
//}


void CXJH_DrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (!m_Dragging)
		return;

	CClientDC ClientDC(this);
	ClientDC.SelectStockObject(NULL_BRUSH);

	//����ƶ�ʱ��ͬ��ť�Ĳ�ͬ����
	switch (m_CurrentTool)
	{
	case 1:			//��ֱ��
		ClientDC.SetROP2(R2_NOT);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(m_PointOld);
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(point);
		break;
	case 3:			//����Բ
		ClientDC.SetROP2(R2_NOT);
		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
	case 5:			//������
		ClientDC.SetROP2(R2_NOT);
		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
		ClientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		break;
	case 4:			//�������
		if (m_PolyCount != 0)
		{
			ClientDC.SetROP2(R2_NOT);
			ClientDC.MoveTo(m_PointLast);
			ClientDC.LineTo(point);
			ClientDC.MoveTo(m_PointLast);
			ClientDC.LineTo(point);		//���Ƶ�ǰ����ʱ��
		}
		else
		{
			ClientDC.SetROP2(R2_NOT);
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(m_PointOld);		//��ȥ��һ�ε���
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(point);		//���Ƶ�ǰ����ʱ��
		}
		m_PointOld = point;
		break;
	case 6:			//����������
		ClientDC.MoveTo(m_PointOrigin);
		ClientDC.LineTo(point);
		m_PointOrigin = point;
		break;
	case 2:			//��Բ
//		ClientDC.SetROP2(R2_NOT);
//		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointOld.x, m_PointOld.y);
//		ClientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		ClientDC.SetROP2(R2_NOT);
		//��,Σ
		//		pFigure = new CCircle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		CPoint center;	//Բ��
		int radius;	//�뾶
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

//�����Ҽ�
void CXJH_DrawView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC ClientDC(this);
	ClientDC.SelectStockObject(NULL_BRUSH);
	CPolyline *pFigure = NULL;

	//����εķ�ڣ�������Ҽ�
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnRButtonUp(nFlags, point);
}


//void CXJH_DrawView::OnAfxIdsAppTitle()
//{
//	// TODO: �ڴ���������������
//}

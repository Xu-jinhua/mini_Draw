#pragma once
class CPolyline :public CFigure
{
public:
	int m_PolyCount;
	CPoint m_arrayP[255];

public:
	CPolyline(POINT* arrayP, int count)
	{
		m_PolyCount = count;
		for (int i = 0; i <= count; i++)
		{
			m_arrayP[i].x = arrayP[i].x;
			m_arrayP[i].y = arrayP[i].y;
		}
	}

	void Draw(CDC *pDC)
	{
		pDC->Polyline(m_arrayP, m_PolyCount);
	}
};

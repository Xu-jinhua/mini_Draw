#pragma once
class CCircle :public CFigure
{
private:
	int m_X1, m_Y1, m_X2, m_Y2;

public:
	CCircle(int X1, int Y1, int X2, int Y2)
	{
		m_X1 = X1;
		m_Y1 = Y1;
		m_X2 = X2;
		m_Y2 = Y2;
	}

	void Draw(CDC *pDC)
	{
		CPoint center;	//Ô²ÐÄ
		int radius;	//°ë¾¶
		radius = sqrt((m_Y2 - m_Y1) * (m_Y2 - m_Y1) + (m_X2 - m_X1) * (m_X2 - m_X1)) / 2;
		center.x = (m_X1 + m_X2) / 2;
		center.y = (m_Y1 + m_Y2) / 2;
		pDC->Ellipse(center.x - radius, center.y - radius, center.x + radius, center.y + radius);
		//		pDC->Ellipse(m_X1, m_Y1, m_X2, m_Y2);
	}

};
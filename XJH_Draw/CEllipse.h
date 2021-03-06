#pragma once
class CEllipse :public CFigure
{
private:
	int m_X1, m_Y1, m_X2, m_Y2;

public:
	CEllipse(int X1, int Y1, int X2, int Y2)
	{
		m_X1 = X1;
		m_Y1 = Y1;
		m_X2 = X2;
		m_Y2 = Y2;
	}

	void Draw(CDC *pDC)
	{
		pDC->Ellipse(m_X1, m_Y1, m_X2, m_Y2);
	}
};
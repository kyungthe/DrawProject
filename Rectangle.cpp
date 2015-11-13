#include "stdafx.h"
#include "Rectangle.h"

IMPLEMENT_SERIAL(CRectangle, CFigure, 1)

CRectangle::CRectangle(CPoint& p1, CPoint& p2) :
leftTop(p1, 0), midTop(p1, 0), rightTop(p1, 0), leftMid(p1, 0), rightMid(p1, 0), leftBottom(p1, 0), midBottom(p1, 0), rightBottom(p1, 0)
{
	SetGeometry(p1, p2);
}

void CRectangle::Draw(CDC* pDC)
{
	pDC->Rectangle(m_rect);
	ReSizeRectDraw(pDC);
}

void CRectangle::ReSizeRectDraw(CDC* pDC)
{
	leftTop.Draw(pDC);
	midTop.Draw(pDC);
	rightTop.Draw(pDC);

	leftMid.Draw(pDC);
	rightMid.Draw(pDC);

	leftBottom.Draw(pDC);
	midBottom.Draw(pDC);
	rightBottom.Draw(pDC);
}

void CRectangle::ReSize(CPoint point)
{
	if (point.x > m_rect.right)
		m_rect.right = point.x;
	else if (point.x < m_rect.left)
		m_rect.left = point.x;
	else if (point.x - m_rect.left > m_rect.right - point.x)
		m_rect.right = point.x;
	else
		m_rect.left = point.x;

	if (point.y > m_rect.bottom)
		m_rect.bottom = point.y;
	else if (point.y < m_rect.top)
		m_rect.top = point.y;
	else if (point.y - m_rect.top > m_rect.bottom - point.y)
		m_rect.bottom = point.y;
	else
		m_rect.top = point.y;

	leftTop.SetPosition(m_rect.TopLeft(), 5);
	midTop.SetPosition(CPoint((m_rect.right + m_rect.left) / 2, m_rect.top), 5);
	rightTop.SetPosition(CPoint(m_rect.right, m_rect.top), 5);

	leftMid.SetPosition(CPoint(m_rect.left, (m_rect.bottom + m_rect.top) / 2), 5);
	rightMid.SetPosition(CPoint(m_rect.right, (m_rect.bottom + m_rect.top) / 2), 5);

	leftBottom.SetPosition(CPoint(m_rect.left, m_rect.bottom), 5);
	midBottom.SetPosition(CPoint((m_rect.right + m_rect.left) / 2, m_rect.bottom), 5);
	rightBottom.SetPosition(m_rect.BottomRight(), 5);
}

void CRectangle::Move(CPoint& pre, CPoint& current)
{
	int move_x = current.x - pre.x;
	int move_y = current.y - pre.y;

	m_rect.OffsetRect(move_x, move_y);

	leftTop.Move(pre, current);
	midTop.Move(pre, current);
	rightTop.Move(pre, current);

	leftMid.Move(pre, current);
	rightMid.Move(pre, current);

	leftBottom.Move(pre, current);
	midBottom.Move(pre, current);
	rightBottom.Move(pre, current);
}

void CRectangle::SetGeometry(CPoint& p1, CPoint& p2)
{
	m_rect.left		= min(p1.x, p2.x);
	m_rect.top		= min(p1.y, p2.y);
	m_rect.right	= max(p1.x, p2.x);
	m_rect.bottom	= max(p1.y, p2.y);
}

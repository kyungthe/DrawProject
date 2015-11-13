#include "stdafx.h"
#include "Rectangle.h"

IMPLEMENT_SERIAL(CRectangle, CFigure, 1)

CRectangle::CRectangle(CPoint p1, CPoint p2) 
{
	SetGeometry(p1, p2);
}

void CRectangle::Draw(CDC* pDC)
{
	pDC->Rectangle(m_rect);
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
	CClientDC dc(AfxGetApp()->m_pActiveWnd);
	CString str;

	if (point.x >= m_rect.left && point.y >= m_rect.top) {
		m_rect.BottomRight() = point;
		str.Format(L"1번 left %d top %d right %d bottom %d", m_rect.left, m_rect.top, m_rect.right, m_rect.bottom);
		dc.TextOutW(100, 100, str);
	}
	else if (point.x >= m_rect.left && point.y < m_rect.top) {
		m_rect.right = point.x;
		m_rect.top = point.y;
		str.Format(L"22번 left %d top %d right %d bottom %d", m_rect.left, m_rect.top, m_rect.right, m_rect.bottom);
		dc.TextOutW(100, 100, str);
	}
	else if (point.x < m_rect.right && point.y >= m_rect.top) {
		m_rect.left = point.x;
		m_rect.bottom = point.y;
		str.Format(L"333번 left %d top %d right %d bottom %d", m_rect.left, m_rect.top, m_rect.right, m_rect.bottom);
		dc.TextOutW(100, 100, str);
	}
	else if (point.x < m_rect.left && point.y < m_rect.top) {
		m_rect.TopLeft() = point;
		str.Format(L"4444번 left %d top %d right %d bottom %d", m_rect.left, m_rect.top, m_rect.right, m_rect.bottom);
		dc.TextOutW(100, 100, str);
	}
}

void CRectangle::Move(CPoint pre, CPoint current)
{
	int move_x = current.x - pre.x;
	int move_y = current.y - pre.y;

	m_rect.MoveToXY(m_rect.left + move_x, m_rect.top + move_y);
}

void CRectangle::SetGeometry(CPoint p1, CPoint p2)
{
	m_rect.left		= min(p1.x, p2.x);
	m_rect.top		= min(p1.y, p2.y);
	m_rect.right	= max(p1.x, p2.x);
	m_rect.bottom	= max(p1.y, p2.y);
}

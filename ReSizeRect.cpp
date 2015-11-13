#include "stdafx.h"
#include "ReSizeRect.h"

CReSizeRect::CReSizeRect(CPoint center, int size)
{
	left	= center.x - size;
	top		= center.y - size;
	right	= center.x + size;
	bottom	= center.y + size;
}

void CReSizeRect::SetPosition(CPoint& center, int size)
{
	left	= center.x - size;
	top		= center.y - size;
	right	= center.x + size;
	bottom	= center.y + size;
}

void CReSizeRect::Draw(CDC* pDC)
{
	pDC->Rectangle(this);
}

void CReSizeRect::Move(CPoint& pre, CPoint& current)
{
	int move_x = current.x - pre.x;
	int move_y = current.y - pre.y;

	OffsetRect(move_x, move_y);
}
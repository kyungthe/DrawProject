#pragma once

#include "Figure.h"

class CRectangle : public CFigure
{
public:
	CRectangle() {}
	CRectangle(CPoint& p1, CPoint& p2);
	virtual BOOL PtInObject(CPoint point) {
		return m_rect.PtInRect(point);
	}
	virtual void Draw(CDC* pDC);
	virtual void ReSizeRectDraw(CDC* pDC);
	virtual CRect BoundRect() { return m_rect; }
	virtual void SetGeometry(CPoint& p1, CPoint& p2);
	CRectangle* Clone() { return new CRectangle(*this); }
	virtual void ReSize(CPoint point);
	virtual void Move(CPoint& pre, CPoint& current);

private:
	DECLARE_SERIAL(CRectangle)
	CRect m_rect;

	CReSizeRect leftTop;
	CReSizeRect midTop;
	CReSizeRect rightTop;

	CReSizeRect leftMid;
	CReSizeRect rightMid;

	CReSizeRect leftBottom;
	CReSizeRect midBottom;
	CReSizeRect rightBottom;
};


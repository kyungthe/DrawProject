#pragma once

#include "afx.h"
#include "ReSizeRect.h"

class CFigure : public CObject
{
public:
	CFigure() {}
	CFigure(const CFigure& fig) { *this = fig; }
	CFigure& operator=(const CFigure& fig) { *this = fig; }
	virtual ~CFigure() { };

	virtual void Draw(CDC* pDC) = 0;
	virtual void ReSizeRectDraw(CDC* pDC) = 0;
	virtual BOOL PtInObject(CPoint point) = 0;
	virtual CRect BoundRect() = 0;
	virtual void SetGeometry(CPoint& p1, CPoint& p2) = 0;
	virtual void ReSize(CPoint point) = 0;
	virtual void Move(CPoint& pre, CPoint& current) = 0;
protected:
	DECLARE_DYNAMIC(CFigure)
};


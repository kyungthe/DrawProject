#pragma once

#include "atltypes.h"

class CReSizeRect :
	public CRect
{
public:
	CReSizeRect() {};
	CReSizeRect(CPoint center, int size);
	//CReSizeRect(const CReSizeRect& resize) { *this = resize; }
	//CReSizeRect& operator=(const CReSizeRect& resize) { return *this = resize; }

	void Draw(CDC* pDC);
	void Move(CPoint& pre, CPoint& current);
	void SetPosition(CPoint& center, int size);
};
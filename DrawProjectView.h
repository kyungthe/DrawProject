
// DrawProjectView.h : CDrawProjectView Ŭ������ �������̽�
//

#pragma once
#include "Rectangle.h"

class CDrawProjectView : public CView
{
private:
	CFigure* m_r = NULL;
	CPoint m_prePoint, m_curtPoint;
	bool m_isDrag = 0;
	bool m_isMove = 0;
protected: // serialization������ ��������ϴ�.
	CDrawProjectView();
	DECLARE_DYNCREATE(CDrawProjectView)

// Ư���Դϴ�.
public:
	CDrawProjectDoc* GetDocument() const;
	
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CDrawProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawProjectView.cpp�� ����� ����
inline CDrawProjectDoc* CDrawProjectView::GetDocument() const
   { return reinterpret_cast<CDrawProjectDoc*>(m_pDocument); }
#endif


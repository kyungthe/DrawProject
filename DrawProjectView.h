
// DrawProjectView.h : CDrawProjectView 클래스의 인터페이스
//

#pragma once
#include "Rectangle.h"

class CDrawProjectView : public CView
{
private:
	CTypedPtrArray<CObArray, CFigure*> m_figures;

	CFigure* m_r;
	CPoint m_prePoint, m_curtPoint;
	bool m_isMake;
	bool m_isMove;

// CTypedPtrArray 메소드
public:
	void   AddFigure(CFigure* figure);
	int    GetFigureCount() { return m_figures.GetCount(); }
	CFigure* GetFigure(int index) { return m_figures[index]; }
	void   DeleteAllFigures();

protected: // serialization에서만 만들어집니다.
	CDrawProjectView();
	DECLARE_DYNCREATE(CDrawProjectView)

// 특성입니다.
public:
	CDrawProjectDoc* GetDocument() const;
	
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CDrawProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // DrawProjectView.cpp의 디버그 버전
inline CDrawProjectDoc* CDrawProjectView::GetDocument() const
   { return reinterpret_cast<CDrawProjectDoc*>(m_pDocument); }
#endif


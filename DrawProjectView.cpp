
// DrawProjectView.cpp : CDrawProjectView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "DrawProject.h"
#endif

#include "DrawProjectDoc.h"
#include "DrawProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawProjectView

IMPLEMENT_DYNCREATE(CDrawProjectView, CView)

BEGIN_MESSAGE_MAP(CDrawProjectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawProjectView 생성/소멸

CDrawProjectView::CDrawProjectView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDrawProjectView::~CDrawProjectView()
{
}

BOOL CDrawProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDrawProjectView 그리기

void CDrawProjectView::OnDraw(CDC* pDC)
{
	CDrawProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	if(m_r != NULL) m_r->Draw(pDC);
}


// CDrawProjectView 인쇄

BOOL CDrawProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDrawProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDrawProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CDrawProjectView 진단

#ifdef _DEBUG
void CDrawProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawProjectDoc* CDrawProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawProjectDoc)));
	return (CDrawProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawProjectView 메시지 처리기


void CDrawProjectView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_r != NULL && m_r->PtInObject(point)) {
		m_isMove = true;
		m_prePoint = point;
	}
	else {
		m_isMake = true;
		m_r = new CRectangle(point, point);
	}

	CView::OnLButtonDown(nFlags, point);
}


void CDrawProjectView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_isMake) {
		m_isMake = false;
	}

	if (m_isMove) m_isMove = false;

	CView::OnLButtonUp(nFlags, point);
}


void CDrawProjectView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_isMake) {
		m_r->ReSize(point);
		Invalidate();
	}

	if (m_isMove) {
		m_curtPoint = point;
		m_r->Move(m_prePoint, m_curtPoint);
		m_prePoint = m_curtPoint;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}

void CDrawProjectView::AddFigure(CFigure* figure)
{
	m_figures.Add(figure);
}

void CDrawProjectView::DeleteAllFigures() {
	for (int i = 0; i < m_figures.GetSize(); ++i)
		delete m_figures[i];
	m_figures.RemoveAll();
}

void CDrawProjectView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_r = NULL;
	m_prePoint = m_curtPoint = CPoint(0, 0);
	m_isMake = 0;
	m_isMove = 0;
}


// DrawProjectView.cpp : CDrawProjectView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawProjectView ����/�Ҹ�

CDrawProjectView::CDrawProjectView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CDrawProjectView::~CDrawProjectView()
{
}

BOOL CDrawProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CDrawProjectView �׸���

void CDrawProjectView::OnDraw(CDC* pDC)
{
	CDrawProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	if(m_r != NULL) m_r->Draw(pDC);
}


// CDrawProjectView �μ�

BOOL CDrawProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CDrawProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CDrawProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CDrawProjectView ����

#ifdef _DEBUG
void CDrawProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawProjectDoc* CDrawProjectView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawProjectDoc)));
	return (CDrawProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawProjectView �޽��� ó����


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

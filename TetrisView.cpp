
// TetrisView.cpp : implementation of the CTetrisView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Tetris.h"
#endif

#include "TetrisDoc.h"
#include "TetrisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTetrisView

IMPLEMENT_DYNCREATE(CTetrisView, CView)

BEGIN_MESSAGE_MAP(CTetrisView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CTetrisView construction/destruction

CTetrisView::CTetrisView() noexcept
{
	// TODO: add construction code here
	//hcnmau = CHcnmau(50, 50, 100, 100,0,255,0);
	banco = CBanCo();
	//hcn = CHcn(500, 500, 800, 800);
	kt = 0;
}

CTetrisView::~CTetrisView()
{
}

BOOL CTetrisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTetrisView drawing

void CTetrisView::OnDraw(CDC* /*pDC*/)
{
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	//CQuanCo* p = new CQuanCoV(50, 50);
	//p->Draw(&pdc, 0);
	CBanCo banco = CBanCo();
	banco.Draw(&pdc);
	//hcn.Draw(&pdc);
}

void CTetrisView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTetrisView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTetrisView diagnostics

#ifdef _DEBUG
void CTetrisView::AssertValid() const
{
	CView::AssertValid();
}

void CTetrisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTetrisDoc* CTetrisView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTetrisDoc)));
	return (CTetrisDoc*)m_pDocument;
}
#endif //_DEBUG


// CTetrisView message handlers
UINT tenrutgon(LPVOID pParam)
{
	CTetrisView* view = (CTetrisView*)pParam;
	view->playgame();

	return 1;
}

void CTetrisView::playgame()
{
	CClientDC pdc(this);
	banco.play(&pdc);
}
void CTetrisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC pdc(this);
	// TODO: Add your message handler code here and/or call default
	if (nChar == 32)
	{
		if (kt == 0)
		{
			banco.Start();
			CClientDC pdc(this);
			banco.Draw(&pdc);
			AfxBeginThread(tenrutgon, this);
			kt = 1;
		}
	}
	if (nChar == 37)
	{
		//banco.pc->GoLeft();
		banco.goLeft(&pdc);
	}
	if (nChar == 40)
	{
		banco.goDown(&pdc);
	}
	if (nChar == 39)
	{
		banco.goRight(&pdc);
	}
	if (nChar == 38)
	{
		banco.rotate(&pdc);
	}
	if (nChar == 86)
	{
		banco.DropInstantly(&pdc);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CTetrisView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CView::OnRButtonDown(nFlags, point);
}

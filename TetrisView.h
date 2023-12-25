
// TetrisView.h : interface of the CTetrisView class
//

#pragma once
#include"CQuanCo.h"
#include"CBanCo.h"
#include"CHcn.h"
//#include<thread>

class CTetrisView : public CView
{
protected: // create from serialization only
	CTetrisView() noexcept;
	DECLARE_DYNCREATE(CTetrisView)

// Attributes
public:
	CTetrisDoc* GetDocument() const;

// Operations
public:
	CHcn hcn;
	//CHcnmau hcnmau;
	CBanCo banco;
	int kt;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CTetrisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void playgame();
	void playmusic();
};

#ifndef _DEBUG  // debug version in TetrisView.cpp
inline CTetrisDoc* CTetrisView::GetDocument() const
   { return reinterpret_cast<CTetrisDoc*>(m_pDocument); }
#endif


#include "pch.h"
#include "CHcnmau.h"

CHcnmau::CHcnmau()
{

}

CHcnmau::CHcnmau(int x1, int y1, int x2, int y2, int r, int g,int b) : CHcn(x1, y1, x2, y2)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void CHcnmau::Draw(CClientDC* pdc)
{
	CPen pen(PS_SOLID, 2, RGB(1,1,1));
	CPen* Olpen = pdc->SelectObject(&pen);
	CBrush myBrush(RGB(r, g, b)); 
	CBrush* OldBrush = pdc->SelectObject(&myBrush);
	pdc->Rectangle(x1,y1,x2,y2);
	pdc->SelectObject(Olpen);
	pdc->SelectObject(OldBrush);
}

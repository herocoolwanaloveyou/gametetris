#include "pch.h"
#include "OCoMau.h"

OCoMau::OCoMau()
{
	gt = 0;
}

OCoMau::OCoMau(int x1, int y1, int x2, int y2, int r, int g, int b, int gt) : CHcnmau(x1,y1,x2,y2,r,g,b)
{
	this->gt = gt;
}

void OCoMau::Draw(CClientDC* pdc)
{
	if (gt == 1)
	{
		CPen pen(PS_SOLID, 2, RGB(1, 1, 1));
		CPen* Oldpen = pdc->SelectObject(&pen);
		CBrush MyBrush(RGB(r, g, b));
		CBrush* OldBrush = pdc->SelectObject(&MyBrush);
		pdc->Rectangle(x1, y1, x2, y2);
		pdc->SelectObject(Oldpen);
		pdc->SelectObject(OldBrush);
	}
}

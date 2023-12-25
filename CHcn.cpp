#include "pch.h"
#include "CHcn.h"

CHcn::CHcn()
{

}

CHcn::CHcn(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void CHcn::Draw(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}

void CHcn::thietlap(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

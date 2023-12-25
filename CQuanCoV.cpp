#include "pch.h"
#include "CQuanCoV.h"


CQuanCoV::CQuanCoV(int mx, int my)
{
	x = mx;
	y = my;
	oco[0] = CHcnmau(x, y, x + RONG, y + RONG, 255, 255, 0);
	oco[1] = CHcnmau(x, y + RONG, x + RONG, y + 2 * RONG, 255, 255, 0);
	oco[2] = CHcnmau(x + RONG, y, x + 2 * RONG, y + RONG, 255, 255, 0);
	oco[3] = CHcnmau(x + RONG, y + RONG, x + 2 * RONG, y + 2 * RONG, 255, 255, 0);
}

void CQuanCoV::thietlap(int x, int y)
{
	this->x = x;
	this->y = y;
	oco[0].thietlap(x, y, x + RONG, y + RONG);
	oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
	oco[2].thietlap(x + RONG, y, x + 2 * RONG, y + RONG);
	oco[3].thietlap(x + RONG, y + RONG, x + 2 * RONG, y + 2 * RONG);
}

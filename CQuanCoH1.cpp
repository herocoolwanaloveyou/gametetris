#include "pch.h"
#include "CQuanCoH1.h"


CQuanCoH1::CQuanCoH1(int mx, int my)
{
	x = mx;
	y = my;
	oco[0] = CHcnmau(x, y, x + RONG, y + RONG, 0, 255, 255);
	oco[1] = CHcnmau(x, y + RONG, x + RONG, y + 2 * RONG, 0, 255, 255);
	oco[2] = CHcnmau(x + RONG, y + RONG, x + 2 * RONG, y + 2 * RONG, 0, 255, 255);
	oco[3] = CHcnmau(x + RONG, y + 2 * RONG, x + 2 * RONG, y + 3 * RONG, 0, 255, 255);
	trangthai = 0;
}

void CQuanCoH1::thietlap(int x, int y)
{
	this->x = x;
	this->y = y;
	if (trangthai == 0)
	{
		oco[0].thietlap(x, y, x + RONG, y + RONG);
		oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
		oco[2].thietlap(x + RONG, y + RONG, x + 2 * RONG, y + 2 * RONG);
		oco[3].thietlap(x + RONG, y + 2 * RONG, x + 2 * RONG, y + 3 * RONG);
	}
	if (trangthai == 1)
	{
		oco[0].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
		oco[1].thietlap(x + RONG, y + RONG, x + 2 * RONG, y + 2 * RONG);
		oco[2].thietlap(x + RONG, y + 2 * RONG, x + 2 * RONG, y + 3 * RONG);
		oco[3].thietlap(x + 2 * RONG, y + 2 * RONG, x + 3 * RONG, y + 3 * RONG);
	}
}

void CQuanCoH1::doitrangthai()
{
	trangthai += 1;
	trangthai = trangthai % 2;
	thietlap(x, y);

}

void CQuanCoH1::vetrangthaicu()
{
	trangthai += 1;
	trangthai = trangthai % 2;
	thietlap(x, y);
}

void CQuanCoH1::rotate()
{
	doitrangthai();
	thietlap(x, y);
}
#include "pch.h"
#include "CQuanCoh2.h"


CQuanCoh2::CQuanCoh2(int mx, int my)
{
	x = mx;
	y = my;
	oco[0] = CHcnmau(x, y, x + RONG, y + RONG, 255, 153, 51);
	oco[1] = CHcnmau(x, y + RONG, x + RONG, y + 2 * RONG, 255, 153, 51);
	oco[2] = CHcnmau(x - RONG, y + RONG, x, y + 2 * RONG, 255, 153, 51);
	oco[3] = CHcnmau(x - RONG, y + 2 * RONG, x, y + 3 * RONG, 255, 153, 51);
	trangthai = 0;
}

void CQuanCoh2::thietlap(int x, int y)
{
	this->x = x;
	this->y = y;
	if (trangthai == 0)
	{
		oco[0].thietlap(x, y, x + RONG, y + RONG);
		oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
		oco[2].thietlap(x - RONG, y + RONG, x, y + 2 * RONG);
		oco[3].thietlap(x - RONG, y + 2 * RONG, x, y + 3 * RONG);
	}
	if (trangthai == 1)
	{
		oco[0].thietlap(x - RONG, y + RONG, x, y + 2 * RONG);
		oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
		oco[2].thietlap(x, y + 2 * RONG, x + RONG, y + 3 * RONG);
		oco[3].thietlap(x + RONG, y + 2 * RONG, x + 2 * RONG, y + 3 * RONG);
	}
}

void CQuanCoh2::doitrangthai()
{
	trangthai += 1;
	trangthai = trangthai % 2;
	thietlap(x, y);

}

void CQuanCoh2::vetrangthaicu()
{
	trangthai += 1;
	trangthai = trangthai % 2;
	thietlap(x, y);
}

void CQuanCoh2::rotate()
{
	doitrangthai();
	thietlap(x, y);
}

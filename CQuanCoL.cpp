#include "pch.h"
#include "CQuanCoL.h"

CQuanCoL::CQuanCoL()
{

}

CQuanCoL::CQuanCoL(int mx, int my)
{
	x = mx;
	y = my;
	oco[0] = CHcnmau(x, y, x + RONG, y + RONG, 51, 255, 51);
	oco[1] = CHcnmau(x, y + RONG, x + RONG, y + 2 * RONG, 51, 255, 51);
	oco[2] = CHcnmau(x, y + 2 * RONG, x + RONG, y + 3 * RONG, 51, 255, 51);
	oco[3] = CHcnmau(x + RONG, y + 2 * RONG, x + 2 * RONG, y + 3 * RONG, 51, 255, 51);
	trangthai = 0;
}

void CQuanCoL::thietlap(int x, int y)
{
	this->x = x;
	this->y = y;
	if (trangthai == 0)
	{
		oco[0].thietlap(x, y, x + RONG, y + RONG);
		oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
		oco[2].thietlap(x, y + 2 * RONG, x + RONG, y + 3 * RONG);
		oco[3].thietlap(x + RONG, y + 2 * RONG, x + 2 * RONG, y + 3 * RONG);
	}
	if (trangthai == 1)
	{
		oco[0].thietlap(x-RONG, y+RONG, x, y +2* RONG);
		oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
		oco[2].thietlap(x+RONG, y + RONG, x +2* RONG, y + 2* RONG);
		oco[3].thietlap(x + RONG, y, x + 2 * RONG, y +RONG);
	}
	if (trangthai == 2)
	{
		oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
		oco[0].thietlap(x, y +2*  RONG, x + RONG, y + 3 * RONG);
		oco[2].thietlap(x, y, x +RONG, y +RONG);
		oco[3].thietlap(x-RONG, y, x, y + RONG);
	}
	if (trangthai == 3) 
	{
		oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
		oco[0].thietlap(x+RONG, y + RONG, x +2* RONG, y + 2 * RONG);
		oco[2].thietlap(x-RONG, y+RONG, x, y +2* RONG);
		oco[3].thietlap(x - RONG, y+2*RONG, x, y +3* RONG);
	}
}

void CQuanCoL::doitrangthai()
{
	trangthai += 1;
	trangthai = trangthai % 4;
	thietlap(x, y);
}

void CQuanCoL::vetrangthaicu()
{
	trangthai += 3;
	trangthai = trangthai % 4;
	thietlap(x, y);
}

void CQuanCoL::rotate()
{
	doitrangthai();
	thietlap(x, y);
}

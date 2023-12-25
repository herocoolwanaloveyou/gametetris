#include "pch.h"
#include "CQuanCo.h"

CQuanCo::CQuanCo()
{
	x = 0;
	y = 0;
	trangthai = 0;
}

void CQuanCo::Draw(CClientDC* pdc, int value)
{
	for (int i = 0; i < 4; i++) 
	{
		if(oco[i].y2 > value)
		oco[i].Draw(pdc);
	}
}

void CQuanCo::GoDown()
{
	for (int i = 0; i < 4; i++)
	{
		oco[i].y1 += RONG;
		oco[i].y2 += RONG;
	}
	y += RONG;
}
void CQuanCo::GoUp()
{
	for (int i = 0; i < 4; i++)
	{
		oco[i].y1 -=RONG;
		oco[i].y2 -= RONG;
	}
	y -= RONG;
}

void CQuanCo::GoLeft()
{
	for (int i = 0; i < 4; i++)
	{
		oco[i].x1 -= RONG;
		oco[i].x2 -= RONG;
	}
	x -= RONG;
}

void CQuanCo::GoRight()
{
	for (int i = 0; i < 4; i++)
	{
		oco[i].x1 += RONG;
		oco[i].x2 += RONG;
	}
	x += RONG;
}




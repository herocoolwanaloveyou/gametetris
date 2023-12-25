#pragma once
class CHcn
{
public:
	int x1, x2, y1, y2;
	CHcn();
	CHcn(int x1, int y1, int x2, int y2);
	void Draw(CClientDC* pdc);
	void thietlap(int x1, int y1, int x2, int y2);
};


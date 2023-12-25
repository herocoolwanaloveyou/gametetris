#pragma once
#include"CHcnmau.h"
#include"OCoMau.h"
#define RONG 50
class CQuanCo
{
public:
	int x, y;
	int trangthai;
	CQuanCo();
	CHcnmau oco[4];
	virtual void Draw(CClientDC* pdc, int value);
	void GoDown();
	void GoUp();
	void GoLeft();
	void GoRight();
	virtual void thietlap(int x, int y){}
	virtual void doitrangthai(){}
	virtual void vetrangthaicu(){}
	virtual void rotate(){}
};


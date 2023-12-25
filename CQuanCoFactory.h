#pragma once
#include"CQuanCo.h"
#include"CQuanCoH1.h"
#include"CQuanCoh2.h"
#include"CQuanCoI.h"
#include"CQuanCoL.h"
#include"CQuanCoT.h"
#include"CQuanCoV.h"
class CQuanCoFactory
{
public:
	static CQuanCo* create_quanco(int x, int y)
	{
		int loai = 0;
		srand(time(0));
		loai = rand()%6;
		CQuanCo* p;
		//loai = 0;
		if (loai == 0) {
			p = new CQuanCoI(x, y);
			return p;
		}
		else if (loai == 1)
		{
			p = new CQuanCoV(x, y);
			return p;
		}
		else if (loai == 2)
		{
			p = new CQuanCoL(x, y);
			return p;
		}
		else if (loai == 3)
		{
			p = new CQuanCoT(x, y);
			return p;
		}
		else if (loai == 4)
		{
			p = new CQuanCoH1(x, y);
			return p;
		}
		else
		{
			p = new CQuanCoh2(x, y);
			return p;
		}
	}
};


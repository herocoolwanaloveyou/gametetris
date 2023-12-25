#pragma once
#include "CHcn.h"
class CHcnmau :
    public CHcn
{
public:
    int r, g, b;
    CHcnmau();
    CHcnmau(int x1, int y1, int x2, int y2, int r, int g, int b);
    void Draw(CClientDC* pdc);
};


#pragma once
#include "CHcnmau.h"
class OCoMau :
    public CHcnmau
{
public:
    int gt;
    OCoMau();
    OCoMau(int x1, int y1, int x2, int y2, int r, int g, int b,int gt);
    void Draw(CClientDC* pdc);
};
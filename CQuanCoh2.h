#pragma once
#include "CQuanCo.h"
class CQuanCoh2 :
    public CQuanCo
{
public:
    CQuanCoh2(int mx, int my);
    void thietlap(int x, int y);
    void doitrangthai();
    void vetrangthaicu();
    void rotate();
};


#pragma once
#include "CQuanCo.h"
class CQuanCoT :
    public CQuanCo
{
public:
    CQuanCoT();
    CQuanCoT(int mx, int my);
    void thietlap(int x, int y);
    void doitrangthai();
    void vetrangthaicu();
    void rotate();
};


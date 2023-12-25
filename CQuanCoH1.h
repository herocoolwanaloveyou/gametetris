#pragma once
#include "CQuanCo.h"
class CQuanCoH1 :
    public CQuanCo
{
public:
    CQuanCoH1(int mx, int my);
    void thietlap(int x, int y);
    void doitrangthai();
    void vetrangthaicu();
    void rotate();
};


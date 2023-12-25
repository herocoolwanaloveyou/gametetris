#pragma once
#include "CQuanCo.h"
class CQuanCoL :
    public CQuanCo
{
public:
    CQuanCoL();
    CQuanCoL(int mx, int my);
    void thietlap(int x, int y);
    void doitrangthai();
    void vetrangthaicu();
    void rotate();
};


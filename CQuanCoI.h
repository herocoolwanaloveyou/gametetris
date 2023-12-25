#pragma once
#include "CQuanCo.h"
#include"CHcnmau.h"
class CQuanCoI :
    public CQuanCo
{
public:
    CQuanCoI();
    CQuanCoI(int mx, int my);
    void thietlap(int x, int y);
    void doitrangthai();
    void vetrangthaicu();
    void rotate();
    void UndoRotation();
};


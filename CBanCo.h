#pragma once
#include"CQuanCo.h"
#include"OcoMau.h"
#include"CQuanCoFactory.h"
#include<mmsystem.h>
#include"CAudioPlayer.h"
#pragma comment(lib, "winmm.lib")
#
#define RONG 50
#define WIDTH 10
#define HEIGHT 16
struct toado { int i; int j; };
class CBanCo
{
public:
	int x, y;
	int control, level, diem,line;
	int lose;
	float speed;
	int speed2;

	OCoMau oco[HEIGHT][WIDTH];
	CQuanCo* pnext, * pc;
	void clear_banco(int mi);
	CBanCo();
	void Draw(CClientDC* pdc);
	void PlaySoundFromFile(LPCTSTR lpszFilePath);
	void Start();
	int kiemtra_dixuong();
	int kiemtra_quatrai();
	int kiemtra_quaphai();
	int kiemtra_xoay();
	bool kiemtra_thua();
	void play(CClientDC*pdc);
	void tangLV();
	void tangspeed();
	toado TimIJ(CHcnmau oco);
	void transfer_banco(CClientDC*pdc);
	void spawn_quanco();
	void goDown(CClientDC* pdc);
	void goLeft(CClientDC* pdc);
	void goRight(CClientDC* pdc);
	void rotate(CClientDC* pdc);
	SYSTEMTIME currentTime;
	void DropInstantly(CClientDC* pdc);
	void playmusic();
};


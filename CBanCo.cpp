#include "pch.h"
#include "CBanCo.h"

CBanCo::CBanCo()
{
	speed = 400;
	x = 550, y = 75;
	speed2 = 0;
	lose = 0;
	pc = nullptr;
	pnext = nullptr;
	CQuanCoFactory factory = CQuanCoFactory();
	pnext = factory.create_quanco(x + int(WIDTH * RONG) + 80, y+ 400);
	control = 0;
	level = 1;
	diem = 0;
	line = 0;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			oco[i][j] = OCoMau(x + j * RONG, y + i * RONG, x + (j + 1) * RONG, y + (i + 1) * RONG,255,0,0,0);
		} 
	}
}

void CBanCo::Draw(CClientDC* pdc)
{
	CPen pen();
	CPen pen2(PS_SOLID, 2, RGB(255, 255, 0));
	CPen* Olpen2 = pdc->SelectObject(&pen2);
	CBrush myBrush2(RGB(0, 128, 255));
	CBrush* OldBrush2 = pdc->SelectObject(&myBrush2);
	pdc->Rectangle(500,40 ,x + 775, y + 820);
	pdc->SelectObject(Olpen2);
	pdc->SelectObject(OldBrush2);



	pdc->Rectangle(x, y, x + RONG * WIDTH, y + RONG * HEIGHT);
	CBrush MyBrush(RGB(192, 192, 192));
	CBrush* OldBrush = pdc->SelectObject(&MyBrush);
	pdc->Rectangle(x, y, x+RONG*WIDTH, y+RONG*HEIGHT);
	pdc->SelectObject(OldBrush);
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			oco[i][j].Draw(pdc);
		}
	}



	CString strNext;
	strNext.Format(_T("NEXT"));
	CRect rectNext(1850, 200, WIDTH * RONG, 650);
	pdc->DrawText(strNext, rectNext, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	CString strLevel;
	strLevel.Format(_T("LEVEL: %d\n"), level);
	CRect rect1(1850, 150, WIDTH * RONG, 400);
	pdc->DrawText(strLevel, rect1, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	

	CString strSpeed;
	strSpeed.Format(_T("SPEED: %d\n"), speed2);
	CRect rectSpeed(1850, 380, WIDTH * RONG, 1000);
	pdc->DrawText(strSpeed, rectSpeed, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	strLevel.Format(_T("SORE: %d"), diem);
	CRect rect2(1850, 50, WIDTH * RONG, 170);
	pdc->DrawText(strLevel, rect2, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	strLevel.Format(_T("Line: %d\n"), line);
	CRect rect3(1850, 100, WIDTH * RONG, 250);
	pdc->DrawText(strLevel, rect3, DT_SINGLELINE | DT_CENTER | DT_VCENTER);



	CString tittle;
	tittle.Format(_T("NHÓM 5"));
	CRect tieude(1080, 20, WIDTH * RONG, 50);
	pdc->DrawText(tittle, tieude, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	CString tittle2;
	tittle2.Format(_T("CHÚC BẠN CHƠi GAME VUI VẺ ;))"));
	CRect tieude2(1080, 20, WIDTH * RONG, 100);
	pdc->DrawText(tittle2, tieude2 , DT_SINGLELINE | DT_CENTER | DT_VCENTER);


	// Lấy thời gian hệ thống
	GetLocalTime(&currentTime);
	// Hiển thị thời gian
	CString strTime;
	strTime.Format(_T("%02d:%02d"), currentTime.wHour, currentTime.wMinute, currentTime.wSecond);
	// Gán strTime vào một control hoặc làm gì đó khác với nó
	CRect recttime(1850, 500, WIDTH * RONG, 1000);
	pdc->DrawText(strTime, recttime, DT_SINGLELINE | DT_CENTER | DT_VCENTER);


	
	if (control == 0)
	{
		CString strStart;
		strStart.Format(_T("1.Bấm nút space để bắt đầu nha !"));
		CRect rect3(1100, 400, WIDTH * RONG, 500);
		pdc->DrawText(strStart, rect3, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		CString strV;
		strV.Format(_T("2.Bấm phím V để  quân cờ rơi xuống nhanh !"));
		CRect rect4(1100, 400, WIDTH * RONG, 560);
		pdc->DrawText(strV, rect4, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		playmusic();

	}

	
	if (pc != nullptr)
	{
		pc->Draw(pdc,y);
	}
	if (pnext != nullptr)
	{
		pnext->Draw(pdc,y);
	}



}


void  CBanCo::PlaySoundFromFile(LPCTSTR lpszFilePath)
{
	if (!AfxIsValidString(lpszFilePath) || !_taccess(lpszFilePath, 0))
	{
		// Phát âm thanh từ file .wav
		PlaySound(lpszFilePath, NULL, SND_FILENAME | SND_ASYNC);
	}
}


void CBanCo::Start()
{
	CQuanCoFactory factory = CQuanCoFactory();
	control = 1;
	level = 1;
	diem = 0;
	pc = factory.create_quanco(x + (WIDTH / 2) * RONG, y-4*RONG);
	
}


int CBanCo::kiemtra_dixuong()
{
	int kq = 0; // kq = 0 k di dc , 1  di dc
	int dem = 0;
	pc->GoDown();
		for (int i = 0; i < 4; i++)
		{
			if (pc->oco[i].y2 > y)
			{
				toado vitri = TimIJ(pc->oco[i]);
				if (vitri.i >= HEIGHT)
				{
					dem = 1;
					break;
				}
				else
				{
					dem += oco[vitri.i][vitri.j].gt;
				}
			}

		}
		if (dem > 0)
		{
			kq = 0;
		}
		else
		{
			kq = 1;
		}
	pc->GoUp();
	return kq;
}

int CBanCo::kiemtra_quatrai()
{
	int kq = 1;
	int i = 0;
	pc->GoLeft();
	while (i < 4 && kq == 1)
	{
		if (pc->oco[i].x1 < x)
			kq = 0;
		//kiem tra o co tren banco co bi chiem dong hay chua
		toado vitri = TimIJ(pc->oco[i]);
		if (vitri.i > 0 && oco[vitri.i][vitri.j].gt == 1)
			kq = 0;
		i++;
		if (kq == 0)
		{
			i++;
		}
	}
	pc->GoRight();
	return kq;
}

int CBanCo::kiemtra_quaphai()
{
	int x3 = x + WIDTH * RONG;
	pc->GoRight();
	int kq = 1;
	int i = 0;
	while (i < 4 && pc->oco[i].x2 <= x3 && kq ==1)
	{

		toado vitri = TimIJ(pc->oco[i]);
		if (vitri.j > WIDTH)
		{
			kq = 0;
		}
		else
		{
			if(oco[vitri.i][vitri.j].gt == 1)
				kq = 0;
		}
		i++;
	}
	if (i < 4)
	{
		kq = 0;
	}
	pc->GoLeft();
	return kq;
}

int CBanCo::kiemtra_xoay()
{
	pc->doitrangthai();
	int kq = 1;
	int x2 = x + WIDTH * RONG;
	int y2 = y + HEIGHT * RONG;
	int i = 0;
	while (i < 4 && kq == 1)
	{
		if (pc->oco[i].x1 < x || pc->oco[i].x2 > x2 || pc->oco[i].y2 > y2)
		{
			kq = 0;
		}
		//kiem tra oco bi chiem dong
		toado vitri = TimIJ(pc->oco[i]);
		if (oco[vitri.i][vitri.j].gt == 1)
		{
			kq = 0;
		}
		i++;
	}
	pc->vetrangthaicu();
	return kq;
}



bool CBanCo::kiemtra_thua()
{
	for (int j = 0; j < WIDTH; j++)
	{
			
		if (oco[0][j].gt == 1)
		{
			return true;
		}
	}
}

void CBanCo::play(CClientDC* pdc)
{
	int tam = 0;

	if (lose != 1) {
		do {
			while (kiemtra_dixuong())
			{

				if (diem < 40) {
					pc->GoDown();
					speed2 = 10;
					Draw(pdc); 
					Sleep(800);
				}
				else if (diem >= 40 && diem < 90)
				{
					pc->GoDown();
					Draw(pdc);
					Sleep(700);
					level = 2;
					speed2 = 20;
				}
				else if (diem >= 90 && diem < 130)
				{
					pc->GoDown();
					Draw(pdc);
					Sleep(300);
					level = 3;
					speed2=30;
				}
				else
				{
					pc->GoDown();
					Draw(pdc);
					Sleep(speed);
				}
			}
	
			if (kiemtra_thua()==true)
			{

				lose = 1;

			}
			if (lose == 1)
			{
				PlaySound(TEXT("lose sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
				CString strthua = _T("BAN DA THUA");
				CRect rect(1100, 400, WIDTH * RONG, 500);
				pdc->DrawText(strthua, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
				return;
			}
			transfer_banco(pdc);
			spawn_quanco();
			tam++;
			

		} while (kiemtra_dixuong());
		
		
	}
	
}

void CBanCo::tangLV(){
	if (diem >= 80 && diem % 80==0)
	{
		level += 1;
		tangspeed();
    }

}
void CBanCo::tangspeed()
{
	speed = speed - 100;
	speed2+=10;
}
toado CBanCo::TimIJ(CHcnmau oco)
{
	toado kq = toado();
	kq.j = (oco.x1 - x) / RONG;
	kq.i = (oco.y1 - y) / RONG;

	return kq;
}

void CBanCo :: clear_banco(int mi)
{
	int i = mi;
	int j = 0;
	while (i > 0)
	{
		for (j = 0; j < WIDTH; j++)
		{
			oco[i][j].gt = oco[i - 1][j].gt;
			oco[i][j].r = oco[i - 1][j].r;
			oco[i][j].g = oco[i - 1][j].g;
			oco[i][j].b = oco[i - 1][j].b;
		}
		i--;
	}
	for (j = 0; j < WIDTH; j++)
	{
		oco[0][j].gt = 0;
	}
}
void CBanCo::transfer_banco(CClientDC*pdc)
{
	for (int i = 0; i < 4; i++)
	{
		toado vitri = TimIJ(pc->oco[i]);
		oco[vitri.i][vitri.j].gt = 1;
		oco[vitri.i][vitri.j].r = pc->oco[i].r;
		oco[vitri.i][vitri.j].g = pc->oco[i].g;
		oco[vitri.i][vitri.j].b = pc->oco[i].b;
	}
	int i = HEIGHT - 1;
	int j = 0;
	int tong = 0;
	int dem = 0;
	while (i > 0)
	{
		tong = 0;
		for (j = 0; j < WIDTH; j++)
		{
			tong+=oco[i][j].gt;
		}
		if (tong == WIDTH)
		{
			diem += 10;
			clear_banco(i);
			PlaySound(TEXT("anbanco.wav"), NULL, SND_FILENAME | SND_ASYNC);
			tangLV();
			Draw(pdc);
			Sleep(300);
			line += 1;
			
			dem++;
		}
		else
		i--;
	}
	if (dem == 2)
	{
		diem += 20;
	}
	if (dem == 3)
	{
		diem += 30;
	}
	if (dem == 4)
	{
		diem += 60;
	}

}

void CBanCo::spawn_quanco()
{
	delete pc;
	pc = pnext;
	pc->thietlap(x + int(WIDTH / 2) * RONG - RONG, y - 4 * RONG);
	CQuanCoFactory factory = CQuanCoFactory();
	pnext = factory.create_quanco(x + int(WIDTH * RONG) + 80, y + 400);
}

void CBanCo::goDown(CClientDC* pdc)
{
	if (kiemtra_dixuong())
	{
		pc->GoDown();
		Draw(pdc);
	}
}

void CBanCo::goLeft(CClientDC* pdc)
{
	if (kiemtra_quatrai())
	{
		PlaySound(TEXT("clickmose.wav"), NULL, SND_FILENAME | SND_ASYNC);
		pc->GoLeft();
		Draw(pdc);

	}
}

void CBanCo::goRight(CClientDC* pdc)
{
	if (kiemtra_quaphai())
	{
		pc->GoRight();
		Draw(pdc);
		PlaySound(TEXT("clickmose.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}

void CBanCo::rotate(CClientDC* pdc)
{
	if (kiemtra_xoay())
	{
		pc->rotate();
		Draw(pdc);
		PlaySound(TEXT("clickmose.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}

void CBanCo::DropInstantly(CClientDC* pdc)
{
	while (kiemtra_dixuong())
	{
		pc->GoDown();
		Draw(pdc);
		Sleep(50);
	}
}

void CBanCo::playmusic()
{
	if (control == 0)
	{
		PlaySound(TEXT("nhacnen.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}

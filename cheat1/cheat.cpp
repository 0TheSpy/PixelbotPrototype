#pragma once

#include "main.h"

COLORREF rearrange(COLORREF val) {
	return
		(val & 0x00ff0000) >> CHAR_BIT * 2|
		(val & 0x0000ff00)|
		(val & 0x000000ff) << CHAR_BIT * 2;
}
 
void myDraw() {
	//SetLayeredWindowAttributes(hWnd, NULL, NULL, NULL);  
	//DwmEnableBlurBehindWindow(hWnd, &bb);  

	ID3DXFont* pFont;  
	D3DXCreateFont(p_Device, 20, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont);
	
	DrawString((char*)AY_OBFUSCATE("Spy CS Pixelbot mode (KEY PGUP): "), 5, 5, 255, 255, 255, 255, pFont);  

	DrawFilledRectangle(0, 0, Width, 1, D3DCOLOR_XRGB(255, 0, 0));
	DrawFilledRectangle(0, 0, 1, Height, D3DCOLOR_XRGB(255, 0, 0));
	DrawFilledRectangle(Width-1, 0, Width, Height, D3DCOLOR_XRGB(255, 0, 0));
	DrawFilledRectangle(0, Height-1, Width, Height, D3DCOLOR_XRGB(255, 0, 0));

	DrawFilledRectangle(scrCenterX - 1, scrCenterY - 1, scrCenterX, scrCenterY, D3DCOLOR_XRGB(255, 255, 255));
	DrawFilledRectangle(scrCenterX + 1, scrCenterY - 1, scrCenterX + 2, scrCenterY, D3DCOLOR_XRGB(255, 255, 255));
	DrawFilledRectangle(scrCenterX - 1, scrCenterY + 1, scrCenterX, scrCenterY + 2, D3DCOLOR_XRGB(255, 255, 255));
	DrawFilledRectangle(scrCenterX + 1, scrCenterY + 1, scrCenterX + 2, scrCenterY + 2, D3DCOLOR_XRGB(255, 255, 255));

	switch (mode){
	case 0:
		DrawString((char*)"DISABLED", 300, 5, 255, 255, 0, 0, pFont); 
		break;
	case 1:
		DrawString((char*)"AIMBOT", 300, 5, 255, 0, 255, 0, pFont);
		break;
	case 2:
		DrawString((char*)"TRIGGERBOT", 300, 5, 255, 0, 255, 0, pFont);
		break;
	}
	
	DrawString((char*)AY_OBFUSCATE("Your team (KEY HOME): "), 5, 25, 255, 255, 255, 0, pFont);  

	if (mineteam)
		DrawString((char*)AY_OBFUSCATE("CT"), 200, 25, 255, 0, 0, 255, pFont); 
	else 
		DrawString((char*)AY_OBFUSCATE("T"), 200, 25, 255, 255, 0, 0, pFont); 

	if (mode == 1) {
		DrawCircle(scrCenterX, scrCenterY, aimfov * 1, 0, 360, D3DCOLOR_ARGB(50, 255, 255, 0));  
		DrawString((char*)AY_OBFUSCATE("Aim smoothing (KEY UP/DOWN): "), 5, 45, 255, 255,255,255, pFont);  

		std::stringstream sstream1;
		sstream1  << aimsmooth;
		std::string result1 = sstream1.str();
		DrawString((char*)(result1.c_str()), 270, 45, 255, 0, 255, 0, pFont);  
	}

	if (mode == 2) { 
		D3DRECT rect = { 5, 45, 5 + 20, 45 + 20  };

		DrawFilledRectangle(5 - 2, 45 - 2, 5 + 22 + 55, 45 + 22, D3DCOLOR_XRGB(255, 255, 255));

		p_Device->Clear(1, &rect, D3DCLEAR_TARGET | D3DCLEAR_TARGET, pixel, 0, 0);
		 
		std::stringstream sstream;
		sstream << std::hex << pixel;
		std::string result = sstream.str();
		 
		DrawString((char*)(result.c_str()), 5 + 22, 45, 255, 255, 0, 0, pFont);  

		DrawString((char*)AY_OBFUSCATE("Shoot delay min (KEY UP/DOWN): "), 5, 65, 255, 255, 255, 255, pFont);  
		std::stringstream sstream3;
		sstream3 << tbdelaymin;
		std::string result3 = sstream3.str();
		DrawString((char*)(result3.c_str()), 280, 65, 255, 0, 255, 0, pFont);  

		DrawString((char*)AY_OBFUSCATE("Shoot delay max (KEY RIGHT/LEFT): "), 5, 85, 255, 255, 255, 255, pFont);  
		std::stringstream sstream4;
		sstream4 << tbdelaymax;
		std::string result4 = sstream4.str();
		DrawString((char*)(result4.c_str()), 300, 85, 255, 0, 255, 0, pFont);   

		DrawString((char*)AY_OBFUSCATE("Shoot delay between (KEY PLUS/MINUS): "), 5, 105, 255, 255, 255, 255, pFont);
		std::stringstream sstream5;
		sstream5 << tbdelaybetween;
		std::string result5 = sstream5.str();
		DrawString((char*)(result5.c_str()), 330, 105, 255, 0, 255, 0, pFont);

		
	}

#ifdef DEBUG
	std::stringstream sstream2;
	sstream2 << "SystemMetrics SM_CXSCREEN " << GetSystemMetrics(SM_CXSCREEN) << " SM_CYSCREEN " << GetSystemMetrics(SM_CYSCREEN);
	std::string result2 = sstream2.str();
	DrawString((char*)(result2.c_str()), 5, 130, 255, 0, 255, 0, pFont);  
	 
	std::stringstream sstream3;
	sstream3 << "WindowRect l " << tSize.left << " r " << tSize.right << " t " << tSize.top << " b " << tSize.bottom;
	std::string result3 = sstream3.str();
	DrawString((char*)(result3.c_str()), 5, 145, 255, 0, 255, 0, pFont);  

	std::stringstream sstream4;
	sstream4 << "ClientRect l " << ttSize.left << " r " << ttSize.right << " t " << ttSize.top << " b " << ttSize.bottom;
	std::string result4 = sstream4.str();
	DrawString((char*)(result4.c_str()), 5, 160, 255, 0, 255, 0, pFont);  

	std::stringstream sstream5;
	sstream5 << "SM_CYCAPTION " << GetSystemMetrics(SM_CYCAPTION) << " cyWindowBorders " << winfo.cyWindowBorders;
	std::string result5 = sstream5.str();
	DrawString((char*)(result5.c_str()), 5, 175, 255, 0, 255, 0, pFont);  
#endif

	pFont->Release();
}

class ScanContents
{
public:
	//values used to compare and decide exactly which quarter
	BITMAP Bm;
	RECT RcWindow;
	//our pixel array
	RGBQUAD* PPixels;
	//all the contents necessary to run our aimbot scanning thread
	ScanContents(BITMAP bm, RECT rcWindow, RGBQUAD* pPixels)
	{
		Bm = bm;
		RcWindow = rcWindow;
		PPixels = pPixels;
	}
}; 

bool TakeScreenshot(int szx = Width, int szy = Height)
{
	BITMAPINFO bmi;
	BITMAP bm; 
	RECT rc = { tSize.left + scrCenterX - szx / 2, tSize.top + scrCenterY - szy / 2 }; 
	HDC     hWindow = GetDC(NULL);
	HDC     hdcShot = CreateCompatibleDC(hWindow);
	HBITMAP hbmap = CreateCompatibleBitmap(hWindow, szx, szy); 
	HGDIOBJ old_obj = SelectObject(hdcShot, hbmap);
	BOOL    bRet = BitBlt(hdcShot, 0, 0, szx, szy, hWindow, tSize.left , tSize.top , SRCCOPY);
	 
	if (!GetObject(hbmap, sizeof(BITMAP), (LPSTR)&bm))
		return false;
	int bitsPerPixel = bm.bmBitsPixel;
	if (bitsPerPixel != 32 || bm.bmPlanes != 1)
		return false;
	
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = szx;
	bmi.bmiHeader.biHeight = szy;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = bitsPerPixel;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = 0;
 
	RGBQUAD* pPixels = new RGBQUAD[bm.bmWidth * bm.bmHeight];

	if (!GetDIBits(hdcShot, hbmap, 0, bm.bmHeight, pPixels, &bmi, DIB_RGB_COLORS))
	{
		DeleteDC(hdcShot);
		delete[] pPixels;
		return false;
	}
	 
	ScanContents scan(bm, rc, pPixels);
 
	for (int y = bm.bmHeight; y > 0; y -= 3)
	{
		for (int x = 0; x < bm.bmWidth; x += 3)
		{ 
			int p = (bm.bmHeight - y - 1) * bm.bmWidth + x; 

			if (mineteam) {
				if (pPixels[p].rgbRed > 220 && pPixels[p].rgbGreen > 220 && pPixels[p].rgbBlue < 25)
				{
					printfdbg("red found at %d, %d (%d,%d,%d)\n", x + scan.RcWindow.left, y + scan.RcWindow.top, pPixels[p].rgbRed, pPixels[p].rgbGreen, pPixels[p].rgbBlue);
					POINT point;
					GetCursorPos(&point); 
					deltax = (x + scan.RcWindow.left) - point.x;
					deltay = (y + scan.RcWindow.top) - point.y; 
					needaim = 1;
					break;
				}

			}
			else {
				if (pPixels[p].rgbRed < 25 && pPixels[p].rgbGreen > 210 && pPixels[p].rgbBlue > 210)
				{
					printfdbg("blu found at %d, %d (%d,%d,%d)\n", x + scan.RcWindow.left, y + scan.RcWindow.top, pPixels[p].rgbRed, pPixels[p].rgbGreen, pPixels[p].rgbBlue);
					POINT point;
					GetCursorPos(&point);
					deltax = (x + scan.RcWindow.left) - point.x;
					deltay = (y + scan.RcWindow.top) - point.y;
					needaim = 1;
					break;
				}
			}
			 
			if (GetAsyncKeyState(VK_DELETE))
			{
				_exit(0);
			}
		}
	}

	// clean up
	if (pPixels)free(pPixels);
	SelectObject(hdcShot, old_obj);
	DeleteDC(hdcShot);
	ReleaseDC(NULL, hWindow);
	DeleteObject(hbmap);

	return true;
} 
  
void Aim()
{
	int c1, c2, c3;
	while (1) {

		if (tWnd == GetForegroundWindow() && mode == 2) {

			c1 = pixel & 0x00FF0000; c2 = pixel & 0x0000FF00; c3 = pixel & 0x000000FF; 
			if (mineteam && c1 > 0xB00000 && c2 > 0xC000 && c3 < 0x24 ||
				!mineteam && c1 < 0x240000 && c2 > 0xC000 && c3 > 0xB0)
			{
				int DelayBefore = std::rand() % (tbdelaymax + 1 - tbdelaymin) + tbdelaymin;
				printfdbg("DelayBefore %d\n", DelayBefore);
				Sleep(DelayBefore);
				  
				while (true) {
					c1 = pixel & 0x00FF0000; c2 = pixel & 0x0000FF00; c3 = pixel & 0x000000FF;
					if (mineteam && c1 > 0xB00000 && c2 > 0xC000 && c3 < 0x24 ||
						!mineteam && c1 < 0x240000 && c2 > 0xC000 && c3 > 0xB0) //still need to shoot?
					{
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
						Sleep(10);
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
						int DelayBetween = std::rand() % tbdelaybetween_rand * 2 - tbdelaybetween_rand + tbdelaybetween;
						printfdbg("DelayBetween %d\n", DelayBetween);
						Sleep(DelayBetween);
					}
					else break;
				} 
			}
		}

		if (tWnd == GetForegroundWindow() && mode == 1 && GetAsyncKeyState(VK_LBUTTON) < 0 && needaim)
		{
			POINT point;
			GetCursorPos(&point);
			SetCursorPos(deltax / aimsmooth + point.x, deltay / aimsmooth + point.y);
			printfdbg("set %d %d\n", deltax, deltay);
			needaim = 0;
		}
		Sleep(1);
	}
}

void TriggerCheck()
{
	bool exiting = 0;  
	while (true)
	{
		if (tWnd == GetForegroundWindow()) {
			if (GetAsyncKeyState(33) < 0) {
				if (mode < 2)
					mode++;
				else mode = 0;
				Sleep(300);  
			}

			if (GetAsyncKeyState(34) < 0) {
				if (mode > 0)
					mode--;
				else mode = 2;
				Sleep(300);  
			}

			if (GetAsyncKeyState(VK_HOME) < 0) {
				if (mineteam == 0)
					mineteam = 1;
				else mineteam = 0;
				Sleep(300);  
			}
			 
			if (GetAsyncKeyState(VK_LEFT) < 0) {
				if(aimfov > 1 && mode == 1)
					aimfov--;

				if (tbdelaymax > 1 && mode == 2) 
				{
					if (tbdelaymax > tbdelaymin + 1)
						tbdelaymax--;
				}

				Sleep(5);  
			}

			if (GetAsyncKeyState(VK_RIGHT) < 0) {
				if(mode == 1)
					aimfov++;

				if (mode == 2)
					tbdelaymax++;

				Sleep(5);  
			}

			if (GetAsyncKeyState(VK_DOWN) < 0) {
				if(aimsmooth > 1 && mode == 1)
					aimsmooth--;

				if (tbdelaymin > 0 && mode == 2)
					tbdelaymin--;

				Sleep(20);  
			}

			if (GetAsyncKeyState(VK_UP) < 0) {
				if(mode == 1)
					aimsmooth++;

				if (mode == 2) 
				{
					tbdelaymin++;
					if (tbdelaymin >= tbdelaymax)
						tbdelaymax = tbdelaymin + 1;
				}

				Sleep(20);  
			}

			if (GetAsyncKeyState(VK_OEM_PLUS) < 0) {
				if (mode == 2)
					tbdelaybetween++;
				
				Sleep(5);
			}

			if (GetAsyncKeyState(VK_OEM_MINUS) < 0) {
				if (tbdelaybetween > tbdelaybetween_rand && mode == 2)
					tbdelaybetween--;

				Sleep(5);
			}

			if (!exiting && GetAsyncKeyState(VK_DELETE) < 0) {
				mode = 0;  
				Beep(1568, 500);  
				_exit(0);
				/*
				CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DisExit, 0, 0, 0);  
				exiting = 1;  
				Sleep(1000);  
				*/
			}

			if (mode == 2) { 
				pixel = rearrange(GetPixel(hdc, Width / 2, Height / 2)); 
			}

			if (mode == 1) {
				if (GetAsyncKeyState(VK_LBUTTON) < 0)
					TakeScreenshot(aimfov * 2, aimfov * 2);
			}
		}

		Sleep(1);  
	}
}
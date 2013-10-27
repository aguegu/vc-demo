// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"
#include "CForm.h"
#include <cstdio>

#include <windows.h>

int main(int argc, char* argv[])
{
	CForm frm;
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	SMALL_RECT x = {0, 0, columns, rows}; 
	// frm.clear(x, '*');

	SMALL_RECT y = {2, 1, columns - 2, rows - 1}; 
	// frm.clear(y);

	frm.drawBox(x);
	frm.drawBox(y);

	Sleep(1000);
	return 0;
}


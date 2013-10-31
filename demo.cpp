// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

int main(int argc, char* argv[])
{
	CForm frm;
	
	COORD size = CForm::getScreenSize();

	SMALL_RECT x = {0, 0, size.X, size.Y}; 
	// frm.clear(x, '*');

	SMALL_RECT y = {2, 1, size.X - 2, size.Y - 1}; 
	// frm.clear(y);

	frm.drawBox(x);
	frm.drawBox(y);

	Sleep(1000);
	return 0;
}


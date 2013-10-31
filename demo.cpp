// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

int main(int argc, char* argv[])
{
	COORD size = CForm::getScreenSize();

	SMALL_RECT full = {0, 0, size.X, size.Y}; 
	CForm form_main("Ä¸´°¿Ú", full);

	SMALL_RECT sub = {2, 1, size.X - 10, size.Y - 6}; 
	CForm form_sub("×Ó´°¿Ú", sub);
	
	form_main.drawBorder();
	form_main.showText();
	
	form_sub.drawBorder();
	form_sub.showText();
	
	Sleep(1000);
	return 0;
}


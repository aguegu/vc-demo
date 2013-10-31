// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

int main(int argc, char* argv[])
{
	COORD size = CForm::getScreenSize();

	SMALL_RECT full = {0, 0, size.X, size.Y}; 
	CForm form_main("主窗口", full);

	SMALL_RECT sub = {2, 1, size.X - 20, size.Y - 1}; 
	CForm form_sub("子窗口01", sub);

	//CForm form_sub;
	
	form_main.setAttribute(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE);
	form_main.clear();
	form_main.drawBorder();
	form_main.showText();
	
	form_sub.setAttribute(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY);
	form_sub.clear();
	form_sub.drawBorder();
	form_sub.showText();
	
	Sleep(5000);
	return 0;
}


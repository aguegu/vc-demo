// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

int main(int argc, char* argv[])
{
	COORD full_size = CForm::getScreenSize();
	COORD zero = {0, 0};

	CForm form_main("主窗口", zero, full_size);

	COORD point = {2, 3};
	COORD size = {20, 5}; 
	CForm form_sub("子窗口01", point, size);

	//CForm form_sub;
	
	form_main.setAttribute(FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE);
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


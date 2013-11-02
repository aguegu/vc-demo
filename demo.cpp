// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

int main(int argc, char* argv[])
{
	COORD full_size = CForm::getScreenSize();
	COORD zero = {0, 0};

	CForm form_main("主窗口", zero, full_size);
	form_main.setAttribute(FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE);
	form_main.display();
	
	COORD point = {2, 3};
	COORD size = {20, 5}; 
	CForm form_sub("子窗口01", point, size);

	form_sub.setAttribute(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY);
	form_sub.display();

	COORD label = {30, 20};
	CLabel x("hello");
	x.moveTo(label);
	
	x.clear();
	x.display();
	


	Sleep(1000);
	return 0;
}


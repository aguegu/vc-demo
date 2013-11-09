// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

void init() {
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
	CLabel x("hello", 8);
	x.moveTo(label);
	x.display();

	COORD ok_position = {24, 16};
	CButton button_ok("ok", 8);
	button_ok.moveTo(ok_position);
	button_ok.getFocus();

	COORD cancel_position = {40, 16};
	CButton button_cancel("cancel", 8);
	button_cancel.setAttribute(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE);
	button_cancel.moveTo(cancel_position);
	button_cancel.display();
}

int main(int argc, char* argv[])
{
	//init();
	int x;
	while ((x = _getch()) != 0x1b)
		printf("0x%02x\n", x);


	//Sleep(1000);
	return 0;
}



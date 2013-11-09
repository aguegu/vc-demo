// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

void init() {
	COORD full_size = CForm::getScreenSize();
	COORD zero = {0, 0};

	CForm form_main("Ö÷´°¿Ú", zero, full_size);
	form_main.setAttribute(FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE);
	form_main.display();
	
	COORD label = {30, 20};
	CLabel x("hello", 8);
	x.moveTo(label);
	x.display();

	COORD position_ok = {12, 16};
	CButton button_ok("ok", 8);
	button_ok.moveTo(position_ok);
	button_ok.getFocus();

	COORD position_cancel = {24, 16};
	CButton button_cancel("cancel", 8);
	button_cancel.moveTo(position_cancel);
	button_cancel.display();

	COORD position_exit = {36, 16};
	CButton button_exit("exit", 8);
	button_exit.moveTo(position_exit);
	button_exit.display();
}

int main(int argc, char* argv[])
{
	init();
	int x;
	while ((x = _getch()) != 0x1b) {
		if (x == 0 || x == 0xe0) {
			x <<= 8;
			x += _getch();
		}
		printf("0x%02X\n", x);
	}

	return EXIT_SUCCESS;
}



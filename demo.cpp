// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

typedef struct {
	COORD Coord;
	char *Text;
	short Length;
} ButtonAttribute ;

static ButtonAttribute button_attributes[3] = {
	{{12, 16}, "login", 8},
	{{24, 16}, "cancel", 8},
	{{36, 16}, "exit", 8},
};

static std::vector<CForm *> controls;
static int focus_on = 0;

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

	for (int i = 0; i < 3; i++) {
		CButton *button = new CButton(button_attributes[i].Text, button_attributes[i].Length);
		button->moveTo(button_attributes[i].Coord);
		button->display();
		controls.push_back(button);		
	}
}

void teardown() {
	for (int i = 0; i< 3; i++)
		free(controls[i]);
}

int main(int argc, char* argv[])
{
	init();	
	
	while (1) {
		int key = controls[focus_on]->getFocus();	

		switch (key) {
		case KEY_UP:
		case KEY_LEFT:
		case KEY_TAB:
			focus_on = (focus_on + 2) % 3;
			break;
		case KEY_DOWN:
		case KEY_RIGHT:
			focus_on = (focus_on + 1) % 3;
			break;
		}

		if (focus_on == 0 && key == KEY_ENTER)
			break;
	}

	teardown();

	return EXIT_SUCCESS;
}



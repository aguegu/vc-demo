// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

typedef struct {
	COORD Coord;
	char *Text;
	short Length;
} ControlAttribute ;

static ControlAttribute button_attributes[3] = {
	{{6, 16}, "login", 8},
	{{18, 16}, "cancel", 8},
	{{30, 16}, "exit", 8},
};

static ControlAttribute label_attributes[2] = {
	{{6, 4}, "username:", 0},
	{{6, 6}, "password:", 0},
};

static ControlAttribute text_attributes[2] = {
	{{16, 4}, "", 16},
	{{16, 6}, "", 16},
};


static std::vector<CForm *> controls;
static int focus_on = 0;

void init() {
	COORD full_size = CForm::getScreenSize();
	COORD zero = {0, 0};
	int i;

	CForm form_main("Ö÷´°¿Ú", zero, full_size);
	form_main.setAttribute(FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE);
	form_main.display();

	for (i = 0; i < 2; i++) {
		CLabel x(label_attributes[i].Text);
		x.moveTo(label_attributes[i].Coord);
		x.display();
	}

	CText *text = new CText(text_attributes[0].Length);
	text->moveTo(text_attributes[0].Coord);
	text->display();
	controls.push_back(text);

	CPassword *password = new CPassword(text_attributes[1].Length);
	password->moveTo(text_attributes[1].Coord);
	password->display();
	controls.push_back(password);
	

	for (i = 0; i < 3; i++) {
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
			focus_on = (focus_on + controls.size() - 1) % controls.size();
			break;
		case KEY_DOWN:
		case KEY_RIGHT:
			focus_on = (focus_on + 1) % controls.size();
			break;
		}

		if (key == KEY_ENTER)
			if (focus_on == 4)
				break;
			else if (focus_on == 2) {
				printf("\r\n\r\n%s | %s", controls[0]->getText().c_str(), controls[1]->getText().c_str());
			}

			// int key = CForm::getKeyInput();
		// printf("0x%02x\r\n", key);
		// if (key == KEY_ENTER)
		// 	break;
	}

	teardown();

	return EXIT_SUCCESS;
}



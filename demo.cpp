// demo.cpp : Defines the entry point for the console application.
//

#include "demo.h"

typedef struct {
	COORD Coord;
	char *Text;
	short Length;
} ControlAttribute ;

static ControlAttribute button_attributes[2] = {
	{{6, 16}, "µÇÂ¼", 8},
	{{18, 16}, "ÍË³ö", 8},
};

static ControlAttribute label_attributes[2] = {
	{{6, 4}, "ÐÕÃû:", 0},
	{{6, 6}, "ÃÜÂë:", 0},
};

static ControlAttribute text_attributes[2] = {
	{{16, 4}, "", 16},
	{{16, 6}, "", 16},
};

static std::vector<CForm *> controls;
static int focus_on = 0;
std::string profile_path;

std::string username;
std::string password;

void initProfile() {
	char s[_MAX_PATH];
	//GetPrivateProfileString("database", "username", "username", username, 16, "C:\\Users\\agu\\Documents\\GitHub\\vc-demo\\profile.ini");
	
	GetModuleFileName(NULL, s, _MAX_PATH);
	profile_path = s;
	profile_path.erase(profile_path.rfind('\\')).append("\\profile.ini");

	GetPrivateProfileString("database", "username", "username", s, _MAX_PATH, profile_path.c_str());
	username = s;

	GetPrivateProfileString("database", "password", "pasword", s, _MAX_PATH, profile_path.c_str());
	password = s;

}

void init() {
	COORD full_size = CForm::getScreenSize();
	COORD zero = {0, 0};
	int i;
	
	CForm form_main("µÇÂ¼½çÃæ", zero, full_size);
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

	CPassword *text_password = new CPassword(text_attributes[1].Length);
	text_password->moveTo(text_attributes[1].Coord);
	text_password->display();
	controls.push_back(text_password);
	
	for (i = 0; i < 2; i++) {
		CButton *button = new CButton(button_attributes[i].Text, button_attributes[i].Length);
		button->moveTo(button_attributes[i].Coord);
		button->display();
		controls.push_back(button);
	}
	
	initProfile();
}

void teardown() {
	for (int i = 0; i< controls.size(); i++)
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
			if (focus_on == 3)
				break;
			else if (focus_on == 2) {

				if (controls[0]->getText().compare(username) == 0 &&
					controls[1]->getText().compare(password) == 0)
					printf("\n\n\n\n       login successfully.      ");
				else
					printf("\n\n\n\n       bad username or password.");
			}

			// int key = CForm::getKeyInput();
		// printf("0x%02x\r\n", key);
		// if (key == KEY_ENTER)
		// 	break;
	}

	teardown();

	return EXIT_SUCCESS;
}



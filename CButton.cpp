#include "CButton.h"

CButton::CButton(const std::string &text): CForm(text) {
	COORD size = {text.length() + 4, 3};
	this->setSize(size);
	this->setAttribute(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE);
}

CButton::CButton(const std::string &text, short length): CForm(text) {
	COORD size = {length + 4, 3};
	this->setSize(size);
	this->setAttribute(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE);
}

CButton::~CButton() {

}

void CButton::display() {
	this->applyAttribute();
	this->clear();
	this->drawBorder();
	this->moveCursorTo((_size.X - _text.length()) / 2, 1);
	this->showText();
}

int CButton::getFocus() {
	CForm::setConsoleAttribute(FOREGROUND_BLUE | BACKGROUND_INTENSITY);
	this->clear();
	this->drawBorder();
	this->moveCursorTo((_size.X - _text.length()) / 2, 1);
	this->showText();

	while (int key = CForm::getKeyInput()) {
		switch (key) {
		case KEY_TAB:
		case KEY_UP:
		case KEY_DOWN:
		case KEY_LEFT:
		case KEY_RIGHT:
		case KEY_ENTER:
		case KEY_ESC:
			this->display();
			return key;
		}
	}

	return 0;
}
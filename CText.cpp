#include "CText.h"

CText::CText(short length) {
	COORD size = {length, 1};
	this->setSize(size);
	this->setText("");
	this->setAttribute(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_GREEN);
}

CText::~CText() {

}

void CText::display() {
	this->applyAttribute();
	this->refresh();
}

int CText::getFocus() {
	CForm::setConsoleAttribute(FOREGROUND_BLUE | BACKGROUND_INTENSITY);

	this->refresh();
	this->moveCursorTo(_text.length(), 0);

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

		if (isprint(key))
			this->setText(_text.append(1, (char)key));
		else if (key == KEY_BACKSPACE && _text.length() > 0)
			this->setText(_text.erase(_text.length() - 1));

		this->refresh();
	}

	return 0;
}

void CText::refresh() {
	this->clear();
	this->moveCursorTo(0, 0);
	this->showText();
}
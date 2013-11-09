#include "CButton.h"

CButton::CButton(const std::string &text): CForm(text) {
	COORD size = {text.length() + 4, 3};
	this->setSize(size);
}

CButton::CButton(const std::string &text, short length): CForm(text) {
	COORD size = {length + 4, 3};
	this->setSize(size);
}

CButton::~CButton() {

}

void CButton::display() {
	this->clear();	
	this->drawBorder();
	this->moveCursorTo((_size.X - _text.length()) / 2, 1);
	this->showText();
}


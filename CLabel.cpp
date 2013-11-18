#include "CLabel.h"

CLabel::CLabel(const std::string &text): CForm(text) {
	COORD size = {text.length(), 1};
	this->setSize(size);
	this->setAttribute(FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE);
}

CLabel::CLabel(const std::string &text, short length): CForm(text) {
	COORD size = {length, 1};
	this->setSize(size);
	this->setAttribute(FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE);
}

CLabel::~CLabel() {

}

void CLabel::display() {
	this->applyAttribute();
	this->clear();
	this->moveCursorTo(0, 0);
	this->showText();
}


#include "CLabel.h"

CLabel::CLabel(const std::string &text): CForm(text) {
	COORD size = {text.length(), 1};
	this->setSize(size);
}

CLabel::CLabel(const std::string &text, short length): CForm(text) {
	COORD size = {length, 1};
	this->setSize(size);
}

CLabel::~CLabel() {

}

void CLabel::display() {
	this->clear();
	this->moveCursorTo(0, 0);
	this->showText();
}


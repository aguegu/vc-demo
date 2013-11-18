#include "CPassword.h"

CPassword::CPassword(short length) : CText(length) {

}

CPassword::~CPassword() {

}

void CPassword::showText() {
	std::string s(_text);
	s.replace(0, s.length(), s.length(), '*');
	CForm::writeConsole(s);
}
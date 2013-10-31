#include "CForm.h"

HANDLE CForm::_output = GetStdHandle(STD_OUTPUT_HANDLE);

CForm::CForm() {
	_text = "";
	_box.Left = 0;
	_box.Right = 4;
	_box.Top = 0;
	_box.Bottom = 2;
	_attribute = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
}

CForm::CForm(const std::string &text, const SMALL_RECT &box) {
	_text = text;
	_box = box;
	_attribute = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
}

CForm::~CForm() {

}

COORD CForm::getScreenSize() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    COORD size = {columns, rows};
    return size;
}

void CForm::setAttribute(WORD attribute) {
	this->_attribute = attribute;
}

void CForm::display() {

}

int CForm::waitForInput(int key) {
	return key;
}

std::string& CForm::getText() {
	return _text;
}

void CForm::moveCursorTo(short x, short y) {
	COORD coordination = {x, y};
	SetConsoleCursorPosition(_output, coordination);
}

void CForm::clear(char c) {
	for (short y = _box.Top; y < _box.Bottom; y++)
		drawLine(c, _box.Left, y, _box.Right - _box.Left);
}

void CForm::drawLine(char c, short x, short y, short length) {
	char *s = (char *)malloc(sizeof(char) * (length + 1));
	memset(s, c, length);
	s[length] = '\0';
	
	SetConsoleTextAttribute(_output, this->_attribute);
 	this->moveCursorTo(x, y);
	WriteConsole(_output, s, length, NULL, NULL);

	free(s);
}

void CForm::drawBorder() {
	SetConsoleTextAttribute(_output, this->_attribute);

	this->moveCursorTo(_box.Left, _box.Top);
	WriteConsole(_output, "©³", 2, NULL, NULL);
	this->moveCursorTo(_box.Left, _box.Bottom - 1);
	WriteConsole(_output, "©»", 2, NULL, NULL);
	this->moveCursorTo(_box.Right - 2, _box.Top);
	WriteConsole(_output, "©·", 2, NULL, NULL);
	this->moveCursorTo(_box.Right - 2, _box.Bottom - 1);
	WriteConsole(_output, "©¿", 2, NULL, NULL);

	for (int x = _box.Left + 2; x < _box.Right - 2; x += 2) {
		this->moveCursorTo(x, _box.Top);
		WriteConsole(_output, "©¥", 2, NULL, NULL);
		this->moveCursorTo(x, _box.Bottom - 1);
		WriteConsole(_output, "©¥", 2, NULL, NULL);			
	}

	for (int y = _box.Top + 1; y < _box.Bottom - 1; y++) {
		this->moveCursorTo(_box.Left, y);
		WriteConsole(_output, "©§", 2, NULL, NULL);	
		this->moveCursorTo(_box.Right -2, y);
		WriteConsole(_output, "©§", 2, NULL, NULL);		
	}
}

void CForm::showText() {
	this->moveCursorTo(_box.Left + 2, _box.Top);
	SetConsoleTextAttribute(_output, this->_attribute);
	WriteConsole(_output, _text.c_str(), _text.length(), NULL, NULL);	
}
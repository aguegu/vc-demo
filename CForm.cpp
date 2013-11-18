#include "CForm.h"

HANDLE CForm::_output = GetStdHandle(STD_OUTPUT_HANDLE);

CForm::CForm() {
	this->init();
}

CForm::CForm(const std::string &text) {
	this->init();
	this->setText(text);
}

CForm::CForm(const std::string &text, const COORD &location, const COORD &size) {
	this->init();

	this->setText(text);
	this->moveTo(location);
	this->setSize(size);
}

CForm::~CForm() {

}

void CForm::init() {
	_text = "";

	_location.X = 0;
	_location.Y = 0;

	_size.X = 1;
	_size.Y = 1;

	_attribute = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
}

void CForm::setText(const std::string &text) {
	_text = text;
}

void CForm::moveTo(const COORD &location) {
	_location = location;
}

void CForm::setSize(const COORD &size) {
	_size = size;
}

COORD CForm::getScreenSize() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    COORD size = {columns, rows};
    return size;
}

void CForm::setConsoleAttribute(WORD attribute) {
	SetConsoleTextAttribute(_output, attribute);
}

void CForm::setAttribute(WORD attribute) {
	this->_attribute = attribute;
}

int CForm::getFocus() {
	return 0;
}

std::string& CForm::getText() {
	return _text;
}

void CForm::moveCursorTo(short x, short y) {
	assert(x < _size.X);
	assert(y < _size.Y);

	COORD coordination = {_location.X + x, _location.Y + y};
	SetConsoleCursorPosition(_output, coordination);
}

void CForm::clear(char c) {
	for (short y = 0; y < _size.Y; y++)
		drawLine(c, 0, y, _size.X);
}

void CForm::drawLine(char c, short x, short y, short length) {
	assert(length <= _size.X);

	char *s = (char *)malloc(sizeof(char) * length);
	memset(s, c, length);

 	this->moveCursorTo(x, y);
	WriteConsole(_output, s, length, NULL, NULL);

	free(s);
}

void CForm::drawBorder() {
	this->moveCursorTo(0, 0);
	WriteConsole(_output, "©³", 2, NULL, NULL);
	this->moveCursorTo(0, _size.Y - 1);
	WriteConsole(_output, "©»", 2, NULL, NULL);
	this->moveCursorTo(_size.X - 2, 0);
	WriteConsole(_output, "©·", 2, NULL, NULL);
	this->moveCursorTo(_size.X - 2, _size.Y - 1);
	WriteConsole(_output, "©¿", 2, NULL, NULL);

	for (int x = 2; x < _size.X - 2; x += 2) {
		this->moveCursorTo(x, 0);
		WriteConsole(_output, "©¥", 2, NULL, NULL);
		this->moveCursorTo(x, _size.Y - 1);
		WriteConsole(_output, "©¥", 2, NULL, NULL);
	}

	for (int y = 1; y < _size.Y - 1; y++) {
		this->moveCursorTo(0, y);
		WriteConsole(_output, "©§", 2, NULL, NULL);
		this->moveCursorTo(_size.X -2, y);
		WriteConsole(_output, "©§", 2, NULL, NULL);
	}
}

void CForm::writeConsole(std::string str) {
	WriteConsole(_output, str.c_str(), str.length(), NULL, NULL);
}

void CForm::showText() {
	CForm::writeConsole(_text);
}

void CForm::display() {
	this->applyAttribute();
	this->clear();
	this->drawBorder();
	this->moveCursorTo(2, 0);
	this->showText();
}

void CForm::applyAttribute() {
	CForm::setConsoleAttribute(this->_attribute);
}

int CForm::getKeyInput() {
	int key;
	key = _getch();

	if (key == 0 || key == 0xe0) {
		key <<= 8;
		key += _getch();
	}

	return key;
}
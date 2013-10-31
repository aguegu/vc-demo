#include "CForm.h"

HANDLE CForm::_output = GetStdHandle(STD_OUTPUT_HANDLE);

CForm::CForm() {
	_box.Left = 0;
	_box.Top = 0;
	_text = "Hello, world.";
}

CForm::CForm(const std::string &text, const SMALL_RECT &box) {
	_text = text;
	_box = box;
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

void CForm::clear(const SMALL_RECT &box, char c) {
	for (short y = box.Top; y < box.Bottom; y++)
		drawLine(c, box.Left, y, box.Right - box.Left);
}

void CForm::drawLine(char c, short x, short y, short length) {
	char *s = (char *)malloc(sizeof(char) * (length + 1));
	memset(s, c, length);
	s[length] = '\0';
	COORD coord = {x, y};
	WriteConsoleOutputCharacter(_output, s, length, coord, NULL);	
	free(s);
}

void CForm::drawBox(const SMALL_RECT &box) {
	COORD coord_left_top = {box.Left, box.Top};
	COORD coord_left_bottom = {box.Left, box.Bottom - 1};
	COORD coord_right_top = {box.Right - 2, box.Top};
	COORD coord_right_bottom = {box.Right - 2, box.Bottom - 1};

	WriteConsoleOutputCharacter(_output, "©³", 2, coord_left_top, NULL);
	WriteConsoleOutputCharacter(_output, "©·", 2, coord_right_top, NULL);
	WriteConsoleOutputCharacter(_output, "©¿", 2, coord_right_bottom, NULL);
	WriteConsoleOutputCharacter(_output, "©»", 2, coord_left_bottom, NULL);

	for (int x = box.Left + 2; x < box.Right - 2; x += 2) {
		COORD top = {x, box.Top};
		COORD bottom = {x, box.Bottom - 1};
		WriteConsoleOutputCharacter(_output, "©¥", 2, top, NULL);
		WriteConsoleOutputCharacter(_output, "©¥", 2, bottom, NULL);
	}

	for (int y = box.Top + 1; y < box.Bottom - 1; y++) {
		COORD left = {box.Left, y};
		COORD right = {box.Right -2, y};
		WriteConsoleOutputCharacter(_output, "©§", 2, left, NULL);
		WriteConsoleOutputCharacter(_output, "©§", 2, right, NULL);
	}
}

void CForm::showText() {

}
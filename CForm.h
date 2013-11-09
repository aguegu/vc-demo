#ifndef _CForm_H_
#define _CForm_H_

#include <string>
#include <iostream>
#include <windows.h>
#include <assert.h>
#include <conio.h>

#define KEY_TAB	(0x09)
#define KEY_ESC (0x1b)
#define KEY_ENTER	 (0x0d)
#define KEY_UP	(0xe048)
#define KEY_LEFT	(0xe04b)
#define KEY_RIGHT	(0xe04d)
#define KEY_DOWN	(0xe050)

class CForm {
public:
	CForm();
	CForm(const std::string &text);
	CForm(const std::string &text, const COORD &loccation, const COORD &size);

	virtual	~CForm();

	void setText(const std::string &text);
	void moveTo(const COORD &location);
	void setSize(const COORD &size);

	virtual void display();
	virtual int getFocus();
	std::string& getText();
	void setAttribute(WORD attribute);

	void moveCursorTo(short x, short y);
	void drawBorder();
	void clear(char c = ' ');
	// static void store(const SMALL_RECT &box);
	// static void restore(const SMALL_RECT &box);
	static COORD getScreenSize();
	static void setConsoleAttribute(WORD attribute);
	static int getKeyInput();

protected:
	void showText();
	void applyAttribute();


	COORD _size;
	std::string _text;

private:
	static HANDLE _output;
	COORD _location;
	WORD _attribute;

	void init();
	void drawLine(char c, short x, short y, short length);

};


#endif
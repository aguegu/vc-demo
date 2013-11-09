#ifndef _CForm_H_
#define _CForm_H_

#include <string>
#include <iostream>
#include <windows.h>
#include <assert.h>

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
	virtual int waitForInput(int key);
	std::string& getText();
	void setAttribute(WORD attribute);
	
	void moveCursorTo(short x, short y);
	void drawBorder();
	void clear(char c = ' ');
	// static void store(const SMALL_RECT &box);
	// static void restore(const SMALL_RECT &box);
	void showTitle();
	static COORD getScreenSize();

protected:
	void showText();
	COORD _size;
	std::string _text;

private:
	void drawLine(char c, short x, short y, short length);
	void init();

	static HANDLE _output;
	
	COORD _location;	
	WORD _attribute;
};


#endif
#ifndef _CForm_H_
#define _CForm_H_

#include <string>
#include <iostream>
#include <windows.h>
#include <assert.h>

class CForm {
public:
	CForm();
	CForm(const std::string &text, const SMALL_RECT &box);
	virtual	~CForm();
	virtual void display();
	virtual int waitForInput(int key);
	std::string& getText();
	void setAttribute(WORD attribute);
	
	void moveCursorTo(short x, short y);
	void drawBorder();
	void clear(char c = ' ');
	// static void store(const SMALL_RECT &box);
	// static void restore(const SMALL_RECT &box);
	void showText();
	static COORD getScreenSize();

protected:
	
	static HANDLE _output;
	std::string _text;
	SMALL_RECT _box;
	WORD _attribute;

private:
	void drawLine(char c, short x, short y, short length);
};


#endif
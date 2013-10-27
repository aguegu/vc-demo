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
	std::string& getTitle();
	
	void moveCursorTo(short x, short y);
	void drawBox(const SMALL_RECT &box);
	static void clear(const SMALL_RECT &box, char c = ' ');
	static void Store(const SMALL_RECT &box);
	static void Restore(const SMALL_RECT &box);
	static void showTitle();
	
protected:
	std::string _text;
	SMALL_RECT _box;
	static HANDLE _output;

private:
	static void drawLine(char c, short x, short y, short length);
};


#endif
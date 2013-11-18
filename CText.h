#ifndef _CTEXT_H_
#define _CTEXT_H_

#include "CForm.h"

class CText : public CForm {
public:
	CText(short length);
	virtual ~CText();
	void display();
	int getFocus();
private:
	void refresh();
};

#endif
#ifndef _CBUTTON_H_
#define _CBUTTON_H_

#include "CForm.h"

class CButton : public CForm {
public:
	CButton(const std::string &text);
	CButton(const std::string &text, short length);
	virtual ~CButton();
	void display();
};

#endif 
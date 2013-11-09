#ifndef _CLABEL_H_
#define _CLABEL_H_

#include "CForm.h"

class CLabel : public CForm {
public:
	CLabel(const std::string &text);
	CLabel(const std::string &text, short length);
	virtual ~CLabel();
	void display();
};

#endif 
#ifndef _CLABEL_H_
#define _CLABEL_H_

#include "CForm.h"

class CLabel : public CForm {
public:
	CLabel(const std::string &text);
	virtual ~CLabel();
	void display();

};

#endif 
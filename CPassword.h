#ifndef _CPASSWORD_H_
#define _CPASSWORD_H_

#include "CText.h"

class CPassword : public CText {
public:
	CPassword(short length);
	virtual ~CPassword();
protected:
	void showText();
};

#endif 
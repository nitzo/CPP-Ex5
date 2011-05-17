#ifndef __ACCOUNTIMPL_H__
#define __ACCOUNTIMPL_H__

#include "Observer.h"

class AccountImpl : public Observer {

public:
	AccountImpl(Subject *bank, float percent, char *date int period);


private:

	float percent;
	char* date;
	int period;
};


#endif
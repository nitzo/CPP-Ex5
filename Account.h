#ifndef __ACCOUNT_H__
#define __ACOOUNT_H__

#include "Subject.h"

class AccountImpl;

class Account {

public:
	~Account();
	Account(Subject* bank);

private:
	AccountImpl* m_Account;			//Actual Account Implementation

};

#endif
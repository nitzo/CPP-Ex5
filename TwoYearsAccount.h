#ifndef __TWOYEARSACCOUNT_H__
#define __TWOYEARSACCOUNT_H__

#include "AccountImpl.h"

//
//Class Representing an Account that allowed to close any time after 2 years
//
class TwoYearsAccount : AccountImpl{

	TwoYearsAccount (float percent, int date, Period period )
		: AccountImpl( percent, date, period ){}
	~TwoYearsAccount();

	bool Close();
	bool IsManageableByFamilyMember();
	bool InvestInStockMarket(int sum);
};

#endif
#ifndef __FAMILYACCOUNT_H__
#define __FAMILYACCOUNT_H__

#include "AccountImpl.h"

//
//Class Representing an Account that can be managed by all family members ( family accounts )
//
class FamilyAccount : AccountImpl{

	TwoYearsAccount ( float percent, int date, Period period )
		: AccountImpl( percent, date, period ){}
	~TwoYearsAccount();

	bool Close();
	bool IsManageableByFamilyMember();
	bool InvestInStockMarket(int sum);
};

#endif
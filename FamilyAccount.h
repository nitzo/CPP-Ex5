#ifndef __FAMILYACCOUNT_H__
#define __FAMILYACCOUNT_H__

#include "AccountImpl.h"
#include <string>

using namespace std;


//
//Class Representing an Account that can be managed by all family members ( family accounts )
//
class FamilyAccount : public AccountImpl{

public:

	FamilyAccount ( float percent, int date, Period period, int id);
	~FamilyAccount();

	bool Close(int currentDate);
	bool IsManageableByFamilyMember();
	bool InvestInStockMarket(int sum);
};

#endif
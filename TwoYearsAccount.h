#ifndef __TWOYEARSACCOUNT_H__
#define __TWOYEARSACCOUNT_H__

#include "AccountImpl.h"
#include <string>

using namespace std;

//
//Class Representing an Account that allowed to close any time after 2 years
//
class TwoYearsAccount : public AccountImpl{

public:

	TwoYearsAccount (float percent, int date, Period period , int id);
	~TwoYearsAccount();

	bool Close(int currentDate);
	bool IsManageableByFamilyMember();
	bool InvestInStockMarket(int sum);
};

#endif
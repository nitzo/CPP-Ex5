#include "TwoYearsAccount.h"

TwoYearsAccount::~TwoYearsAccount()
{
	//Do Nothing
}

bool TwoYearsAccount::Close(int currentDate)
{
	int duration = currentDate-date;

	if(duration < 2){
		return false;
	}

	closed = true;
	return true;
}

bool TwoYearsAccount::IsManageableByFamilyMember()
{
	return false;
}

bool TwoYearsAccount::InvestInStockMarket( int sum )
{
	return false;
}



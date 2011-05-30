#include "TwoYearsAccount.h"


TwoYearsAccount::TwoYearsAccount( float percent, int date, Period period, int id )
	: AccountImpl( TWOYEARS ,percent, date, period , id){}

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



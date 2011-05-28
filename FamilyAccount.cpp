#include "FamilyAccount.h"

FamilyAccount::FamilyAccount( float percent, int date, Period period )
	: AccountImpl( 1,percent, date, period ){}

FamilyAccount::~FamilyAccount()
{
	//Do Nothing
}

bool FamilyAccount::Close(int currentDate)
{
	closed = true;
	return true;
}

bool FamilyAccount::IsManageableByFamilyMember()
{
	return true;
}

bool FamilyAccount::InvestInStockMarket( int sum )
{
	return false;
}


#include "FamilyAccount.h"

FamilyAccount::FamilyAccount( float percent, int date, Period period, int id )
	: AccountImpl( FAMILY,percent, date, period, id ){}

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


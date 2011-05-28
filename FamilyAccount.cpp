#include "FamilyAccount.h"

FamilyAccount::~TwoYearsAccount()
{
	//Do Nothing
}

bool FamilyAccount::Close()
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


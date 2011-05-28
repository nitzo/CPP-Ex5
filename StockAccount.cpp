#include "StockAccount.h"

StockAccount::~StockAccount()
{
	//Do Nothing
}

bool StockAccount::Close()
{
	closed = true;
	return true;
}

bool StockAccount::IsManageableByFamilyMember()
{
	return false;
}

bool StockAccount::InvestInStockMarket( int sum )
{
	if (sum > amount)
	{
		stockAmount += amount;
		amount = 0;
	}else{
		stockAmount += sum;
		amount -= sum;
		return true;
	}	
}

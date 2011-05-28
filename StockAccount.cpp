#include "StockAccount.h"

StockAccount::StockAccount( float percent, int date, Period period )
: AccountImpl( 2,percent, date, period ){}

StockAccount::~StockAccount()
{
	//Do Nothing
}


float StockAccount::GetStockAmount()
{
	return stockAmount;
}

bool StockAccount::Close(int currentDate)
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

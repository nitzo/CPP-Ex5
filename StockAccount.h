#ifndef __STOCKACCOUNT_H__
#define __STOCKACCOUNT_H__

#include "AccountImpl.h"

//
//Class Representing an Account that the deposit is allowed to invest in Stock Exchange
//
class StockAccount : AccountImpl{

public:

	StockAccount ( float percent, int date, Period period )
		: AccountImpl( percent, date, period ){}
	~StockAccount();

	bool Close();
	bool IsManageableByFamilyMember();
	bool InvestInStockMarket(int sum);

	int GetStockAmount();											//get the amount of investment in the stock market

private:

	//Members//
	int stockAmount;												//amount of investment in the stock market
};

#endif
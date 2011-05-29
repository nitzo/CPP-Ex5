#ifndef __STOCKACCOUNT_H__
#define __STOCKACCOUNT_H__

#include "AccountImpl.h"
#include <string>

using namespace std;

//
//Class Representing an Account that the deposit is allowed to invest in Stock Exchange
//
class StockAccount : public AccountImpl{

public:

	StockAccount ( float percent, int date, Period period );
	~StockAccount();

	bool Close(int currentDate);
	bool IsManageableByFamilyMember();
	bool InvestInStockMarket(int sum);

	float GetStockAmount();											//get the amount of investment in the stock market

private:

	//Members//
	float stockAmount;												//amount of investment in the stock market
};

#endif
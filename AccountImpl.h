#ifndef __ACCOUNTIMPL_H__
#define __ACCOUNTIMPL_H__

#include "Observer.h"

enum Period{THREE=3,SEVEN=7,TEN=10};												//Enum represent the saving period (in years)


class AccountImpl :{

public:
	AccountImpl(float percent, int date, Period period);			//CTOR
	virtual ~AccountImpl();															//DTOR

	//Information Methods//
	float GetPrecent() const;														//percent on deposit (interest)
	int GetDate() const;															//Year of creation
	Period GetPeriod() const;														//Saving period
	string GetLastMsg() const;														//bank last massage
	bool IsClosed() const;															//Is the current account is closed

	//Operations Methods//
	void deposit(int sum);															//deposit cash in the account
	float withdrawal(int sum);														//withdrawal cash from the account
	void updateMessage(string msg);													//update the bank last massage

	//Other Operations Methods//
	virtual bool Close();															//close the account
	virtual bool IsManageableByFamilyMember();										//Is the Account can be manage by family members
	virtual bool InvestInStockMarket(int sum);										//deposit an investment in the stock market

private:

	//Members//
	float percent;																	//percent on deposit (interest)
	int date;																		//Year of creation 
	Period period;																	//Saving period
	string lastMsg;																	//bank last massage
	float amount;																	//cash amount in the account
	bool closed;																	//Indicates is he account is closed

};

#endif
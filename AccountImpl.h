#ifndef __ACCOUNTIMPL_H__
#define __ACCOUNTIMPL_H__

#include <string>

#include "Account.h"


using namespace std;




class AccountImpl {

public:

	AccountImpl(Account_Type type,float percent, int date, Period period, int id);	//CTOR
	virtual ~AccountImpl();															//DTOR

	//Information Methods//
	float GetPrecent() const;														//percent on deposit (interest)
	int GetDate() const;															//Year of creation
	Period GetPeriod() const;														//Saving period
	string GetLastMsg() const;														//bank last massage
	float getAmount() const;														//cash amount in the account
	bool IsClosed() const;															//Is the current account is closed
	int GetAccountType() const;														//type of the account
	int GetId() const;

	//Operations Methods//
	void deposit(int sum);															//deposit cash in the account
	float withdraw(int sum);														//withdraw cash from the account
	void Notify(string msg);														//update the bank last massage

	//Other Operations Methods//
	virtual bool Close(int currentDate) = 0;										//close the account
	virtual bool IsManageableByFamilyMember() = 0;									//Is the Account can be manage by family members
	virtual bool InvestInStockMarket(int sum) = 0;									//deposit an investment in the stock market

protected:
	bool closed;																	//Indicates is he account is closed
	float amount;																	//cash amount in the account
	int date;																		//Year of creation 

private:
		
	//Members//
	int id;
	Account_Type type;																//type of the account
	float percent;																	//percent on deposit (interest)
	Period period;																	//Saving period
	string lastMsg;																	//bank last massage

};

#endif
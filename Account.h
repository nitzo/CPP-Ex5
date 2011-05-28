#ifndef __ACCOUNT_H__
#define __ACOOUNT_H__
//TODO: add include
//#include "tBank_t.h"
#include "AccountImpl.h"

//ENUM//
enum Account_Type{																	//enum of the Account types
	TWOYEARS,			//is allowed to close any time after 2 years
	FAMILY,				//can be managed by all family members ( family accounts )
	STOCKEXCHANGE};		//deposit is allowed to invest in Stock Exchange

enum Operation{																	//enum of the Account operations 
	DEPOSIT,			//deposit cash in the account
	WITHDRAWAL,			//withdrawal cash from the account
	DEPOSITSTOCK,		//invest in the stock market
	NOTIFY,				//send message to the account owners
	CLOSE};				//close the account

//ABC representing account 
//using Bridge Design pattern for its implementation those holds a Factory of different account implementations
//Observer of tBank_t
class Account {

public:
	Account(Account_Type type, int date, Period period, float PrecentOnDeposite);		//CTOR
	~Account();																		//DTOR

	//Observer method
	void Update(Operation operation, int amount, string msg);						//update the account state
	string GetAccountStatus();														//report of the current account

private:
	//Member//
	AccountImpl* m_Account;															//Instance of the Account Implementation

	//Factory Method//
	AccountImpl* Factory(Account_Type type, int date, Period period, float PrecentOnDeposite);		//AccountImpl Factory

	//Operation Methods
	void deposit(int amount);														//deposit cash in the account
	void withdrawal(int amount);													//withdrawal cash from the account
	void depositStock(int amount);													//deposit an investment in the stock market 
	void notify(string msg);														//notify the account by a massage
	//Other Operations//
	void close();																	//close the account

};

#endif
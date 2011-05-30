#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <string>

using namespace std;

class AccountImpl;


//ENUMS
enum Account_Type{																	//enum of the Account types
		TWOYEARS,			//is allowed to close any time after 2 years
		FAMILY,				//can be managed by all family members ( family accounts )
		STOCKEXCHANGE};		//deposit is allowed to invest in Stock Exchange



enum Operation	{																	//enum of the Account operations 
	DEPOSIT,			//deposit cash in the account
	WITHDRAWAL,			//withdrawal cash from the account
	DEPOSITSTOCK,		//invest in the stock market
	NOTIFY,				//send message to the account owners
	CLOSE};				//close the account


enum Period {THREE=3,SEVEN=7,TEN=10} ;												//Enum represent the saving period (in years)


//ABC representing account 
//using Bridge Design pattern for its implementation those holds a Factory of different account implementations
//Observer of tBank_t
class Account {

public:

	Account(Account_Type type, int date, Period period, float PrecentOnDeposite, int id);	//CTOR
	~Account();																		//DTOR

	//Observer method
	void Update(Operation operation, int amount, string msg);						//update the account state
	friend ostream &operator<< (ostream &os, Account &acc);							//report of the current account

	int getType() const;
	int getDate() const;
	Period getPeriod() const;

	
private:

	Account(const Account &t);														//Prevent COPY
	Account &operator=(const Account &t);											//Prevent COPY


	//Member//
	AccountImpl* m_Account;															//Instance of the Account Implementation

	//Factory Method//
	AccountImpl* AccountFactory(Account_Type type, int date, Period period, float PrecentOnDeposite, int id);	//AccountImpl Factory

	//Operation Methods
	void deposit(int amount);														//deposit cash in the account
	void withdraw(int amount);														//withdraw cash from the account
	void depositStock(int amount);													//deposit an investment in the stock market 
	void notify(string msg);														//notify the account by a massage

	//Other Operations//
	void close(int currentDate);													//close the account

};

#endif
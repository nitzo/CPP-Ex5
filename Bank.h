#ifndef __BANK_H__
#define  __BANK_H__


#include <vector>
#include "Account.h"
#include <string>

using namespace std;

class Account;

//An object representing a bank.
//This object is a:
//		1. Singleton and cannot be created more than once per program
//		2. Subject and can be observed by the accounts
class Bank{

public:
	
	
	static Bank& Instance()  {return m_bank;}			//get reference to the bank instance
	
	//Subject Methods//
	void Attach(Account* acc);							//add observer to observer list
	void Detach(Account* acc);							//remove observer from observer list
	
	Account *createNewAccount(int type, int date, int period, float PrecentOnDeposite);			//Create a new account and attach to bank

	friend ostream &operator<< (ostream &os, Bank &bank);	//report of the current bank
	
	//Observer notifications
	void InvestInStockExchange(int amount);				//Invest in stock exchange
	void GiveFamilyBonus();
	void Notify();										//notify all observer to come

	void deposit(int id, int amount);				//Deposit amount in account
	void withdraw(int id, int amount);				//Withdraw amount from account

private:

	Bank();											//Private CTOR in order to disable instantiation
	~Bank();										//DTOR - Deletes all accounts in bank
	Bank(const Bank &bank);							//Prevent COPY
	Bank &operator=(const Bank &bank);				//Prevent COPY

	static Bank m_bank;								//Singleton static object

	//Data Members//
	vector<Account*> m_accounts;						//observers Vector

};



#endif
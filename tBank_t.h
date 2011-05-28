#ifndef __TBANK_T_H__
#define  __TBANK_T_H__

#include "Account.h"

//An object representing a bank.
//This object is a:
//		1. Singleton and cannot be created more than once per program
//		2. Subject and can be observed by the accounts
class tBank_t{

public:
	
	//TODO: is this should be static to?
	static tBank_t& Instance() {return bank;}			//get reference to the bank instance

	//Subject Methods//
	void Attach(Account* acc);							//add observer to observer list
	void Detach(Account* acc);							//remove observer from observer list
	void Notify();										//notify all observer

private:

	tBank_t();											//Private CTOR in order to disable instantiation
	tBank_t(const tBank_t &bank);						//Prevent COPY
	tBank_t &operator=(tBank_t &bank);					//Prevent COPY

	static tBank_t bank;								//Singleton static object

	//Data Members//
	vector<Account*> m_accounts;						//observers Vector

};

#endif
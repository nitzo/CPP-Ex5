#include "Bank.h"
#include "Account.h"
#include <time.h>
#include <ostream>

Bank Bank::m_bank;

Bank::Bank() {
	//DO NOTHING
}


Bank::~Bank() {

	//Delete all of the accounts
	for (vector<Account *>::iterator it = m_accounts.begin(); it != m_accounts.end(); it++){
		delete *it;
	}

	m_accounts.clear();
}

Account *Bank::createNewAccount(int type, int date, int period, float PrecentOnDeposite){

	Account_Type aType;
	Period aPeriod;

	if (type == 0)
		aType = TWOYEARS;
	else if (type == 1)
		aType = FAMILY;
	else
		aType = STOCKEXCHANGE;

	if (period == 3)
		aPeriod = THREE;
	else if (period == 7)
		aPeriod = SEVEN;
	else
		aPeriod = TEN;
	

	Account *acc = new Account(aType, date, aPeriod, PrecentOnDeposite, m_accounts.size());

	this->Attach(acc);

	return acc;
}

void Bank::Attach( Account* acc)
{
	m_accounts.push_back(acc);
}

void Bank::Detach( Account* acc)
{
	unsigned int i = 0;

	for (i = 0; i < m_accounts.size(); i++) 
		if (m_accounts[i] == acc) break; 

	m_accounts.erase(m_accounts.begin() + i); 
}



void Bank::deposit(int id, int amount){
	if (id >= 0 && id < m_accounts.size())
		m_accounts[id]->Update(DEPOSIT, amount, "");
}

void Bank::withdraw(int id, int amount){
	if (id >= 0 && id < m_accounts.size())
		m_accounts[id]->Update(WITHDRAWAL, amount, "");
}

ostream &operator<< (ostream &os, Bank &bank){

	for (vector<Account *>::iterator it = bank.m_accounts.begin(); it != bank.m_accounts.end(); it++){

		 os << **it;

	}

	return os;

}

/** Ovserver notify methods **/

/* Invest in stock exchange only for accounts with openng time not bigger the 5 years ago
	and that saving period is TEN */
void Bank::InvestInStockExchange(int amount){

	time_t rawtime;
	time (&rawtime);
	struct tm * timeinfo;
	timeinfo = localtime(&rawtime);

	int year = timeinfo->tm_year + 1900;

	for (vector<Account *>::iterator it = m_accounts.begin(); it != m_accounts.end(); it++){

		if ((*it)->getDate() > year - 5 && (*it)->getPeriod() == TEN && (*it)->getType() == STOCKEXCHANGE){
			(*it)->Update(DEPOSITSTOCK, amount, "");
		}
	}

}

/* Give 500 shekels bonus to family accounts */
void Bank::GiveFamilyBonus(){

	for (vector<Account *>::iterator it = m_accounts.begin(); it != m_accounts.end(); it++){

		if ((*it)->getType() == FAMILY){
			(*it)->Update(DEPOSIT, 500, "");
		}
	}

}

/* Notify all accounts to come to bank */
void Bank::Notify(){

	for (vector<Account *>::iterator it = m_accounts.begin(); it != m_accounts.end(); it++){

		(*it)->Update(NOTIFY, 0, "Come to the bank please");
		
	}

}



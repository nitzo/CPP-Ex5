#include "Account.h"
#include "AccountImpl.h"
#include "FamilyAccount.h"
#include "StockAccount.h"
#include "TwoYearsAccount.h"



/****************
 * CTOR & DTOR
 ****************/

Account::Account( Account_Type type, int date, Period period, float PrecentOnDeposit, int id)
{
	m_Account = AccountFactory(type, date,period,PrecentOnDeposit, id);
	
}

Account::~Account()
{
	delete m_Account;
	m_Account = 0;
}


/*******************
 * Bridge Wrappers
 ******************/

void Account::Update( Operation operation, int amount, string msg )
{
	switch (operation)
	{
		case DEPOSIT:
			deposit(amount);
			break;
		case WITHDRAWAL:
			withdraw(amount);
			break;
		case DEPOSITSTOCK:
			depositStock(amount);
			break;
		case NOTIFY:
			notify(msg);
			break;
	}
}

ostream & operator<<( ostream &os, Account &acc )
{
	return os << "Account id: " << acc.m_Account->GetId() << "\n"
		<< "Account Type is " << acc.m_Account->GetAccountType() << " (0 - 2 years, 1- family, 2 - stock market)" << "\n"
		<< "percent on deposit: " << acc.m_Account->GetPrecent() << "\n"
		<< "Year of creation: " <<  acc.m_Account->GetDate() <<  "\n"
		<< "Saving period: " << acc.m_Account->GetPeriod() << "\n"
		<< "The bank last massage: " << acc.m_Account->GetLastMsg() << "\n"
		<< "cash amount in the account: " << acc.m_Account->getAmount() << "\n"
		<< "The Account is " << (acc.m_Account->IsClosed() ?  "closed" : "open") << "\n";
}

AccountImpl* Account::AccountFactory( Account_Type type, int date, Period period, float PrecentOnDeposite, int id )
{
	AccountImpl* account;

	switch (type)
	{
	case TWOYEARS:
		account = new TwoYearsAccount(PrecentOnDeposite,date,period, id);
		break;
	case FAMILY:
		account = new FamilyAccount(PrecentOnDeposite,date,period, id);
		break;
	case STOCKEXCHANGE:
		account = new StockAccount(PrecentOnDeposite,date,period, id);
		break;
	}

	return account;
}

void Account::deposit( int amount )
{
	m_Account->deposit(amount);
	
	string str;
	str += amount;
	str += " deposit to the account";
	
	m_Account->Notify(str);
}

void Account::withdraw( int amount )
{
	float result;

	result = m_Account->withdraw(amount);
	string str;
	str += (char) result;
	str += " withdrawal from the account";
	m_Account->Notify(str);
}

void Account::depositStock( int amount )
{
	int result;

	result = m_Account->InvestInStockMarket(amount);
	string str;
	str += (char) result;
	str += " invested in the stock market";
	m_Account->Notify(str);
}

void Account::notify( string msg )
{
	m_Account->Notify(msg);
}

void Account::close(int currentDate)
{
	bool result;
	result = m_Account->Close(currentDate);
	m_Account->Notify((result ? "the account were closed" : "unable to close the account"));
}

int Account::getDate() const{
	return m_Account->GetDate();
}

int Account::getType() const{
	return m_Account->GetAccountType();
}

Period Account::getPeriod() const {
	return m_Account->GetPeriod();
}


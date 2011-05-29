#include "Account.h"
#include "TwoYearsAccount.h"
#include "FamilyAccount.h"
#include "StockAccount.h"

Account::Account( Account_Type type,int date, Period period, float PrecentOnDeposite )
{
	m_Account = Factory(type, date,period,PrecentOnDeposite);
}

Account::~Account()
{
	delete m_Account;
	m_Account = 0;
}

void Account::Update( Operation operation, int amount, string msg )
{
	switch (operation)
	{
		case DEPOSIT:
			deposit(amount);
			break;
		case WITHDRAWAL:
			withdrawal(amount);
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
	return os << "Account Type is " << acc.m_Account->GetAccountType() << " (0 - 2 years, 1- family, 2 - stock market)" << "\n"
		<< "percent on deposit: " << acc.m_Account->GetPrecent() << "\n"
		<< "Year of creation: " <<  acc.m_Account->GetDate() <<  "\n"
		<< "Saving period: " << acc.m_Account->GetPeriod() << "\n"
		<< "The bank last massage: " << acc.m_Account->GetLastMsg() << "\n"
		<< "cash amount in the account: " << acc.m_Account->getAmount() << "\n"
		<< "The Account is " << (acc.m_Account->IsClosed() ?  "closed" : "open") << "\n";
}

AccountImpl* Account::Factory( Account_Type type, int date, Period period, float PrecentOnDeposite )
{
	AccountImpl* account = 0;

	switch (type)
	{
	case TWOYEARS:
		account = new TwoYearsAccount(PrecentOnDeposite,date,period);
	case FAMILY:
		account = new FamilyAccount(PrecentOnDeposite,date,period);
	case STOCKEXCHANGE:
		account = new StockAccount(PrecentOnDeposite,date,period);
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

void Account::withdrawal( int amount )
{
	float result;

	result = m_Account->withdrawal(amount);
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
	m_Account->Notify((result ? "the account were closed" : "the account is unable to close the account"));
}

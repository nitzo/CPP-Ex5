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

std::string Account::GetAccountStatus()
{
	string str;

	//TODO: fix this
//	str << "Account Type is " << m_Account->GetAccountType() << "(0 - 2 years, 1- family, 2 - stock market)" <<endl
//		<< "percent on deposit: " << m_Account->GetPrecent() << endl
//		<< "Year of creation: " << m_Account->GetDate() << endl
//		<< "Saving period: " << m_Account->GetPeriod() << endl
//		<< "The bank last massage: " << m_Account->GetLastMsg() << endl
//		<< "cash amount in the account: " << m_Account->getAmount() << endl
//		<< "The Account is " << (m_Account->IsClosed() ?  "closed" : "open") << endl;
	
	return str;
}

AccountImpl* Account::Factory( Account_Type type, int date, Period period, float PrecentOnDeposite )
{
	switch (type)
	{
	case TWOYEARS:
		return new TwoYearsAccount(PrecentOnDeposite,date,period);
	case FAMILY:
		return new FamilyAccount(PrecentOnDeposite,date,period);
	case STOCKEXCHANGE:
		return new StockAccount(PrecentOnDeposite,date,period);
	}
}

void Account::deposit( int amount )
{
	m_Account->deposit(amount);
	m_Account->Notify(amount <<" deposit to the account")
}

void Account::withdrawal( int amount )
{
	float result;

	result = m_Account->withdrawal(amount);
	m_Account->Notify(result << " withdrawal from the account");
}

void Account::depositStock( int amount )
{
	int result;

	result = m_Account->InvestInStockMarket(amount);
	m_Account->Notify(result << " invested in the stock market");
}

void Account::notify( string msg )
{
	m_Account->Notify(msg);
}

void Account::close()
{
	bool result;
	result = m_Account->Close();
	m_Account->Notify((result ? "the account were closed" : "the account is unable to close the account"));
}

#include "AccountImpl.h"
#include "Account.h"
#include <string>
#include <iostream>

using namespace std;

/*****************
 * CTORs and DTORs
 *****************/

AccountImpl::AccountImpl(Account_Type type,float percent, int date, Period period, int id)
{
	this->id = id;
	this->type = type;
	this->percent = percent;
	this->date = date;
	this->period = period;
	closed = false;
	this->amount = 0;
	lastMsg = "There is no messages from the bank";
}

AccountImpl::~AccountImpl(){

	cout << "Account " << id << " deleted";	
}

float AccountImpl::GetPrecent() const
{
	return percent;
}



/*********************
 * Member functions
 *********************/
int AccountImpl::GetDate() const
{
	return date;
}
Period AccountImpl::GetPeriod() const
{
	return period;
}

std::string AccountImpl::GetLastMsg() const
{
	return lastMsg;
}


bool AccountImpl::IsClosed() const
{
	return closed;
}


void AccountImpl::deposit( int sum )
{
	amount += sum;
}

float AccountImpl::withdraw( int sum )
{
	float tmp;
	//case withdrawal grater then the amount in the account
	if(amount < sum){
		tmp = amount;
		amount = 0;
	}else{
		tmp = (float)sum;
		amount -= sum;
	}
	return tmp;
}

void AccountImpl::Notify( string msg )
{
	lastMsg = msg;
}

int AccountImpl::GetAccountType() const
{
	return type;

}

float AccountImpl::getAmount() const
{
	return amount;
}

int AccountImpl::GetId() const
{
	return id;
}


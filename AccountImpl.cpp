#include "AccountImpl.h"
#include <string>

using namespace std;

AccountImpl::AccountImpl(int type,float percent, int date, Period period )
{
	this->type = type;
	this->percent = percent;
	this->date = date;
	this->period = period;
	closed = false;
	lastMsg = "There is no messages from the bank";
}

float AccountImpl::GetPrecent() const
{
	return percent;
}

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

float AccountImpl::withdrawal( int sum )
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

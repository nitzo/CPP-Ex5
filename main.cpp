//
//VirtualTau Notes:
// 1. mistake correction: "Bank sends message to all 3 years saving account owners to come to the bank for the meeting with clerk."
//
#include "Bank.h"
#include "Account.h"
#include <iostream>

int main (int argc, char** argv){

	int op = 0, date = 0, id, amount;
	int type;
	int period;
	float intrest;
	
	while (op != 8){
	
		cout << "Please select an operation to perform:" << endl;
		cout << "1 - Create an account and Attach to bank" << endl;
		cout << "2 - Print bank status" << endl;
		cout << "3 - Deposit into account " << endl;
		cout << "4 - Withdraw from account " << endl;
		cout << "5 - Invest in stock (Only if account is STOCKEXCHANGE, open no more than 5 years ago and saving period is TEN)" << endl;
		cout << "6 - Give family accounts 500 bonus" << endl;
		cout << "7 - Notify all accounts to come to bank" << endl;
		cout << "8 - Exit program" << endl;

		

		cin >> op;
		
		switch (op){

		case 1:

			cout << "Select Account type: " << endl;
			cout << TWOYEARS << " - Two years account" << endl;
			cout << FAMILY << " - Family account" << endl;
			cout << STOCKEXCHANGE << " - Stock Exchange account" << endl;

			cin >> type;

			cout << "Input Date: " << endl;

			cin >> date;

			cout << "Select Account period: " << endl;
			cout << THREE << " - Three years account" << endl;
			cout << SEVEN << " - Seven years account" << endl;
			cout << TEN << " - Ten years account" << endl;

			cin >> period;

			cout << "Input intrest: " << endl;

			cin >> intrest;


			Bank::Instance().createNewAccount(type, date, period, intrest);
			break;
		case 2:
			cout << Bank::Instance();
			break;
		
		
		case 3:

			cout << "Input account id to deposit to: " << endl;
			cin >> id;

			cout << "Input amount to deposit: " << endl;
			cin >> amount;

			Bank::Instance().deposit(id, amount);

			break;

		case 4:

			cout << "Input account id to withdraw from: " << endl;
			cin >> id;

			cout << "Input amount to withdraw: " << endl;
			cin >> amount;

			Bank::Instance().withdraw(id, amount);

			break;

		case 5:

			cout << "Input amount to invest: " << endl;
			cin >> amount;

			Bank::Instance().InvestInStockExchange(amount);
			break;
		case 6:

			Bank::Instance().GiveFamilyBonus();
			break;

		case 7:

			Bank::Instance().Notify();
			break;

		}

	}
}
	


#include "tBank_t.h"
#include "Account.h"
#include <iostream>

int main (int argc, char** argv){

	int op = 0;

	while (op != 3){
	
		cout << "Please select an operation to perform:" << endl;
		cout << "1 - Create an account and Attach to bank" << endl;
		cout << "2 - Print bank status" << endl;
		cout << "3 - Exit program" << endl;

		

		cin >> op;
		
		switch (op){

		case 1:
			break;
		case 2:
			cout << tBank_t::Instance();
			break;
		
		}


	}
	


	



}
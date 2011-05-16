#ifndef __TBANK_T_H__
#define  __TBANK_T_H__

#include "Subject.h"

//An object representing a bank.
//This object is a singleton and cannot be created more than once per program
class tBank_t : Subject {


public:

	tBank_t& Instance() {return bank;}

private:
		

	tBank_t();							//Private CTOR in order to disable instiatiation
	tBank_t(const tBank_t &bank);		//Prevent COPY
	tBank_t &operator=(tBank_t &bank);  //Prevent COPY

	
	static tBank_t bank;				//Singleton static object

	//Data Members

};

#endif
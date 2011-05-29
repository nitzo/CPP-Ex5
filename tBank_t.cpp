#include "tBank_t.h"

void tBank_t::Attach( Account* acc)
{
	m_accounts.push_back(acc);
}

void tBank_t::Detach( Account* acc)
{
	unsigned int i = 0;

	for (i = 0; i < m_accounts.size(); i++) 
		if (m_accounts[i] == acc) break; 

	m_accounts.erase(m_accounts.begin() + i); 
}

void tBank_t::Notify()
{
	
	for (unsigned i = 0; i < m_accounts.size(); i++){

		//TODO: implement condition
		/*if(true){
			(m_accounts[i])->Update(this);
		}*/
	}
}

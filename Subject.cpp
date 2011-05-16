#include "Subject.h"
#include "Observer.h"

//Attach obj to subject
void Subject::Attach (Observer* ob) { 
	m_observers.push_back(ob); 
} 

//Detach a specific observer from subject
void Subject::Detach (Observer* ob) { 
	unsigned int i = 0;

	for (i = 0; i < m_observers.size(); i++) 
		if (m_observers[i] == ob) break; 

	m_observers.erase(m_observers.begin() + i); 
} 

//Notify ALL of the observers about change in subject
void Subject::Notify () { 
	for (unsigned i = 0; i < m_observers.size(); i++) 
		(m_observers[i])->Update(this); 
}
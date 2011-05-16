#ifndef __SUBJECT_H__
#define  __SUBJECT_H__


#include <vector>

using namespace std;

class Observer;

class Subject {

public:
	virtual ~Subject() {}

    virtual void Attach(Observer*);
    virtual void Detach(Observer*);
    virtual void Notify();

protected:

	Subject() {}

private:

    vector<Observer*> m_observers;	//Hold All observers
};

#endif
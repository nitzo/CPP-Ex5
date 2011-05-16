#ifndef __OBSERVER_H__
#define  __OBSERVER_H__

#include <vector>

using namespace std;

class Subject;

class Observer {

public:

	virtual			~Observer() {}
    virtual void	Update(Subject* ChngSubject) = 0;

protected:

	Observer() {}

	Subject* sbj;

};

#endif
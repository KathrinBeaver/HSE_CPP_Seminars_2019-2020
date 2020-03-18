#include <iostream>
#include <string>

#ifndef __Destr__
#define __Destr__

class ProtectedDestrBase {
public:
	ProtectedDestrBase() {
		std::cout << "Base was created \n";
	};

	virtual void kill() {
		ProtectedDestrBase::~ProtectedDestrBase();
	};

protected:
	virtual ~ProtectedDestrBase() {
		std::cout << "~Base() \n";
	};
};

class Derived : public ProtectedDestrBase {
public:
	Derived() {
		std::cout << "Derived was created \n";
	};
	
	~Derived() {
		std::cout << "~Derived() \n";
	};	
};
#endif
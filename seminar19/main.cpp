#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include <typeinfo>
#include <vector>

#include "Singleton.cpp"
#include "SingletonBasic.cpp"

#include "Building_v1.cpp"
#include "Building_v2.cpp"
#include "Circus_v1.cpp"
#include "Circus_v11.cpp"
#include "Circus_v2.cpp"
#include "Clown.cpp"
#include "Rector.cpp"
#include "University.cpp"

//using custom deleter for Buildings...
class Deleter {
public:
	void operator() (Building_v1* ptr) {
		std::string realObject = typeid(*ptr).name();
		std::cout << "From unique_ptr deleter: deleting ptr of Class: " << realObject << std::endl;
		if (realObject.find("Circus") != -1) {
			delete dynamic_cast<Circus_v1*>(ptr);
		}
		else if (realObject.find("University") != -1) {
			delete dynamic_cast<University*>(ptr);
		}
		//if all cases fail - then this is a building
		else {
			delete ptr;
		}
	}
};

void example1() {
	//If destructor is not virtual we still can use smart ptr with Deleter (class or function)
	//Deleter del;
	
	//std::unique_ptr<Building_v1> circus = std::unique_ptr<Building_v1>(new Circus_v1());

	//std::unique_ptr<Building_v1, Deleter> circus = 
	//	std::unique_ptr<Building_v1, Deleter>(new Circus_v1, del);

	//Alternative without smart ptr:
	//Building_v1* circus1 = new Circus_v1();    
	//delete circus1;
	//delete (Circus_v1*)circus1;    

	//If destructor is virtual the right destructor is chosen in runtime
std::unique_ptr<Building_v2> circus2 = std::unique_ptr<Building_v2>(new Circus_v11());
}

void example2() {
	std::vector<std::unique_ptr<Building_v2>> town;
	{
		Clown cl("Jumbo");
		town.push_back(std::unique_ptr<Building_v2>(new Circus_v11(&cl)));
	}
	town.push_back(std::unique_ptr<Building_v2>(new University));

	town[0]->GetInfo();
	static_cast<Circus_v11*>(town[0].get())->PrintClownStatus();
}

void example2_1() {
	std::vector<std::unique_ptr<Building_v2>> town;
	{
		std::shared_ptr<Clown> cl = std::shared_ptr<Clown>(new Clown("Jumbo"));
		town.push_back(std::unique_ptr<Building_v2>(new Circus_v2(cl)));
	}
	town.push_back(std::unique_ptr<Building_v2>(new University));

	town[0]->GetInfo();
	((Circus_v2*)town[0].get())->PrintClownStatus();
}


class A {
public:
	virtual int func() const {
		return 0;
	}

	virtual ~A() = 0;
};

class B : A {
public:
//	int func() override {
	int func() const {
		return 1;
	}
	
};

class C : B {};


int main() {

//	A a;
//	A* a = new A();
//	B b;
//	C c;

	//example1(); // deleters of sub classes
	//example2(); // base class and lifecycle managmnent
	//example2_1();

	//Singleton& s1 = Singleton::Instance();
	//Singleton& s2 = Singleton::Instance();
	SingletonBasic* s2 = SingletonBasic::instance();
	SingletonBasic* s3 = SingletonBasic::instance();

	system("pause");
	return 0;
}
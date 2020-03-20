#include "Building_v2.cpp"
#include "Rector.cpp"

#ifndef __University__
#define __University__

//University is inherited from class Building
class University : public Building_v2 {
private:
	Rector rector;
public:
	//Would anything change if we delete ":rector()" ?
	University() : rector() {		
		std::cout << "Creating a University. Rector is " << rector.GetInfo() << "\n";
	};
	~University() {
		std::cout << "~Destroying a University. Rector was " 
			<< rector.GetInfo() << "\n";
	}
};

#endif
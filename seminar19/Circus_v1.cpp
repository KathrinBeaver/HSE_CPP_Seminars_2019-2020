#include <iostream>
#include <string>

#include "Building_v1.cpp"
#include "Clown.cpp"

#ifndef __Circus_v1__
#define __Circus_v1__

//Circus is inherited from class Building_v1 and aggregates class Clown
class Circus_v1 : public Building_v1 {
private:
	Clown* clown;

public:
    Circus_v1() {
		clown = nullptr;
        std::cout << "Constructing a Circus\n";
    };

    Circus_v1(Clown* _clown) : Circus_v1() {
        clown = _clown;
    }

    void SetClown(Clown* _clown) {
        clown = _clown;
    }

	void PrintClownStatus() {
        if(clown != nullptr) {
            std::cout << "Clown exists\n";
            clown->PrintName();
        }
        else {
            std::cout << "Clown in NULL\n";
        }
    }
    
	~Circus_v1() {
        if(clown != nullptr) clown->PrintName();
        std::cout << "~Destroying a Circus \n";
    }
};

#endif

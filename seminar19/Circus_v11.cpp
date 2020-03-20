#include <iostream>
#include <string>

#include "Building_v2.cpp"
#include "Clown.cpp"

#ifndef __Circus_v11__
#define __Circus_v11__

//Circus is inherited from class Building_v2 and aggregates class Clown
class Circus_v11 : public Building_v2 {
private:
    Clown* clown;
public:
    Circus_v11() {
		clown = nullptr;
        std::cout << "Constructing a Circus\n";
    };
    
	Circus_v11(Clown* _clown) : Circus_v11() {
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

    ~Circus_v11() {
        if(clown != nullptr) clown->PrintName();
		clown = nullptr;
        std::cout << "~Destroying a Circus \n";
    }
};

#endif

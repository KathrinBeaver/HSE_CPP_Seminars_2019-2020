#include <iostream>
#include <memory>
#include <string>

#include "Building_v2.cpp"
#include "Clown.cpp"

#ifndef __Circus_v2__
#define __Circus_v2__

// 2nd try
//Circus is inherited from class Building_v2 and aggregates class Clown as shared_ptr
class Circus_v2 : public Building_v2 {
private:
    std::shared_ptr<Clown> clown;
public:
    Circus_v2() {
		clown = nullptr;
        std::cout << "Constructing a Circus\n";
    };
    
	Circus_v2(std::shared_ptr<Clown>& _clown) : Circus_v2() {
        clown = _clown;
    }
    
	void SetClown(std::shared_ptr<Clown>& _clown) {
        this->clown = _clown;
    }

    void PrintClownStatus() const {
        if(clown != nullptr) {
            std::cout << "Clown exists. Hey, Clown, who a' u? ";
            clown->PrintName();
        }
        else {
            std::cout << "Clown in NULL\n";
        }
    }

    ~Circus_v2() {
        if(clown != nullptr) clown->PrintName();
        std::cout << "~Destroying a Circus \n";
    }
};

#endif

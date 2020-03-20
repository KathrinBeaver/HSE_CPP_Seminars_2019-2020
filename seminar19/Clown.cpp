#include <iostream>
#include <string>

#ifndef __Clown__
#define __Clown__

class Clown {
private:
    std::string nickname;

public:
    Clown(std::string _nickname = "") : nickname(_nickname) {
        std::cout << "Creating a Clown\n";
    }

    Clown(const Clown& other) {
        std::cout << "Creating a Clown as a copy\n";
        this->nickname = other.nickname;
    }

	~Clown() {	
		nickname = "";
        std::cout << "~Destroying a Clown\n";	
    }
    
	void PrintName() const {
        std::cout << "I am " << nickname << "\n";
    }
};

#endif

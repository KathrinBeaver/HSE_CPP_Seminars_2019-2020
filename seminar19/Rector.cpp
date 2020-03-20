#include <iostream>
#include <string>

#ifndef __Rector__
#define __Rector__

class Rector {
private:
    std::string name;

public:
    Rector(std::string _name = "Kuzminov") : name(_name) {
        std::cout << "Rector constructor\n";
    }

    ~Rector() {
        std::cout << "~Destroying a Rector\n";
    }

    std::string GetInfo() const {
        std::string retStr = name + "\n";
        return retStr;
    }
};

#endif

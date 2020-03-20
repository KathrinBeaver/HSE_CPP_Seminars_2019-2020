#include <iostream>

#ifndef __Building_v2__
#define __Building_v2__

class Building_v2 {
private:
    int xSize;
    int ySize;
    int height;
public:
    Building_v2() : xSize(0), ySize(0), height(0) {
        std::cout << "Constructing a Building\n";
    }
    
    Building_v2(int x, int y, int h) {
        this->xSize = x;
        this->ySize = y;
        this->height = h;
    }
    
    virtual int GetCost() {
        return xSize * ySize * height * 10;
    }
    
    virtual void GetInfo() {
        std::cout << "xSize=" << xSize << " ySize=" << ySize << "\n";
    }
    
public:
    virtual ~Building_v2() {
        std::cout << "~Destructing a Building\n";
    };
};
#endif

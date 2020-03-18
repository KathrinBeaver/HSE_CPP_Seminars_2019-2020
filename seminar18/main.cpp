#include <iostream>
#include <string>
#include <exception>
#include "ProtectedDestr.cpp"

class C {
private:
    int* value;
public:
    C(int val = 0) {
        value = new int(val);
        std::cout << "Constructing C. Value = " << *this->value << "\n";
    }
    ~C() {
		std::cout << "~Destructing Value = " << *this->value << "\n";
        delete value;
        std::cout << "~Destructing C\n";
    }
};

void example0() {
	//ProtectedDestrBase base;
	ProtectedDestrBase* basePtr = new ProtectedDestrBase();
	//delete basePtr;
	basePtr->kill();

	Derived child;

	Derived* childPtr = new Derived();
	delete childPtr;
}

void example1() {
	const int N = 50;
	int* placementMemory = new int[N];
	std::cout << "Left border = " << placementMemory << "\n";
	std::cout << "Right border = " << placementMemory + N - 1 << "\n\n";

	int* newArray = placementMemory + 10;
	//delete[] newArray;
	std::cout << "Left border = " << newArray << "\n";
	std::cout << "Right border = " << newArray + 9 << "\n\n";

	int* newArray1 = new (placementMemory) int[10]; // initialises memory, not allocates
	std::cout << "Left border = " << newArray1 << "\n";
	std::cout << "Right border = " << newArray1 + 9 << "\n\n";

	int* newArray2 = new (placementMemory + 10) int[10];
	std::cout << "Left border = " << newArray2 << "\n";
	std::cout << "Right border = " << newArray2 + 9 << "\n";

	//is it good?
	Derived* derived = new (placementMemory + 20) Derived();
	//delete derived;
	derived->~Derived();

	delete[] placementMemory;
}

void example2() {

	const int SIZE = 2;

	std::cout << sizeof(C) * SIZE << " bytes\n";

	void* memory = ::operator new(sizeof(C) * SIZE); // Operator new

	C* arrayOfObjC = static_cast<C*>(memory); // Cast to the desired pointer type
	
	std::cout << "Memory allocated but NOT assigned.\n";
	
	for (size_t i = 0; i < SIZE; i++) {
		new (arrayOfObjC + i) C(i); // Placement new
	}

	// Removing data
	for (size_t i = 0; i < SIZE; i++) {
		(arrayOfObjC + i)->~C();  // Destructing data, no deallocation
	}
	
	//delete arrayOfObjC;
	::operator delete(arrayOfObjC);  // Deletes memory but doesn't call destructor!	
}

int main() {
    //example0();   
	//example1();
	example2();
	
	system("pause");
	return 0;
}
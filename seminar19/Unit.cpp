#include <string>

class Part {
	std::string name;
};

class Unit {
	std::string name;
	Part part;

public:
	Unit() : part() { // конструктор целого
	}
};


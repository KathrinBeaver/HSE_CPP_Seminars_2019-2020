#include <exception>
#include <iostream>
#include <string>


class Point {

private:
	static int count;
	static int realCount;
	int x;
	int y;

public:
	const int id;

	Point() : id(++count) {
		++realCount;
		std::cout << "!!! new object Point() id = " << id << "\n";
		throw 42;
	}

	Point(int x, int y) : id(++count) {
		++realCount;
		this->x = x;
		this->y = y;
		std::cout << "!!! new object Point(x, y) id = " << id << "\n";
	}

	// конструктор копирования
	Point(const Point& other) : id(++count) {
		++realCount;
		this->x = other.x;
		this->y = other.y;
		std::cout << "!!! new copy object Point id = " << id << "\n";
	}

	Point& operator = (const Point& other) {
		this->x = other.x;
		this->y = other.y;
		std::cout << "!!! operator = (const Point&) " << id << " " << other.id << "\n";
		return *this;
	}

	~Point() {
		--realCount;
		std::cout << "!!! delete object Point() id = " << id << "\n";
	}

	static int getRealCount() {
		return realCount;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	void printInfo() {
		std::cout << "(" << this->getX() << ", " << this->getY() << ")\n";
	}
};

int Point::count = 0;
int Point::realCount = 0;

/* Function 1: 1 / (2  - sqrt(x)) */
float function1(float x) {
    if(x < 0) {
        throw std::string("Square root of negative value");
    }
    float res = sqrt(x);
    if(2 - res == 0) {
        throw 0xFF;
    }
    return 1 / (2 - res);
}

/* Function 2: 1  / ((6 - x) * sqrt(x - 1)) */
double function2(int x) {
    if ((x == 6) || (x == 1)) {
        throw std::logic_error("Div by zero");
    }
    if (x < 1) {
        throw std::string("Square root of negative value");
    }
    return 1 / ((6 - x) * sqrt(x - 1));
}

void example1() {
    try {
        float res = function1(-1);
        std::cout << "Result 1 = " << res << "\n";
    }
    catch(int e) {
        std::cout << "Error code: " << e << "\n";
    }
    catch(std::string e) {
        std::cout << e << "\n";
    }
    try {
        double res = function2(1);
        std::cout << "Result of the 2nd function = " << res << "\n";
    }
    catch(int e) {
        std::cout << "Error code: " << e << "\n";
    }
    catch(std::logic_error e) {
        std::cout << e.what() << "\n";
    }
	catch (const std::exception& err)
	{
		std::cout << "Exception!!!" << std::endl;
	}
    catch(...) {/* Ловим все возможные исключения*/
        std::cout << "ERROR!!! " << std::endl;
    }

}

int main() {
    
	Point p1;

	//example1();

	/*
	try {
		int a = 0;
		int h = 1 / a;
		std::cout << h;
	}
	catch (...) {
		std::cout << "Error div by 0";
	}
	*/

	/*
	try {
		float a = 0;
		float h = 1 / a;
		std::cout << h;
	}
	catch (...) {
		std::cout << "Error div by 0";
	}
	*/

	system("pause");  
}
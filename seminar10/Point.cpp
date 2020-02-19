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

	void printInfo()  {
		std::cout << "(" << this->getX() << ", " << this->getY() << ")\n";
	}

	// префиксный ++
	Point& operator ++ () {
		this->x++;
		this->y++;
		return *this;
	}

	// постфиксный ++
	Point operator ++ (int) {				
		Point tmp(*this);			
		++x;
		++y;    
		return tmp;
	}

	Point operator + (const Point& other) {		
		Point tmp (x + other.x, y + other.y);		
		return tmp;
	}

	// Операция сложения сложения с числом
	Point operator + (int k) {		
		Point tmp (x + k, y + k);
		return tmp;
	}
};

int Point::count = 0;
int Point::realCount = 0;
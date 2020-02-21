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
		this->x = 1;
		this->y = 1;
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

	// move-конструктор
	Point(Point&& other) : id(++count) {  // && - это rvalue-ссылка, по которой можно передать временный объект
		++realCount;
		std::cout << "!!! move Point(Point&&) " << id << " " << other.id << "\n";
		x = std::move(other.x);
		y = std::move(other.y);			
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

	static int GetRealCount() {
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

	void PrintInfo() {
		std::cout << "(" << this->getX() << ", " << this->getY() << ")\t";
	}
};

int Point::count = 0;
int Point::realCount = 0;
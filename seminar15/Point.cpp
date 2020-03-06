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
		std::cout << "New object Point() id = " << id << "\n";
	}

	Point(int x, int y) : id(++count) {
		++realCount;
		this->x = x;
		this->y = y;
		std::cout << "New object Point(x, y) id =" << id << "\n";
	}

	Point(const Point& other) : id(++count) {
		++realCount;
		this->x = other.x;
		this->y = other.y;
		std::cout << "New copy object Point id = " << id << "\n";
	}

	Point& operator = (const Point& other) {
		this->x = other.x;
		this->y = other.y;
		std::cout << "Operator = (const Point&) " << id << " " << other.id << "\n";
		return *this;
	}

	~Point() {
		--realCount;
		std::cout << "Delete object Point() id = " << id << "\n";
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
		std::cout << "(" << this->getX() << ", " << this->getY() << ")\n";
	}
};
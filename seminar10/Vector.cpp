#include <string>
#include "Point.cpp"

class Vector {

private:
	Point p1;		
	Point p2;

public:

	Vector(const Point& p1, const Point& p2) : p1(p1), p2(p2) {
		std::cout << "!!! New Vector" << "\n";
	}

	~Vector(){
		std::cout << "!!! Destructing Vector" << "\n";
	}

	Point getP1() const {
		return p1;
	}

	Point getP2() const {
		return p2;
	}

	void setP1(const Point& p1) {
		this->p1 = p1;
	}

	void setP2(const Point& p2) {
		this->p2 = p2;
	}

	void printInfo() {
		std::cout << "(" << p1.getX() <<  ", " << p1.getY() <<  ") - (" << p2.getX() << ", " << p2.getY() << ")\n";
	}

	void printNormalInfo() {
		std::cout << "{" << p2.getX() - p1.getX() << ", " << p2.getY() - p1.getY() << "}\n";
	}

	Vector& operator * (int k) {
		Point newP2(this->p1.getX() + (this->p2.getX() - this->p1.getX()) * k, 
					this->p1.getY() + (this->p2.getY() - this->p1.getY()) * k);
		p2 = newP2;
		return *this;
	}

	int operator * (const Vector& other) {
		// добавить пол¤ дл¤ нормализованного представлени¤ вектора
		// реализовать функцию скал¤рного произведени¤ векторов
		// упростить остальные методы
		return 0;
	}
};
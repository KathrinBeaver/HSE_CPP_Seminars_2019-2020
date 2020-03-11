#include <algorithm> 
#include <cstring>
#include <iostream>
#include <math.h>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>

# define PI 3.14159

class Currency {
private:
	float ammount;
	const float kursToUsd;
public:
	Currency(float sum, float kurs) : kursToUsd(kurs), ammount(sum) {}
	
	// Variant 1 - not working
	// Этот "operator +" является членом класса, у него есть доступ к private, но он принимает другое число параметров
	/*
	float operator + (Currency curr1, Currency curr2) {
		return curr1.ammount + curr2.ammount;
	}
	*/

	// Variant 2 - working
	// Этот "operator +" является членом класса, у него есть доступ к private, он принимает правильное число параметров
	float operator + (Currency otherCurr) {
		return this->ammount * this->kursToUsd + otherCurr.ammount * otherCurr.kursToUsd;
	}

	// Variant 3 - working
	// Этот "operator +" не является членом класса, но у него есть доступ к private
	// Доступа к *this - нет
	friend float operator + (Currency curr1, Currency curr2) {
		return curr1.ammount * curr1.kursToUsd + curr2.ammount * curr2.kursToUsd;
	}
};

// Variant 4 - not working
// Этот "operator +" не является членом класса и у него нет доступа к private
/*
float operator + (Currency curr1, Currency curr2) {
	return curr1.ammount * curr1.kursToUsd + curr2.ammount * curr1.kursToUsd;
}
*/

// Как переписать последний вариант и класс, чтобы он работал, не нарушая принципов ООП?

class Shape {
protected:
    int x, y;
public:
    Shape(int x = 0, int y = 0) : x(0), y(0) {};
    void virtual display() const {
    //void display() const {
        std::cout << "Its a basic Shape, Area = 0; (" << x << "," << y << ")\n";
    }

    float virtual getArea() const {
    //float getArea() const {
        return 0.;
    }
};

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int r = 0) : Shape(), radius(r) {};
	
    void display() const {
        std::cout << "Its a Circle, Area = " << getArea() << " (" << x << "," << y << ")\n";
    }

	void testCircleFunc() {

	}

    float getArea() const {
        return static_cast<float>(PI * radius * radius);
    }
};

class Square : public Shape {
private:
    int side;
public:
    Square(int a = 0) : Shape(), side(a) {};

    void display() const {
        std::cout << "Its a Square, Area = " << getArea() << " (" << x << "," << y << ")\n";
    }
    float getArea() const {
        return static_cast<float>(side * side);
    }
};

int main() {

	Currency curr1(100, 2);
	Currency curr2(100, 1);
	// Так не работает: определено 2 "оператора +"
	//std::cout << curr1 + curr2;
	std::cout << operator+(curr1, curr2) << std::endl;
	std::cout << curr1.operator+(curr2) << std::endl;

    Shape p = Shape();
    Circle c = Circle(3);	
	Shape sh = c;
    //Circle c = Shape(); // error: Can't initialize a child using Parent	

    //What will be printed?
    p.display();
    c.display();

    Shape c1 = Circle(4);   
	c1.display();
    //((Circle)(c1)).display(); // error: Can't convert data from Parent to Child

    Circle c2 = Circle(5);
    Shape& p1 = c2; // Ok
    c2.display();
    p1.display(); // "Its a Circle, Area..."

    std::cout << "\n******\n" << std::endl;
    std::cout << typeid(p1).name() << "\n";
    std::cout << "\n******\n" << std::endl;

	/*
	std::vector<Shape*> figures;
	figures.push_back(new Circle(1));
	figures.push_back(new Circle(2));
	figures.push_back(new Square(1));
	figures.push_back(new Square(2));	
	*/

    std::vector<std::unique_ptr<Shape>> figures;
    figures.push_back(std::make_unique<Circle>(1));
    figures.push_back(std::make_unique<Circle>(2));
    figures.push_back(std::make_unique<Square>(1));
    figures.push_back(std::make_unique<Square>(2));
    
    for(auto& fig : figures) {
        fig->display();
        std::cout << typeid(*fig).name() << "\n";
    }
	
    std::cout << "\n******\n" << std::endl;
    std::sort(figures.begin(), figures.end(), 
		[](auto& a, auto& b) {return a->getArea() < b->getArea();});
    
	for(auto& fig : figures) {
        fig->display();       
    }

	// Memory leak?

	system("pause");
	return 0;
}
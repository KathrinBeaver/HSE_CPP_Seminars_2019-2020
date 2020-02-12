#include <iostream>
#include <fstream>

#include "binary_search.cpp"
#include "left_right.cpp"

using namespace std;

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(x) {}
};

ostream& operator<<(ostream& out, const Point& p) {
	out << p.x << " " << p.y;
	return out;
}

template<class T>
// Сейчас одно и тоже, раньше typename - только для простых типов,
// class - для классов
// template<typename T>
T test(const T& t) {
	cout << t << endl;
	return t;
}

int main() {	

	//leftAndRight();	

	//binaryApproximateSearch();
    
	test(111);

	Point point(2, 3);
	test(point);

	system("pause");
    return 0;
}
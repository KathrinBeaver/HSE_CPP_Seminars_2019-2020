#include <iostream>
#include "Vector.cpp"

int main() {
	//{
		Point p1;
		Point p2 = p1;

		p1 = p2;

		Point p3, p4;
		p3.setX(1);
		p3.setY(1);

		p4.setX(2);
		p4.setY(2);
			

		std::cout << "sizeof(Point) = " << sizeof(Point) << "\n";		

		Point point1(3, 1), point2(5, 2), point3(0, 0);

			/*
			std::cout << "\n---------------- Point ++ ---------------- \n";

			point1.printInfo();
			point2.printInfo();
			point3.printInfo();

			(point3 + point1++).printInfo();
			point1.printInfo();

			(point3 + ++point1).printInfo();
			point1.printInfo();
			*/

			/*	std::cout << "\n---------------- ++ ---------------- \n";

				Vector vect(point1, point2);

				vect.printInfo();
				vect.printNormalInfo();

				vect = vect * 2;

				vect.printInfo();
				vect.printNormalInfo();

			*/

		std::cout << "Point real count = " << Point::getRealCount() << "\n";
//	}
	system("pause");
}
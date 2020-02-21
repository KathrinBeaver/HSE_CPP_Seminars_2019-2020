#include <iostream>
#include <vector>

#include "Line.cpp"
#include "Point.cpp"

using namespace std;

void f(int x) {
	cout << "x = " << x << "\n";
}

void example0() {
	int b = 7, a = 5;
	int &p = a;
	cout << a << ' ' << p << endl;
	a = 6;
	cout << a << ' ' << p << endl;
	p = b;
	cout << a << ' ' << p << endl;
	cout << &a << ' ' << &p << endl;
}

/* Ссылки на переменные */
void example1() {

	int x = 111;

	cout << "x = " << x << "\n";
	cout << "&x = " << &x << "\n";
	
	int& ref = x;

	cout << "ref = " << ref << "\n";
	cout << "&ref = " << &ref << "\n";

	int y = 222;

	cout << "y = " << y << "\n";
	cout << "&y = " << &y << "\n";
	cout << "\n";

	//&ref = &y; // Ошибка компиляции: ссылку нельзя переопределять
	ref = y;
	y = 333;

	cout << "ref = " << ref << "\n";
	cout << "&ref = " << &ref << "\n";
	cout << "x = " << x << "\n";
	cout << "&x = " << &x << "\n";
	cout << "y = " << y << "\n";
	cout << "&y = " << &y << "\n";
	cout << "\n";
}

/* Ссылки на функции */
void example2() {
	void(&rf) (int) = f;
	f(123);
	rf(123);
	cout << "\n";
}

/* Указатели */
void example3() {

	int xx = 111;

	cout << "xx = " << xx << "\n";
	cout << "&xx = " << &xx << "\n";
	cout << "\n";

	int* ptr = &xx;

	cout << "ptr = " << ptr << "\n";
	cout << "*ptr = " << *ptr << "\n";
	cout << "xx = " << xx << "\n";
	cout << "&xx = " << &xx << "\n";
	cout << "\n";

	int yy = 222;
	ptr = &yy;
	*ptr = 333;

	cout << "ptr = " << ptr << "\n";
	cout << "*ptr = " << *ptr << "\n";
	cout << "xx = " << xx << "\n";
	cout << "&xx = " << &xx << "\n";
	cout << "yy = " << yy << "\n";
	cout << "&yy = " << &yy << "\n";
	cout << "\n";

	ptr = nullptr;
	//cout << "*ptr = " << *ptr << "\n"; //  Ошибка при исполнении

	if (ptr != nullptr) {
		cout << *ptr << "\n";
	}
}

/* Размеры указателей */
void example4() {
	long long a = 0;
	long long& ref = a;
	ref = 10;

	cout << "a = " << a << ", size = " << sizeof(a) << "\n";     // У меня: 8
	cout << "ref = " << ref << ", size = " << sizeof(ref) << "\n";	// У меня: 8
	cout << "&a = " << &a << ", size = " << sizeof(&a) << "\n";
	cout << "&ref = " << &ref << ", size = " << sizeof(&ref) << "\n";  // У всех для x86: 4 - это адрес, он равен 4 байтам	
}

/* Арифметика указателей */
void example5() {

	int a[10];

	for (size_t i = 0; i < 10; ++i) {
		a[i] = i;
	}

	cout << "a = " << a << ", size=" << sizeof(a) << "\n";
	cout << "*a = " << *a << "\n";
	cout << "&a[0] = " << &a[0] << "\n";
	cout << "a[0] = " << a[0] << "\n";
	cout << "\n";

	cout << "a + 1 = " << a + 1 << "\n";
	cout << "*(a + 1) = " << *(a + 1) << "\n";
	cout << "&a[1] = " << &a[1] << "\n";
	cout << "a[1] = " << a[1] << "\n";
	cout << "\n";
}

/* Динамическое выделение памяти */
void example6() {

	int b = 10;
	int* ptr1 = &b;
	b = 20;

	cout << "b =  " << b << "\n";
	cout << "&b =  " << &b << "\n";
	cout << "ptr =  " << ptr1 << "\n";
	cout << "*ptr =  " << *ptr1 << "\n";
	cout << "\n";

	int* ptr2 = new int(b);
	b = 30;

	cout << "b =  " << b << "\n";
	cout << "&b =  " << &b << "\n";
	cout << "ptr1 =  " << ptr1 << "\n"; // Адрес ptr1 - из стека
	cout << "*ptr1 =  " << *ptr1 << "\n"; // 30
	cout << "ptr2 =  " << ptr2 << "\n";  // Адрес ptr2 - из "кучи"
	cout << "*ptr2 =  " << *ptr2 << "\n"; // 20, как и было
	cout << "\n";

	*ptr2 = 40;

	cout << "b =  " << b << "\n";
	cout << "&b =  " << &b << "\n";
	cout << "ptr1 =  " << ptr1 << "\n"; // Адрес ptr1 - из стека
	cout << "*ptr1 =  " << *ptr1 << "\n"; // 30
	cout << "ptr2 =  " << ptr2 << "\n";  // Адрес ptr2 - из "кучи"
	cout << "*ptr2 =  " << *ptr2 << "\n"; // 20, как и было
	cout << "\n";

	delete ptr2; // Для всего, чего мы выделяли память через new, нужно освобождать её вручную
}

/* Динамическое создание объектов */
void example7() {

	Point* point1 = new Point(1, 1);

	cout << "sizeof(Point) = " << sizeof(Point) << "\n";
	cout << "sizeof(point1) = " << sizeof(point1) << "\n";
	cout << "sizeof(*point1) = " << sizeof(*point1) << "\n";

	delete point1;

	cout << "\n";
}

void printArray(int** array, int size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

/* Динамические массивы чисел */
void example8(int n) {

	int** matrix = new int*[n];

	for (size_t i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (size_t j = 0; j < n; j++) {
			matrix[i][j] = i * j;
		}
	}

	cout << "sizeof(matrix pointer) = " << sizeof(matrix) << "\n";
	cout << "sizeof(matrix) = " << sizeof(matrix[0][0]) * n * n << "\n\n";

	printArray(matrix, n);

	for (size_t i = 0; i < n; i++) {
		delete[] matrix[i];
	}

	// очистить всю память и обнулить указатель
	delete[] matrix;
	matrix = nullptr;
}

void printArray(Point*** array, int size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			//array[i][j]->PrintInfo();
			(*array[i][j]).PrintInfo();
		}
		cout << "\n";
	}
	cout << "\n";
}

/* Динамические массивы объектов*/
void example9(int n) {

	Point*** points = new Point**[n];
	for (size_t i = 0; i < n; i++) {
		points[i] = new Point*[n];
		for (size_t j = 0; j < n; j++) {
			points[i][j] = new Point(i, j);
		}
	}

	cout << "sizeof(points) = " << sizeof(points) << "\n";
	cout << "sizeof(matrix) = " << sizeof(*points[0][0]) * n * n << "\n\n";

	printArray(points, n);

	//delete points[1][1];

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			delete points[i][j];
		}
		delete[] points[i];
	}

	// очистить память и обнулить указатель
	delete[] points;
	//points = nullptr;
}

/* Утечка памяти */
void example10() {
	while (1) {
		new Point(0, 0);
		//Point(0, 0);
	}
}

/* move constructor */
void example11() {		
	Line line1 = Line();
	Line line2(line1);
	line1.PrintInfo();
	line2.PrintInfo();

	Line line3 = line2;
	//Line line3 = move(line2);
	
	line1.PrintInfo();
	line2.PrintInfo();	
	line3.PrintInfo();			
}

/* move = */
void example12() {
	Line line1 = Line();
	Line line2;
	
	//line2 = line1;
	line2 = move(line1);

	line1.PrintInfo();
	line2.PrintInfo();	
}

int main() {

	//example0();
	//example1();
	//example2();
	example3();
	//example4();
	//example5();
	//example6();
	//example7();
	//example8(5);
	//example9(2);
	//example10();
	//example11(); // move constructor
	//example12(); // move =

	system("pause");
	return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void example0() {
	float a = 123456789;
	float b = 123456788;
	std::cout << std::fixed << a << std::endl;    // ? 
	std::cout << std::fixed << b << std::endl;   // ?? 
	std::cout << "a - b = " << a - b << std::endl; // ??? 
	std::cout << "a  b = " << a + b << std::endl;

	double c = 123456789;
	double d = 123456788;
	std::cout << std::fixed << c << std::endl;    // ? 
	std::cout << std::fixed << d << std::endl;   // ?? 
	std::cout << "c - d = " << c - d << std::endl; // ??? 
}

/* Пример 1. Вектор и работа с ним.  */
void example1() {
	//  вектор -  "умный" динамический массив данных #(Py Vs C++) Массив - это НЕ список!
	// #include <vector>
	vector<int> v1; // объявили вектор, сейчас вектор пустой.
	vector<long> v2 = { 1, 3, 4 }; // или так - статическая инициализация
	v1.push_back(42); //положить в конец
	v1.push_back(41); //положить в конец

	// печать вектора через цикл foreach
	for (auto i : v2) {
		cout << i << endl;
	}
	// вывод вектора через перебор значений
	for (size_t i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << endl;  // так
		cout << v1[i] << endl; // или так
	}
}

/* Задача 1. Для двумерного массива рассчитать сумму всех его четных и
нечетных элементов */
void example2() {
	vector<vector<int>> matrix;
	size_t size = 0;
	cout << "Enter size (n*n): ";
	cin >> size;
	int sumOdd = 0;
	int sumEven = 0;
	for (size_t i = 0; i < size; ++i) {
		matrix.push_back(vector<int>());
		for (size_t j = 0; j < size; ++j)
		{
			matrix.at(i).push_back(rand() % 10); // rand() - random number from 0 to RAND_MAX
			cout << matrix.at(i).at(j) << "\t";
			if (matrix[i][j] % 2 == 0) {
				sumEven += matrix[i][j];
			}
			else {
				sumOdd += matrix[i][j];
			}
		}
		cout << "\n";
	}
	cout << "Sum of even elements: " << sumEven << endl;
	cout << "Sum of odd elements: " << sumOdd << endl;
}

/* Задача 2.  Для двумерного массива отсортировать элементы каждой строки,
вывести их в обратном порядке */
void example3() {
	size_t size;
	cout << "Enter size (n*n): ";
	std::cin >> size;
	std::vector<std::vector<int>> matrix;
	matrix.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		matrix.push_back(std::vector<int>());
		//matrix.back().reserve(size);
		for (size_t j = 0; j < size; ++j) {
			matrix.back().push_back(rand() % 10);
			std::cout << matrix.back().back() << "\t";
			//std::cout << matrix.at(i).at(j) << "\t";
		}
		std::cout << "\n";
	}
	
	// Sort row elements
	std::cout << "\n\n Sorted:\n";
	for (size_t i = 0; i < size; ++i) {
		std::sort(matrix.at(i).begin(), matrix.at(i).end());
		for (size_t j = 0; j < size; ++j) {
			std::cout << matrix.at(i).at(j) << "\t";
		}
		std::cout << "\n";
	}

	// Reverse row elements
	std::cout << "\n\n Reversed:\n";
	for (size_t i = 0; i < size; ++i) {
		std::reverse(matrix.at(i).begin(), matrix.at(i).end());
		for (size_t j = 0; j < size; ++j) {
			std::cout << matrix.at(i).at(j) << "\t";
		}
		std::cout << "\n";
	}
}

/* Пример 2. Условия
*/
void example4() {
	int a = -4;

	cout << (-5 < a) << endl;
	cout << (-5 < a < -1) << endl;

	if (-5 < a < -1) {
		std::cout << "!!!" << endl;
	}

	char ch = 'A';

	if (ch > 0) {
		std::cout << ch << " > 0" << endl;
	}
}

/* Пример 3. switch
*/
void example5() {

	int number = 1;
	//int number = 5;

	switch (number) {
		case 0:
			cout << "number = 0" << endl;
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			cout << "number from 1 to 5" << endl;
			break;
		case 6:
			cout << "number = 6" << endl;
			break;
		case 7:
			cout << "number = 7" << endl;
			break;
		default:
			cout << "unknown" << endl;
	}
}

int main() {

	/*

	cout << "int - " << sizeof(int) << endl;
	cout << "unsigned int - " << sizeof(unsigned int) << endl;
	cout << "long - " << sizeof(long) << endl;
	cout << "unsigned long - " << sizeof(unsigned long) << endl;
	cout << "long long - " << sizeof(long long) << endl;
	cout << "long long int - " << sizeof(long long int) << endl;
	cout << "unsigned long long - " << sizeof(unsigned long long) << endl;
	cout << "float - " << sizeof(float) << endl;
	cout << "double - " << sizeof(double) << endl;
	cout << "size_t - " << sizeof(size_t) << endl;
	cout << "bool - " << sizeof(bool) << endl;
	cout << "char - " << sizeof(char) << endl;
	*/

	cout << "std::int8_t - " << sizeof(std::int8_t) << endl;
	cout << "std::uint8_t - " << sizeof(std::uint8_t) << endl;

	std::uint8_t num1 = -3;
	cout << static_cast<int>(num1) << endl;

	std::int8_t num2 = -3;
	cout << static_cast<int>(num2) << endl;

	//example0();
	//example1();
	//example2();
	//example3();
	//example4();
	//example5();

	system("pause");
	return 0;
}
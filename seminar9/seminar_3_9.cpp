#include <iostream>

#include "any_of.cpp"
#include "reverse_copy.cpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iterator> //inserter

using namespace std;

struct Point1 {
	int x, y;
	Point1(int x, int y) : x(x), y(x) {}
};

ostream& operator << (ostream& out, const Point1& p) {
	out << p.x << " " << p.y;
	return out;
}

void uniqueTest()
{
	cout << "Unique example" << endl;

	// удаление повторяющихся элементов
	vector<int> testVector{ 1, 2, 3, 1, 2, 3, 3, 4, 5, 4, 5, 6, 7 };
	sort(testVector.begin(), testVector.end()); // 1 1 2 2 3 3 3 4 4 5 5 6 7 
	auto last = unique(testVector.begin(), testVector.end());

	// testVector сейчас содержит {1 2 3 4 5 6 7 * * * * * *}, 
	// где * обозначает неопределённый элемент
	cout << "Size = " << testVector.size() << endl;
	for (int i : testVector) {
		cout << i << " ";
	}
	cout << endl;

	testVector.erase(last, testVector.end());

	cout << "Size = " << testVector.size() << endl;

	for (int i : testVector) {
		cout << i << " ";
	}
	cout << endl;
}

// Удаление последовательных повторяющихся пробелов
void uniqueSpaceTest()
{
	string testString = "A   string   with  odd       spaces";

	cout << testString << '\n';

	auto end = unique(testString.begin(), testString.end());
	
	/*
	auto end = unique(testString.begin(), testString.end(), [](char left, char right) {
		return isspace(left) && isspace(right);
	});
	*/

	cout << testString << '\n';
	cout << string(testString.begin(), end) << endl;
	cout << "Test string size: " << testString.size() << endl;
	testString.erase(end, testString.end());
	cout << testString << endl << endl;
}

void unique_copy()
{
	string testString = "A string    with   odd      spaces";
	cout << "testString: " << testString << endl;

	string result;
	//Почему нельзя третьим параметром result.begin()? Или можно?
	auto res = unique_copy(testString.begin(), testString.end(), back_inserter(result),
		[](char c1, char c2) { return c1 == ' ' && c2 == ' '; });

	cout << "Result: " << result << endl;
}

int main() {

	std::vector<int> v1 = { 1, 2, 3 };
	std::vector<int> v2 = { 2, 4, 6, 8 };
	std::vector<int> v3;

	//Упадет - недостаточно места в v3
	//std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

	//uniqueTest();
	//uniqueSpaceTest();
	//unique_copy();

	anyOf();
	//reverseCopy();	
	system("pause");
	return 0;
}




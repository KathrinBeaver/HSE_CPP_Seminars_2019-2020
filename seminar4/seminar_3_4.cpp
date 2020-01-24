#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Car {
    string name;
    long price;
    int yearOfProduction;
    Car(string _name, long _price, int _yearOfProduction) :
        name(_name), price(_price), yearOfProduction(_yearOfProduction) {}
};

bool sortByPrice(const Car& car1, const Car& car2) {
	return car1.price < car2.price;
}

bool operator < (const Car& car1, const Car& car2) {
    return car1.name < car2.name;
}

void example3_4_1() {
	vector<Car> garage;
	garage.push_back({ "Audi", 100500, 2017 });
	garage.push_back({ "Bmw", 100501, 2016 });
	garage.push_back({ "Bently", 100900, 2017 });
	garage.push_back({ "UAZ", 666, 2015 });
	garage.emplace_back("ddd", 555, 2016);
	
	sort(garage.begin(), garage.end());

	// сортировка с помощью вспомогательной функции
	sort(garage.begin(), garage.end(), sortByPrice);
	
	for (size_t i = 0; i < garage.size(); ++i) {
		cout << garage[i].price;
		cout << " " + garage[i].name + " ";
		cout << garage[i].yearOfProduction << endl;
	}
	
	// сортировка с помощью lambda-функции
	sort(garage.begin(), garage.end(),
		[](Car& car1, Car& car2)->bool {
			return car1.yearOfProduction < car2.yearOfProduction;
		});

/*	int count = garage.size();

	sort(garage.begin(), garage.end(), 
		[count] (Car& car1, Car& car2)->bool {
			int tmp = count; // "count" захватываетс¤ по значению
			//count++;
			return car1.yearOfProduction < car2.yearOfProduction;
		});
*/

	cout << "\nWith lambda:\n";
	for (size_t i = 0; i < garage.size(); ++i) {
		cout << garage[i].price;
		cout << " " + garage[i].name + " ";
		cout << garage[i].yearOfProduction << endl;
	}
	/* ¬опрос: а как еще, не пользу¤сь функцией или л¤мбда функцией 
	   "научить" std::sort сортировать объекты собственных типов?
	*/
}
// habr про л¤мбды: https://habr.com/ru/post/66021/

/*
	std::set Ч ассоциативный контейнер, который содержит упор¤доченный набор
	уникальных объектов типа Key. —ортировка элементов осуществл¤етс¤ применением
	функции Compare к ключам множества.
	ќперации поиска, удалени¤ и вставки имеют логарифмическую сложность.
*/
void example3_4_2() {
	set<int> numbers = {1, 2, 3, 4, 5, 1, 2, 3};
	
	for (const auto number : numbers) {
		cout << number << endl;
	}

	set<Car> garage;
    garage.insert({"Audi", 100500, 2017});
    garage.emplace("Bmw", 100501, 2016);
    garage.insert({"Audi", 100502, 2018});
    garage.insert({"ZaZ", 100, 2010});

    for (const auto& car : garage) {
        cout << "The car is: " << car.name << " price: " << car.price << endl;
    }	
}

void calculateDigitsCount() {
	int number = 422224;
	set<char> digits;
	char last = number % 10;
	while (number /= 10) {
		digits.insert(last);
		last = number % 10;
	}
	cout << "Total digits in the number: " << digits.size() << "\n";
}

int main() {
	//example3_4_1();
    example3_4_2();
	//calculateDigitsCount();

    system("pause");
    return 0;
}

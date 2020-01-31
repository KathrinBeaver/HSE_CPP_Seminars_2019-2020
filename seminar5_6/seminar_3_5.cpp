#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Car {
	string name;
	long price;
	int yearOfProduction;
	Car(string _name, long _price, int _yearOfProduction) :
		name(_name), price(_price), yearOfProduction(_yearOfProduction) {}
};

struct SortCar {
	bool operator ()(const Car& car1, const Car& car2) const {
		return car1.price < car2.price;
	}
};

bool sortByPrice(const Car& car1, const Car& car2) {
	return car1.price < car2.price;
}

bool operator < (const Car& car1, const Car& car2) {
	return car1.name < car2.name;
}

/*
std::set — ассоциативный контейнер, который содержит упорядоченный набор
уникальных объектов типа Key. Сортировка элементов осуществляется применением
функции Compare к ключам множества.
Операции поиска, удаления и вставки имеют логарифмическую сложность.
*/
void example3_5_0() {
	set<int> numbers = { 1, 2, 3, 4, 5, 1, 2, 3 };

	for (const auto number : numbers) {
		cout << number << endl;
	}

	set<Car, SortCar> garage;
	//set<Car> garage;
	garage.insert({ "Audi", 100500, 2017 });
	//garage.emplace({ "Audi", 100500, 2017 });
	garage.emplace("Bmw", 100501, 2016);
	garage.insert({ "Audi", 100502, 2018 });
	garage.insert({ "ZaZ", 100, 2010 });

	garage.find({ "Audi", 111, 22 });

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

/*
std::map — отсортированный ассоциативный контейнер,
который содержит пары(std::pair) ключ-значение с неповторяющимися ключами.
Порядок ключей задаётся функцией сравнения Compare.
Операции поиска, удаления и вставки имеют логарифмическую сложность.
*/
void example3_5_1() {
	cout << "\nMap example started \n";

	map<char, int> myMap;

	myMap['x'] = 100;
	myMap.emplace('y', 200);
	myMap.insert(pair<char, int>('z', 300));
	myMap.insert({ 'ab', 400 }); // ошибка? (на самом деле - да, но VS такое "cъест").  
	myMap.insert({ '1', 500 });
	
	auto retVal = myMap.insert({ '1', 600 });

	cout << "\nInsert returned: " << retVal.first->first << "  " << retVal.first->second << "  " << retVal.second;
	cout << "\nInsert returned: " << (*retVal.first).first << "  " << (*retVal.first).second << "  " << retVal.second;
	
	myMap.emplace('1', 700);
	//myMap['1'] = 800;

	cout << "\nmyMap contains:";
	cout << "\t{";
	for (const auto& x : myMap) {
		cout << "\'" << x.first << "\':" << x.second << ", ";
	}
	cout << "}\n";

	// map::count(key) - возвращает количество элементов, соответствующих ключу. 
	// Что может вернуть count в map?
	cout << "count = " << myMap.count('y') << "\n";

	if (myMap.find(111) != myMap.end()) { // Какой тип данных мы ищем?
		cout << "Element exist!" << endl;
	} else {
		cout << "No element!" << endl;
	}
}

// Работа с unordered_set
/*
Неупорядоченный набор представляет собой ассоциативный контейнер,
который содержит множество уникальных объектов типа Key.
Поиск, вставка и удаление имеют константную сложность
*/


// Собственная функция для вычисления хэшей на основе длин строк.
// Обратите внимание на способ ее оформления - тип с определенным оператором()
struct StringHashBySize {
	// На засыпку: что значит последний const?
	size_t operator()(const string& str) const {
		int size = str.length();

		//hash<int> hashInt;
		//return hashInt(size);

		return hash<int>()(size);
	}
};

// Собственное сравнение строк - по длине
struct StringEqualBySize {
	bool operator()(const string& str1, const string& str2) const {
		if (str1.length() == str2.length()) {
			return true;
		}
		else {
			return false;
		}
	}
};

void example3_5_2() {
	// Объявление сета с собственными функциями определения уникальности элемента
	unordered_set<string, StringHashBySize, StringEqualBySize> setOfStrs;
	//unordered_set<string> setOfStrs1;

	setOfStrs.insert("First");
	setOfStrs.insert("second");

	// Будет ли добавлено? 
	setOfStrs.insert("third");
	setOfStrs.insert("Second");
	setOfStrs.insert("five");

	for (const string& s : setOfStrs) {
		cout << s << endl;
	}
}

// Задача:
// Попробуйте сложить в unordered_map Автомобили, представленные структурой Car.

/*
Other Associative containers:
set
multiset
map
multimap
Unordered associative containers:
unordered_set
unordered_multiset
unordered_map
unordered_multimap
*/

void calculateWordsCount() {
	string word;
	map<string, int> freqs;
	while (cin >> word) {
		if (word == "!") break;
		++freqs[word]; // если ключа не было - он вставится на лету со значением 0		
	}
	for (const auto& item : freqs) {
		cout << item.first << "\t" << item.second << "\n";
	}
}

/*
std::multimap
это ассоциативный контейнер, который содержит упорядоченный список пар "ключ-значение".
Сортировка аналогична map.
Операции поиска, и удаления имеют логарифмическую сложность.
Порядок пар ключ-значение с одинаковыми ключами соответствует порядку вставки пар и не меняется.
*/
int multimapExample() {
	std::multimap<char, int> lettersMap;

	lettersMap.insert(pair<char, int>('a', 10));
	lettersMap.insert(pair<char, int>('b', 20));
	lettersMap.insert(pair<char, int>('b', 30));
	lettersMap.insert(pair<char, int>('b', 40));
	lettersMap.insert(pair<char, int>('c', 50));
	lettersMap.insert(pair<char, int>('c', 60));
	lettersMap.insert(pair<char, int>('d', 60));

	cout << "MultiMap: " << endl;
	for (const pair<char, int> item : lettersMap) {
		cout << item.first << "\t" << item.second << "\n";
	}
	
	// Получить элементы через find
	auto foundItem = lettersMap.find('b');
	cout << "Values for key " << foundItem->first << ": ";
	while (foundItem != lettersMap.end() && foundItem->first == 'b') {
		cout << foundItem->second << " ";
		++foundItem;
	}	

	// или через equal_range
	std::cout << "\nmyMultiMap contains:\n";
	for (char ch = 'a'; ch <= 'd'; ch++)
	{
		std::pair<std::multimap<char, int>::iterator, std::multimap<char, int>::iterator> ret 
			= lettersMap.equal_range(ch); //возвращает пару итераторов: начало и конец
		std::cout << ch << " =>";
		for (std::multimap<char, int>::iterator it = ret.first; 
			it != ret.second; ++it)
			std::cout << ' ' << it->second;
		std::cout << '\n';
	}

	return 0;
}


int main() {

	string line;

	ifstream in("testIn.txt");

	cout << "Read from file: \n" << endl;
	if (in.is_open()) {
		while (getline(in, line)) {
			cout << line << endl;
		}		
	}

	ofstream out;
	out.open("testOut.txt");
	out << "Hello";

	//example3_5_0();
	//calculateDigitsCount();

	example3_5_1();  
	//example3_5_2();

	//calculateWordsCount();	
	//multimapExample();

	system("pause");
	return 0;
}


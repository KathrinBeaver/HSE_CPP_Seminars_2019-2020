#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

void examplePairs() {
    pair<int, int> coordinatesOfPointA = { 10, 10 };
	cout << coordinatesOfPointA.first << ' ' 
		<< coordinatesOfPointA.second << endl;

    pair<int, int> coordinatesOfPointB;
    if (coordinatesOfPointA == coordinatesOfPointB) {
        cout << "Equals 1\n";
    }

	cout << coordinatesOfPointB.first << ' ' << coordinatesOfPointB.second << endl;

    coordinatesOfPointB = coordinatesOfPointA;
	cout << coordinatesOfPointB.first << ' ' << coordinatesOfPointB.second << endl;
	if (coordinatesOfPointA == coordinatesOfPointB) {
		cout << "Equals 2\n";
	}
}

void exampleTuples() {
    tuple<int, double, string, int> tup1 {0, 3.14, "hello", 3 };
    tuple<int, double, string, int> tup2 {-1, 3.15, "hello", 2 };
    cout << get<1>(tup1) << "\n"; // 3.14
    cout << get<double>(tup1) << "\n"; // 3.14
	//cout << get<int>(tup1) << "\n"; // ?
    cout << (tup2 > tup1) << endl;
}

/* Пример 1. 2 простейшие структуры */
/* Структура применяется как POD-тип данных,
структуры хранятся на стеке.
*/
struct Date {
    int year;
    int month;
    int day;
};

struct ItemInStore {
    string name;
    Date expirationDate;
    int priсe;
};

bool operator < (const ItemInStore& item1, const ItemInStore& item2) {
    const Date& d1 = item1.expirationDate;
    const Date& d2 = item2.expirationDate;
    return d1.year < d2.year
        || d1.year == d2.year && d1.month < d2.month
        || d1.year == d2.year && d1.month == d2.month && d1.day < d2.day;
}

/* Задача 1.
Заполнить магазин случайными товарами из перечня
{"товар1, товар2, товар3"}.
Для всех указать случайный не истёкший срок годности
в этом или следующем году.
Для всех сделать случайную цену в диапазоне [10; 100].
Отсортировать товары магазина по возрастанию срока годности.
*/
vector<ItemInStore> example3_3_1() {
    cout << "\nExample #1 started \n";
    const int N = 10;
    vector<ItemInStore> goods;	
    vector<string> listOfGoods = { "Screwdriver", "Hammer", "Pliers" };
    Date expDate = { 10, 11, 2019 };
    cout << "Size of Date = " << sizeof(expDate) << "\n\n";

    for (size_t i = 0; i < N; i++) {
        expDate.year = rand() % 2 + 2020;
        expDate.month = rand() % 12 + 1;
        expDate.day = rand() % 28 + 1; //чтобы не добавлять еще условий
        goods.push_back({ listOfGoods.at(rand() % 3),
                        expDate,
                        rand() % 91 + 10
            });
    }
    sort(goods.begin(), goods.end());

    //Print the result
    for (auto item : goods) {
        cout << item.name << " " << item.priсe << " ";
        cout << item.expirationDate.day << "-";
        cout << item.expirationDate.month << "-";
        cout << item.expirationDate.year << "\n";
    }
    return goods;
}

/* Ссылки */
/* Написать функцию, которая будет увеличивать цену
товаров из предыдущей задачи на 10%
*/
// Какую сигнатуру выбрать?
//void example3_3_2(vector<ItemInStore> v) {
//void example3_3_2(const vector<ItemInStore>& v) {
void example3_3_2(vector<ItemInStore>& goods) {
    cout << "\nExample 2 started \n";

	// Ссылка обязательно! Иначе - копия и список не поменяется
    for (ItemInStore& item : goods) { 
        item.priсe = static_cast<int>(round(item.priсe * 1.1));
    }

	// Cсылка желательно, экономим память.
	// const желательно, ускоряем программу
    for (const auto& item : goods) {
        cout << item.name << " " << item.priсe << " ";
        cout << item.expirationDate.day << "-";
        cout << item.expirationDate.month << "-";
        cout << item.expirationDate.year << "\n";
    }
}

int main() {
	
	/*
	string str = "sss";
	int res = str.find("ggg");
	cout << res << endl;
	cout << str.find("aaa") << endl;
	cout << std::hex << str.find("aaa") << endl;

	unsigned int tmp = 0;
	cout << tmp - 1 << endl;
	cout << std::hex << std::string::npos << endl;

	*/

	//examplePairs();
	//exampleTuples();
	vector<ItemInStore> store = example3_3_1();
	example3_3_2(store);    
    system("pause");
    return 0;
}

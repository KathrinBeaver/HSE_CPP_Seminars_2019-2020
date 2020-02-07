#ifndef _LIST_EXAMPLE_
#define _LIST_EXAMPLE_

#include<list>
#include<iostream>

using namespace std;

template <class T>
ostream& operator << (ostream& out, list<T> listToPrint) {
	for (auto& elem : listToPrint) {
		cout << elem << " ";
	}
	return out;
}

/*
 Нужно создать список из 20 элементов.
 Заполнить этот список значениями по возрастанию.
 Вставить в каждую позицию списка, кратную 3, цифру 100.
 Пример:
	Список: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
	Вывод:  1,2,100,3,4,100,5,6,100,7,8,100,9,10,100,11,12,100,
	13,14,100,15,16,100,17,18,100,19,20
*/
void listExample() {
	list<int> listOfNumbers;
	for (int i = 0; i < 20; ++i) {
		listOfNumbers.push_back(i + 1);
	}
	cout << listOfNumbers << endl;
	int count = 1;
	for (auto it = listOfNumbers.begin(); it != listOfNumbers.end(); ++it) {
		if (count % 3 == 0) {
			listOfNumbers.insert(it, 100);
			count++;
		}
		count++;
	}
	cout << listOfNumbers << endl;
}
#endif // !_LIST_EXAMPLE_

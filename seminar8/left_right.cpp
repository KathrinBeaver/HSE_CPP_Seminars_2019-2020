/*
	Дан отсортированный вектор натуральных чисел.
	Нужно найти индекс самого левого
	и самого правого вхождения введенного числа.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void leftAndRight() {
	std::vector<int> numbers = { 2, 3, 5, 7, 7, 9, 10, 3, 11 };

	int el;
	std::cout << "Enter an element to look for: ";
	std::cin >> el;
	auto foundFirst = std::find(numbers.begin(), numbers.end(), el);
	if (foundFirst == numbers.end()) {
		std::cout << "No elements were found!" << std::endl;
		return;
	}
	//auto foundLast = std::find(foundFirst + 1, numbers.end(), el);
	auto foundLast = std::find(numbers.rbegin(), numbers.rend(), el);

/*	if (foundLast == numbers.end()) {
		foundLast = foundFirst;
	} 
	else {
		auto tmp = foundLast;
		while (tmp != numbers.end()) {
			foundLast = tmp;
			tmp = std::find(foundLast + 1, numbers.end(), el);
		}
	}
	*/
	
    std::cout << "First found at " << (foundFirst - numbers.begin()) << std::endl;
    std::cout << "Last  found at " << (numbers.rend() - foundLast - 1) << std::endl;
}
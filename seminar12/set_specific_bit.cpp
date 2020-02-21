#include <bitset>
#include <iostream>
#include <string>

using namespace std;

/*
	Напишите программу, которая в заданном числе устанавливает
	определенный бит в 1 (биты при этом нумеруются с нуля,
	начиная от младших).
*/
int setBit1() {
	int num =  42, bit = 4;
	std::cout << num << std::endl;
	std::cout << (num | (1 << bit)) << std::endl;
	std::cout << num << std::endl;
	num = num | (1 << bit);
	std::cout << num << std::endl;
	return 0;
}

int setBit2() {	
	bitset<16> num(42);		
	std::cout << num << std::endl;
	std::cout << num.test(4) << std::endl;
	std::cout << num.count() << std::endl;
	num.set(4);
	std::cout << num.to_string() << std::endl;
	std::cout << num.count() << std::endl;
	std::cout << num.to_ulong() << std::endl;
	std::cout << num.reset(4) << std::endl;	
	std::cout << num.to_ulong() << std::endl;
	return 0;
}

/*
	Напишите программу, которая обнуляет
	заданное количество последних бит числа
	TODO Реализовать с помощью bitset
*/
int setZeros() {
	int num = 42, bits = 2;
	std::cout << num << std::endl;
	std::cout << std::hex << num << std::endl;
	int mask = (1 << bits) - 1;
	std::cout << (num & (~mask)) << std::endl;	
	return 0;
}
/*
	Напишите программу, которая выводит значение (десятичное), 
	содержащееся в заданных битах числа (например, с 3 по 5-й)
	TODO Реализовать с помощью bitset
*/
int getBitValues() {
	int num = 42, bitFrom = 3, bitTo = 6; // 42 = 0010 1010

	// mask = 0100 0000 - 0000 1000 = 0011 1000
	int mask = (1 << bitTo) - (1 << bitFrom); 
	
	std::cout << ((num & mask) >> bitFrom) << "\n"; // 101 = 5
	return 0;
}

/*
IPv4-адрес принято записывать, используя 4 числа, разделенные точками. 
Например: 192.168.1.1
Эту запись можно воспринимать как запись 4-значного числа 
в "256-ричной системе счисления".
Ваша задача реализовать перевод из 256-ричной в десятичную систему 
счисления и наоборот.
*/
void ipv4ToInt() {
	std::string line;
	getline(std::cin, line);
	if (std::count(line.begin(), line.end(), '.') == 0) {
		auto ipAddress = stoll(line);
		std::cout << (ipAddress / (1 << 24)) << "."
			<< ((ipAddress % (1 << 24) / (1 << 16))) << "."
			<< (ipAddress % (1 << 16) / (1 << 8)) << "."
			<< (ipAddress % (1 << 8));
	}
	else {
		long long number = 0;
		for (auto i = 0; i != 4; ++i) {
			number = (number << 8);
			number += stoi(line.substr(0, line.find('.')));
			line = line.substr(line.find('.') + 1);
		}
		std::cout << number;
	}	
}

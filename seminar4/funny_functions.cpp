#include <iostream>

using namespace std;

void func1() {
	int number1 = 150;
}

void func2() {
	int number2;
	cout << "number2 = " << number2;
}

int main() {
    cout << "Start... \n";
   
	func1();
	func2();
    
    cout << "Finish... \n";    
}
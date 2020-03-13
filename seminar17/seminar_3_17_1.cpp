#include <iostream>
#include <string>

class A {
};
class B {
public:
	virtual ~B() {};
};

bool isNegative(float x) {
    //int *ptr = (int*) &x;	
	int ptr = static_cast<int>(x);	
	//int *ptr = reinterpret_cast<int*>(&x);
    return ptr > 0; // или проверить старший бит
}
int main() {
    std::cout << std::boolalpha << isNegative(-1.0) << std::endl;

	int a = 10, b = 3;
	const int* pointer1 = &a;
	pointer1 = &b;
	int* pointer2 = const_cast<int*>(pointer1);
	//int* pointer3 = pointer1;
	//*pointer1 = 0;
	*pointer2 = 0;

	//A objA = static_cast<A>(B());
	A* objA = dynamic_cast<A*>(new B());

    system("pause");
    return 0;
}
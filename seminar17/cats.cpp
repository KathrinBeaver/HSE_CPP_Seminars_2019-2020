#include <iostream>

using std::cout;
using std::endl;

class Cat {
public:
    virtual ~Cat() {
	//~Cat() {
        sayGoodbye();
    }
	
	void sayGoodbye() const {
		cout << "I am SimpleCat: Bye, meow-meow!" << endl;
	}
    
	virtual void askForFood() const {
        speak();
        eat();
    }

    virtual void speak() const {
        cout << "Meeeeeow! ";
    }

    void eat() const {
        cout << "**mmmm**" << endl;
    }
	Cat() {
		cout << "Cat created" << endl;
	}
	Cat(Cat& other) = default;
	Cat(Cat&& other) = default;
};

class Persian : public Cat {
public:
	void speak() const {
        cout << "Where is my meat? ";
    }
	void sayGoodbye() const {
        cout << "I am Persian: Bye-bye" << endl;
    }
	~Persian() {
        sayGoodbye();
    }

	// Not mandatory
	Persian() : Cat() {
		cout << "Persian created" << endl;
	};	
};


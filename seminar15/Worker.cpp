#ifndef _worker
#define _worker

#include <iostream>
#include <memory>

class Worker {
private:
	int state;
	// Ќадо знать какой статус у другого обработчика, используем "умный" указатель на него
	//std::shared_ptr<Worker> otherWorker; 
	std::weak_ptr<Worker> otherWorker;
public:
	Worker(){
		std::cout << "In Constructor \n";
	}
	
	void setPtr(std::shared_ptr<Worker>& other) {
		this->otherWorker = other;
	}

	~Worker(){
		std::cout << "In Destructor \n";
	}
	
	void test1() {	
		//otherWorker->test2(); // ќшибка компил¤ции при std::weak_ptr<Worker> otherWorker;
		if (auto tmp = otherWorker.lock())
		{
			tmp->test2();
		}	
	}

	void test2() {
		std::cout << "Test2\n";
	}	
};
#endif
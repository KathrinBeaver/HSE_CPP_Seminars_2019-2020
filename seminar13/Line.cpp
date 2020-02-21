#include <iostream>
#include <string>

class Line {

private:	
	int* xs;
	int* ys;

public:	

	Line() {		
		std::cout << "!!! new object Line() " << "\n";		
		xs = new int[10];
		ys = new int[10];
		for (int i = 0; i < 10; i++) {
			this->xs[i] = i;
			this->ys[i] = i;
		}
	}
	
	// конструктор копирования
	Line(const Line& other) {		
		xs = new int[10];
		ys = new int[10];
		for (int i = 0; i < 10; i++) {
			this->xs[i] = other.xs[i];
			this->ys[i] = other.ys[i];
		}		
		std::cout << "!!! new copy object Line " << "\n";
	}

	// move-конструктор
	Line(Line&& other) {  // && - это rvalue-ссылка, по которой можно передать временный объект		
		std::cout << "!!! move Line(Line&&)" << "\n";
		this->xs = std::move(other.xs);
		other.xs = nullptr;
		this->ys = std::move(other.ys);
		other.ys = nullptr;
	}

	Line& operator = (const Line& other) {
		xs = new int[10];
		ys = new int[10];
		for (int i = 0; i < 10; i++) {
			this->xs[i] = other.xs[i];
			this->ys[i] = other.ys[i];
		}
		std::cout << "!!! operator = (const Line&) " << "\n";
		return *this;
	}

	Line& operator = (Line&& other) {
		this->xs = std::move(other.xs);
		other.xs = nullptr;
		this->ys = std::move(other.ys);
		other.ys = nullptr;
		std::cout << "!!! operator = (Line&&) " << "\n";
		return *this;
	}

	~Line() {
		delete this->xs;
		delete this->ys;
		std::cout << "!!! delete object Line()" << "\n";
	}

	void PrintInfo() {
		for (int i = 0; i < 10; i++) {		
			std::cout << "(" << this->xs[i] << ", " << this->ys[i] << ")\t";
		}		
	}
};
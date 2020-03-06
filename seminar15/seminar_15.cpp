// Seminar2_16
#include <memory>
#include <vector>
#include "Point.cpp"
#include "Worker.cpp"

int Point::count = 0;
int Point::realCount = 0;

void example0() {
	void* point = new Point(); //так можно?
	// ...
	delete point; // а так можно?
	// delete (Point*)point;
	// Но правильно пользоваться виртуальными деструкторами базовых классов, 
	// но об этом в следующем модуле.

	int* array = new int[25];
	// ...
	delete[] array; //удаляем массив целиком

	int* array2 = new int[25];
	// ...
	delete array2; // Удаляется только первый элемент массива.
	//все остальные утекли 
	
	Point* array3 = new Point[42]; 
	Point* temp = array3; // Куда ссылается temp?
	array3 = array3 + 20;
	//delete temp; // Что удалит temp?
	// А так?
	delete[] array3;
	// А так?
	delete[] temp;
}

void example1() {
	// AutoPtr старый тип автоматического указателя, 
	// при присваивании в исходном указателе получается нулевой. 
	// что является частым источником ошибок!
	std::auto_ptr<Point> autoPtr1(new Point(1, 1));
	std::auto_ptr<Point> autoPtr2;
	autoPtr2 = autoPtr1;
	autoPtr2->PrintInfo();
	if (autoPtr1.get() != nullptr) {
		autoPtr1->PrintInfo();
	}
	else {
		std::cout << "Pointer autoPtr1 is empty!\n";
	}

	// Аналогично становится весьма неудобно использовать различные коллекции
	std::vector<std::auto_ptr<int>> collection;
	for (size_t i = 0; i < 10; ++i) {
		collection.push_back(std::auto_ptr<int>(new int(i * i))); // Сколько памяти выделили?
	}
	std::cout << *collection[2].get() << "\n";
	std::cout << *collection[2] << "\n"; // или так, * переопределена для умных указателей
	// Эта операция уберет данные из коллекции!
	std::auto_ptr<int> elem = collection[2]; 
	
	// Падение - обращение по нулевому указателю
	//std::cout << (*collection[2].get());
}

// unique_ptr
void example2() {
	std::unique_ptr<Point> p1(new Point(1, 2));
	// Решение проблемы с "потерей" указателя
	// Код не скомпилируется:
	//std::unique_ptr<Point> p2 = p1;
	// Но если очень надо, то можно в явном виде:
	std::unique_ptr<Point> p2 = std::move(p1);	
	p2->PrintInfo();
	//p1->PrintInfo(); // падение
}

void example3() {
	std::shared_ptr<Point> point2;
	{
		std::shared_ptr<Point> point1(new Point(99, 99));
		point2 = point1;
		point1->PrintInfo();
		point2->PrintInfo();

		std::cout << point1.use_count() << "\n"; //2
		std::cout << point2.use_count() << "\n"; //2
		// Будет ли удален point1? А данные?
	}
	// Что будет распечатано?
	point2->PrintInfo();
	std::cout << point2.use_count() << "\n"; //1
	// Что лучше?
	//doSomefunction(std::shared_ptr<Point>(new Point), executeSmth());
	//doSomefunction(std::make_shared<Point>(), executeSmth());
}

void example4() {
	std::shared_ptr<Worker> w1 = std::make_shared<Worker>();
	std::shared_ptr<Worker> w2 = std::make_shared<Worker>();
	w1->setPtr(w2);
	w2->setPtr(w1);
	w1->test1();
	std::cout << w1.use_count() << "\n";
	std::cout << w2.use_count() << "\n"; 
}

int main()
{
	//example0();
	//example1();
	//example2();
	//example3();
	example4();

	system("pause");
	return 0;
}

#include "cats.cpp"
#include <vector>
#include <memory>

using namespace std;
using myT = unique_ptr<Cat>;

//Cats with virtual methods and raw Pointers
void example0() {

	Cat* cats[] = { new Cat(), new Persian() };

	cout << "Simple Cat: ";
	cats[0]->askForFood();

	cout << "Persian Cat: ";
	cats[1]->askForFood();

	delete cats[0];
	delete cats[1];
}

// Example1 
// Use smart pointers instead of raw pointers and vector
void example1() {
	//vector<unique_ptr<Cat>> myCats;
	vector<myT> myCats;

	myCats.push_back(move(myT(new Cat())));
	myCats.push_back(move(myT(new Persian())));

	for (const auto& cat : myCats) {
		cat->askForFood();
	}
}

// What are the arguments of main()? 
int main(int argc, char** argv) {
	example0();
	example1();

	cout << "\nCommand line args:\n";
	if (argc != 0) {
		for (int i = 0; i < argc; i++) {
			cout << argv[i] << "\n";
		}
	}

	system("pause");
	return 0;
}


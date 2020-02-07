/*
Требуется простая релизация очереди с приоритетами.
clear — сделать очередь с приоритетами пустой.
add n — добавить в очередь с приоритетами число n. 
extract — достать из очереди с приоритетами максимальное значение.
*/

/*
Определено в заголовочном файле <queue>
template<class T, class Container = std::vector<T>,
class Compare = std::less<typename Container::value_type>> 

class priority_queue;

Очередь с приоритетом - это тип контейнера, 
который позволяет достичь константной скорости доступа к максимальному 
(или минимальному, в зависимости от реализации Compare) элементу.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <functional> //std::greater
#include <string>

using namespace std;

void makePriorityQueue() {
    string command;
    priority_queue<int, vector<int>, less<int>> myQueue;
    //priority_queue<int> myQueue;
    while(cin >> command) {
        if(command == "extract") {
            if(!myQueue.empty()) {
				//доступ к первому в очереди элементу
                std::cout << myQueue.top() << "\n"; 
                myQueue.pop();
            }
            else {
                std::cout << "Error, empty Queue\n";
            }
			continue;
        }
        if(command == "add") {
            size_t num;
            std::cin >> num;
            myQueue.push(num);
			continue;
        }
        if(command == "clear") {
            while(!myQueue.empty()) {
                myQueue.pop();
            }
			std::cout << "ok";
			continue;
        }
		cout << "Cmd is unknown. Finished.\n";
		break;
    }
}
// Реализовать очередь с приоритетами для точек по степени 
// удаленности от начала координат.
// Высший приоритет у точки, самой близкой к началу координат.
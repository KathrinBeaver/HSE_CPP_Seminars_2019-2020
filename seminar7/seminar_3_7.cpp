#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include "upper_bound.cpp"
#include "deque_impl.cpp"
#include "queue_with_priorities.cpp"
#include "sums_stack.cpp"
#include "list_example.cpp"

using namespace std;

ostream& operator << (ostream& out, const set<char> setOfSymbols) {
    for (const auto& symbol : setOfSymbols) {
        out << symbol << " ";
    }
    out << endl;
    return out;
}

void setIntersectionExample()
{
    string strForTest = "old owl owned сoal";
    stringstream stringStream(strForTest);
    string temp = "";
    string result = "";
    
    // Разделяем строку на слова
    stringStream >> result; 
    sort(result.begin(), result.end());
    
    while (stringStream >> temp)
    {
        sort(temp.begin(), temp.end());
        set_intersection(result.begin(), result.end(), 
							temp.begin(), temp.end(), 
							result.begin());
    }
    set<char> resultSet(result.begin(), result.end());
    cout << "Common letter(s): " << resultSet;
}

int main() {
    
    //listExample();
    
	//printSums(3);

	//makeDeque();

	//makePriorityQueue();

	//setIntersectionExample();   

    system("pause");
    return 0;
}

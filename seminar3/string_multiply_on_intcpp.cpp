#include <string>
#include <iostream>

using namespace std;

// исправляем недостаток С++ : 
// учим строку умножаться на число
string operator * (string& str, int k) {
    string repl = str;
    for (size_t i = 1; i < k; ++i) {
        str.replace(str.begin(), str.begin(), repl);
    }
    return k ? str : "";
}

void testMultiplyOnNumber() {
    string sTest = "abc1";
    cout << sTest * 2 << endl;
    cout << sTest * 0 << endl;
    cout << sTest * 3 << endl;    
	cout << sTest * -2 << endl;
}

int main222() {
	testMultiplyOnNumber();
	system("pause");
	return 0;
}

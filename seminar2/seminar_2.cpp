#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Строки и всё, что про них полезно знать */
void example2_3_1() {
    string str1 = "A little brown fox jumps over a lazy dog";
    str1 += " and another dog";
    //str1 = str1 * 3; //- такая операция не определена
    cout << str1.size() << endl; // 56
    cout << str1.length() << endl; // 56
	cout << str1.capacity() << endl; 
    cout << str1 << endl;
    reverse(str1.begin(), str1.end()); // строка в обратном порядке
    cout << str1 << endl;
    reverse(str1.begin(), str1.end());    

	cout << "***********************" << endl;

    const char* chs = str1.c_str(); //Преобразует строку к массиву символов в стиле Си.
   
	const string& str2 = str1; // str2 - доступная только для чтения ссылка на str1.
    str1[0] = 'a'; // ok
    //str2[0] = 'n'; // error!
	cout << str1;
	cout << str2;

	cout << "***********************" << endl;

    const string zzz = "zzz";
    cout << str1.insert(1, zzz) << endl;
	cout << str1 << endl;
    cout << str1.find(zzz) << endl; // Позиция первого вхождения или "-1".

	cout << "***********************" << endl;
	
	//if (str1.find("123") != -1) {
	if (str1.find(zzz) != -1) {
		cout << str1.replace(str1.find(zzz), zzz.length(), "*") << endl; // replace: откуда, сколько, "на что менять"
	}
	else {
		cout << "Error!" << endl;
	}

	cout << "***********************" << endl;
	//cout << str1.replace(-1, zzz.length(), "*") << endl;
	cout << "***********************" << endl;
    
	for (auto ch : str1) {
	//for (auto& ch : str1) {
        ch += 1;
		cout << ch;
    }
    cout << str1 << endl; //поменяется ли строка?

	if (str1 > "aaa") {
		cout << ">" << endl;
	} 
	else {
		cout << "<" << endl;
	}
	
}
/* 
 Дана строка, в которой буква h встречается как минимум два раза.
 Разверните последовательность символов, заключенную между первым
 и последнием появлением буквы h в противоположном порядке.
*/
void example2_3_2() {
    string str1;
    cout << "Please enter a string containing two letters \"h\":\n";
    getline(std::cin, str1);
    int hFirstPos = str1.find('h');
    int hLastPos = str1.rfind('h');
    if(hFirstPos == -1 || hFirstPos == hLastPos) {
        cout << "Your string is not correct\n";
    }
    else {
        reverse(str1.begin() + hFirstPos + 1, str1.begin() + hLastPos);
        cout << str1 << endl;
    }
}
/*
    Продублировать заключенную между первым и 
	последним вхождением символа "@" подстроку.
*/
void example2_3_3() {
    string str = "a @12345@ a";
	cout << str << endl;
    int atFirstPos = str.find('@');
    int atLastPos = str.rfind('@');
    string strDuplicate = str.substr(atFirstPos + 1, atLastPos - atFirstPos - 1); //откуда, сколько
    cout << strDuplicate << endl;
	strDuplicate += strDuplicate;
    str.replace(atFirstPos + 1, strDuplicate.length() / 2, strDuplicate);
    cout << str << endl;
}
/*
   Удалить из строки все символы @.
*/
void example2_3_4() {
    string str = "@123@abcd.com@";
	cout << str << endl;
    int pos = -1;
    while((pos = str.find("@")) != -1) {
        str.replace(pos, 1, "");
    }
    cout << str << endl;
}

int main() {    

	string str1;
	cin >> str1;	
	cout << str1 << endl;

	string str2;
	getline(cin, str2);
	cout << str2 << endl;

	str1[0] = 'Z';
	cout << str1 << endl;	

	/*
	const string STR;
	cin >> STR;	
	cout << STR << endl;
	STR[0] = 'Z';
	cout << STR << endl;
	*/

    //example2_3_1();
    //example2_3_2();
    //example2_3_3();
    //example2_3_4();

    system("pause");
    return 0;
}



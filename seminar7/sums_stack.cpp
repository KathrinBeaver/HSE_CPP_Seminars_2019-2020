/*
    Для данного введенного натурального числа N 
    вывести все его разложения 
    в виде суммы натуральных чисел.
*/

#include <iostream>
#include <vector>

using namespace std;

void printResult(const vector<size_t>& v) {
    for(const auto& elem : v) {
        cout << elem << ' ';
    }
    cout << endl;
    return;
}

void countSums(size_t maxNum, size_t currSum, vector<size_t>& ans) {
    if(currSum == maxNum) {
        printResult(ans);
        return;
    }

    for(size_t i = 1; i <= maxNum; ++i) {
        if(currSum + i <= maxNum) {
            ans.push_back(i);
            countSums(maxNum, currSum + i, ans);
            ans.pop_back();
        }
        else {
            break;
        }
    }
}

void printSums(size_t number) {
    vector<size_t> v;
    countSums(number, 0, v);
}
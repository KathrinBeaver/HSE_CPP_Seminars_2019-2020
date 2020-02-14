/*
Вам надо написать свою реализацию алгоритма any_of. 
Заголовок функции должен быть таким:
template <typename It, typename Pred>
bool any_of(It first, It last, Pred func);
Функция должна вернуть true,
если в последовательности [first; last) существует элемент,
для которого функция func возвращает истину.
В противном случае функция должна вернуть false.

Протестируйте вашу функцию для предиката "число является четным" на контейнере list.

Аналогично, протестируйте функцию на векторе точек,
проверяя лежит ли точка на параболе y=x^2
*/

#include <iostream>
#include <list>
#include <vector>

namespace myStd {
    template <typename It, typename Pred>
    bool any_of(It first, It last, Pred func) {
        while(first != last) {
            if(func(*first)) {
                return true;
            }
            ++first;
        }
        return false;
    }
}

struct Point2 {
    double x, y;
    Point2(double x, double y) : x(x), y(y) {}
};

void anyOf() {
    std::list<int> numbers = {1, 3, 5, 7, 7, 9, 11};
    bool result = myStd::any_of(numbers.begin(), numbers.end(), [](int x) -> bool {return !(x % 2); });
    std::cout << std::boolalpha << result << std::endl;

    std::vector<Point2> points;
    points.emplace_back(1, 2);
    points.emplace_back(-1, -2);
    points.emplace_back(0, 0);

    result = myStd::any_of(points.begin(), points.end(), [](const Point2& p) -> bool {
        return p.y == p.x * p.x;
    });

    std::cout << std::boolalpha << result << std::endl;
}

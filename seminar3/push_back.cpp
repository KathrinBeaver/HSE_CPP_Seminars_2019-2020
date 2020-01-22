#include <vector>

struct Item {
    int a, b, c;
    Item(int a, int b, int c) : a(a), b(b), c(c) {}
};

// emplace умеет вызывать конструктор в недрах вектора, не создавая лишних копий.
int mainPushEmplace() {
    std::vector<Item> items;
    //items.push_back(1, 2, 3);    <- не скомпилируется!
	items.push_back(Item(1, 2, 3));
	items.emplace_back(1, 2, 3);
    return 0;
}

int main3() {
	mainPushEmplace();
	system("pause");
	return 0;
}

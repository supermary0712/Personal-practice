#include <iostream>
#include <set>
#include <string>

//using namespace std;

int main()
{
    std::set<std::string> stringset;
    std::set<int> intset;

    std::cout << "1、stringset size = " << stringset.size() << std::endl;
    std::cout << "1、intset size =" << intset.size() << std::endl;

    stringset.insert("abc");
    stringset.insert("lmn");
    stringset.insert("opq");

    intset.insert(1);
    intset.insert(2);
    intset.insert(3);
    intset.insert(4);
    intset.insert(3);

    std::cout << "2、stringset size = " << stringset.size() << std::endl;
    std::cout << "2、intset size = " << intset.size() << std::endl;

    for (auto iter = stringset.begin(); iter != stringset.end(); iter++) {
        std::cout << *iter << std::endl;
    }

    for (auto int_iter = intset.begin(); int_iter != intset.end(); int_iter++) {
        std::cout << *int_iter << std::endl;
    }

    return 0;
}
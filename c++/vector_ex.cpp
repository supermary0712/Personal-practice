#include <iostream>
#include <vector>

//验证emplace_back()和push_back()的区别
/*
emplace_back() 和 push_back() 的区别，就在于底层实现的机制不同。
push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中
（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 emplace_back() 在实现时，
则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。

*/
class testDemo
{
    public:
        testDemo(int num):num(num) {
            std::cout << "调用构造函数" << std::endl;
        }
        testDemo(const testDemo& other) : num(other.num) {
            std::cout << "调用拷贝构造函数" << std::endl;
        }
        testDemo(testDemo&& other) :num(other.num) {
            std::cout << "调用移动构造函数" << std::endl;
        }
    private:
        int num;
};

int main()
{
    std::vector<char>value(3);

    for (auto i = value.begin(); i < value.end(); i++) {
        *i = 'S';
    }

    value.at(1) = 'T';
    value.at(2) = 'L';

    //value.push_back('S');
    //value.push_back('T');
    //value.push_back('L');

    printf("size: %d \n", value.size());

    for (auto i = value.begin(); i < value.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    value.insert(value.begin(), 'C');
    std::cout << "首个元素为：" << value.at(0) << std::endl;

    std::cout << "emplace_back:" << std::endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);

    std::cout << "push_back:" << std::endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);

    return 0;
}
#include <iostream>

using namespace std;

//mySwap函数模板声明
template<typename T> void mySwap(T &t1, T &t2);

//mySwap函数模板定义
template<typename T> void mySwap(T &t1, T &t2)
{
    T tmpT;

    cout << "t1:" << t1 << ", t2:" << t2 << endl;

    tmpT = t1;
    t1 = t2;
    t2 = tmpT;
}

//类模板声明
template <class T> class myStack {
    public:
        myStack();
        ~myStack();
        void push(T t);
        T pop();
        bool isEmpty();

    private:
        T *m_pT;
        int m_maxSize;
        int m_size;
};

//类实现
template <class T> myStack<T> :: myStack() {
    m_maxSize = 100;
    m_size = 0;
    m_pT = new T[m_maxSize];
}
template <class T> myStack<T> :: ~myStack() {
    delete [] m_pT;
}
template <class T> void myStack<T> :: push(T t) {
    m_size++;
    m_pT[m_size - 1] = t;
}
template <class T> T myStack<T> :: pop() {
    T t = m_pT[m_size - 1];
    m_size--;
    return t;
}
template <class T> bool myStack<T> :: isEmpty() {
    return m_size == 0;
}

int main(int argc, char* argv[])
{
    //使用mySwap函数模板
    //int类型
    int num1 = 1;
    int num2 = 2;
    //char类型
    char *name1 = "malixing";
    char *name2 = "wangjing";
    //string类型
    string str1 = "hello";
    string str2 = "world";

    mySwap<int>(num1, num2);
    cout << "num1: " << num1 << ", num2: " << num2 << endl;

    mySwap<char*>(name1, name2);
    cout << "name1:" << name1 << ", name2:" << name2 << endl;

    mySwap<string>(str1, str2);
    cout << "str1:" << str1 << ", str2:" << str2 << endl;

    //使用myStack类模板
    myStack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    while (!intStack.isEmpty()) {
        cout << "num:" << intStack.pop() << "  " ;
    }

    return 0;
}


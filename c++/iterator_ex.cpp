#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    //定义并初始化向量
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "第一种遍历方法： " << endl;
    //size返回元素个数
    for (int i = 0; i < v.size(); ++i)
    {
        //像普通数组一样使用vector容器
        cout << v[i] << " ";
    }

    //创建一个正向迭代器
    vector<int> :: iterator i;

    cout << endl << "第二种遍历方法： " << endl;
    //用！=比较两个迭代器
    for (i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl << "第三种遍历方法： " << endl;
    for (i = v.begin(); i < v.end(); ++i)
    {
        //用<比较两个迭代器
        cout << *i << " ";
    }

    cout << endl << "第四种遍历方法： " << endl;
    i = v.begin();
    while (i < v.end()) 
    {
        //间隔一个输出
        cout << *i << " ";
        //随机访问迭代器支持+=整数的操作
        i += 2;
    }

    return 0;
}
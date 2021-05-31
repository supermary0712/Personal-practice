#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*pair是一种简单的关联类型，不属于容器范围。而是代表一个 key-value键值对。

创建、初始化、操作 示例代码如下：*/

//将pair放入容器
int main (int argc, const char *argv[])
{
    vector<pair<string, int>> vec; //初始化vector

    pair<string, int> p1;
    p1.first = "hello";
    p1.second = 12;
    vec.push_back(p1);

    pair<string, int> p2("world", 22);
    vec.push_back(p2);

    vec.push_back(make_pair<string, int>("foo", 44));

    for(vector< pair<string, int> > :: iterator it = vec.begin();
        it != vec.end();
        ++it)
    {
        cout << "key: " << it->first << "; val: " << it->second << endl;
    }

    return 0;
}
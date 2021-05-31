#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
1）：map则是一个容器，里面存储的是 pair对象。但存储的方式与vector<pair>这种 连续存储有所不同， map采用的是 二叉排序树存储pair，一般是红黑树。

2）：map使用下标访问时，如果 key不存在，那么会在map 中自动添加一个新的pair，value为默认值。

性能分析：由于map采用二叉排序树（红黑树），树的高度不超过 [logN] +1。所以 插入和查询时间复杂度 为  O（lgN）；

注意：使用insert插入map元素时，如果失败，则不会更新原来的值。
*/
int main(int argc, const char *argv[])
{
    map<string, int> m;

    //数组方式插入数据
    m["beijing"] = 2000;
    m["hangzhou"] = 880;
    m["shanghai"] = 1500;

    //insert函数插入pair数据
    m.insert(pair <string, int> ("guangzhou", 1000));

    //insert函数插入value_type数据
    m.insert(map <string, int> ::value_type ("wuxi", 400));

    //修改map中value
    m["beijing"] = 2001;

    cout << "1 map size is :" << m.size() << endl;

    //删除map中值
    m.erase("guangzhou");

    cout << "2 map size is :" << m.size() << endl;

    for(map<string, int> :: const_iterator it = m.begin();
        it != m.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}


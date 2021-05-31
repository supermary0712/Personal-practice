#include <iostream>
#include <sstream>

using namespace std;

int main() 
{
    string test = "-123 9.87 welcome to, 989, test!";
    istringstream iss;
    iss.str(test);//将string类型的test复制给iss,返回void
    string s;

    cout << "按照空格读取字符串：" << endl;
    while (iss >> s) {
        cout << s << endl; //按空格读取string
    }
    cout << "*************************" << endl;

    istringstream strm(test);
    //创建存储test的副本的stringstream对象
    int i;
    float f;
    char c;
    char buff[1024];

    strm >> i;
    cout << "读取int类型：" << i << endl;
    strm >> f;
    cout << "读取float类型：" << f << endl;
    strm >> c;
    cout << "读取char类型：" << c << endl;
    strm >> buff;
    cout << "读取buffer类型：" << buff << endl;

    int j;
    strm >> j;
    cout << "忽略‘，’读取int类型：" << j << endl;

    system("pause");

    return 0;
}
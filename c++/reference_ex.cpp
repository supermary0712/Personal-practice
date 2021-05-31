#include <iostream>

using namespace std;

/*
  函数参数传递:
  值传递(单向值拷贝,只能将实参的值拷贝给形参, 实参与形参各自独占内存)
  引用传递 :实现的是引用传递(形参与实参共用内存), 实参与形参是同一个对象
*/
//函数声明，使用引用当作形参进行函数调用（引用传递，也称变量传递）
void swap_reference(int &x, int &y);
//函数声明，使用指针当作形参进行函数调用(值传递)
void swap_pointer(int *x, int *y);
//函数声明，直接使用int类型作为形参进行函数调用（值传递）
void swap(int x, int y);

//把引用作为返回值
double& setValues(int i);
/*
  声明全局变量用来测试引用作为返回值，
  当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，
  但是，可以返回一个对静态变量的引用。即：
  int& func() {
   int q;
   //! return q; // 在编译时发生错误
   static int x;
   return x;     // 安全，x 在函数作用域外依然是有效的
  }
*/
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

int main()
{
    int i = 0;
    double d = 0.0;
    int a = 100;
    int b = 200;

    //测试引用的作用，即变量的别名
    i = 5;
    d = 11.7;
    //声明引用变量
    int& r = i;
    double& s = d;
    /*
      打印变量i d 以及他们的引用的值和地址，
      从结果可以发现经过声明后r是i的别名，s是d的别名，具有同样的值，占内存中同一个存储单元，即具有同一地址。
      注意：&符号作为取地址符合作为引用声明符的区别，在上述程序中的第2行，&在数据类型后，为引用声明符。
      而第下面打印变量地址时为取地址符。可以用这个方法作区分：只有在数据类型后&才是引用声明符。
    */
    cout << "1=====================================1" << endl;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference :" << r << endl;
    cout << "Pointer of i is :" << &i << endl;
    cout << "Pointer of i reference is :" << &r << endl;

    cout << "Value of d :" << d << endl;
    cout << "Value of d reference :" << s << endl;
    cout << "Pointer of d is :" << &d << endl;
    cout << "Pointer of d reference is :" << &s << endl;

    /*
      测试变量名作为实参和形参进行函数调用
      这种方式传给形参的是变量的值，传递时单向的。即如果执行函数形参的值变了，
      不会回传给实参。如下测试结果可见。
    */
    cout << "2=====================================2" << endl;
    cout << "Before swap a is :" << a << endl;
    cout << "Before swap b is :" << b << endl;

    swap(a, b);

    cout << "After swap a is :" << a << endl;
    cout << "After swap b is :" << b << endl;

    //重新赋值
    a = 100;
    b = 200;

    /*
      测试形参为指针变量，实参时一个变量的地址，调用函数时，形参得到的是实参变量的地址，
      因此指向实参的变量单元。
      从结果来看，这种方式可以实现变量的交换，但是不够直观，而且依旧是“值传递”的方式，
      只不过传递的是变量的地址而已。
    */
    cout << "3=====================================3" << endl;
    cout << "Before swap a is :" << a << endl;
    cout << "Before swap b is :" << b << endl;

    swap_pointer(&a, &b);

    cout << "After swap a is :" << a << endl;
    cout << "After swap b is :" << b << endl;

    //重新赋值
    a = 100;
    b = 200;
    /*
      测试引用传参方式，即形参是声明的引用，注意这个引用并没有初始化，而在函数调用的过程中
      实现了引用的初始化，这时传入的实参就是变量，而不是数值，所以做到了真正意义上的“变量传递”。
      从结果看，这种方式也可以实现变量的交换。
    */
    cout << "4=====================================4" << endl;
    cout << "Before swap a is :" << a << endl;
    cout << "Before swap b is :" << b << endl;

    swap_reference(a, b);

    cout << "After swap a is :" << a << endl;
    cout << "After swap b is :" << b << endl;

    /*
      测试引用作为返回值，
      通过使用引用来替代指针，会使 C++ 程序更容易阅读和维护。C++ 函数可以返回一个引用，方式与返回一个指针类似。
      当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边。
    */
    cout << "5=====================================5" << endl;
    cout << "Before setValues the vals is :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = " << vals[i] << endl;
    }

    setValues(1) = 20.23; //改变第2个元素
    setValues(3) = 70.8;  //改变第4个元素

    cout << "After setValues the vals is :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = " << vals[i] << endl;
    }

    return 0;
}

//变量名作为实参和形参
void swap(int x, int y)
{
    int temp;

    cout << __func__ << " before x is :" << x << endl;
    cout << __func__ << " befoer y is :" << y << endl;

    temp = x;
    x = y;
    y = temp;

    cout << __func__ << " after x is :" << x << endl;
    cout << __func__ << " after y is :" << y << endl;

    return;
}

//传递变量的地址
void swap_pointer(int *x, int *y)
{
    int temp = 0;

    cout << __func__ << " before x is :" << *x << endl;
    cout << __func__ << " befoer y is :" << *y << endl;

    temp = *x;
    *x = *y;
    *y = temp;

    cout << __func__ << " after x is :" << *x << endl;
    cout << __func__ << " after y is :" << *y << endl;

    return;
}

//引用作为函数参数
void swap_reference(int &x, int &y)
{
    int temp;

    cout << __func__ << " before x is :" << x << endl;
    cout << __func__ << " befoer y is :" << y << endl;

    temp = x;
    x = y;
    y = temp;

    cout << __func__ << " after x is :" << x << endl;
    cout << __func__ << " after y is :" << y << endl;

    return;
}

//引用作为返回值
double& setValues(int i)
{
    //声明引用变量ref为vals[i]
    double& ref = vals[i];
     // 返回第 i 个元素的引用，ref 是一个引用变量，ref 引用 vals[i]，最后再返回 shit。
    return ref;
}
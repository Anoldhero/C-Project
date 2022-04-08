#include <iostream>
using namespace std;


class MyInteger
{
    friend ostream & operator<<(ostream &cout, MyInteger myint);
public:
    MyInteger()
    {
        m_Num = 0;
    }

private:
    int m_Num;

};

class Person
{

    friend ostream & operator<<(ostream &cout ,Person &p);
public:
    Person(int a,int b)
    {
        m_A = a;
        m_B = b;
    }
private:
    //成员函数重载
    // Person operator+(Person &p)
    // {
    //     Person temp;
    //     temp.m_A = this->m_A + p.m_A;
    //     temp.m_B = this->m_B + p.m_B;
    //     return temp;
    // }

    int m_A;
    int m_B;
};

/* 
//左移运算符重载
ostream & operator<<(ostream &cout ,Person &p)
{
    cout << "m_A = " << p.m_A << "  m_B = " << p.m_B ;
    return cout;
} 
*/

//解引用，为了对一个数据进行操作
//递增运算符重载  前置or后置

//前置
MyInteger & operator++()
{
    //先进行++运算
    m_Num++;

    //再将自身做一个返回
    return *this;
}

/* 
//返回值不可以满足函数重载条件
//后置
MyInteger operator++(int)        //int 为占位参数，可用于区分前置后置的递增
{
    //先 记录当时结果  
    MyInteger temp = *this;
    //后
    m_Num++;
    //最后返回记录结果
    return temp;
}
 */



//加号运算符重载
// Person operator+(Peson &p1,Person &p2)
// {
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp;
// }

void test01()
{
    // Person p1;
    // p1.m_A = 10;
    // p1.m_B = 10;
    // Person p2;
    // p2.m_A = 10;
    // p2.m_B = 10;

    //成员函数重载本质调用
    //Person p3 = p1.operator+(p2); 可简化为： Person p3 = p1 + p2;
    
    //全局函数重载本质调用
    //Person p3 = operator+(p1,p2);

    //运算符重载 也可发生 函数重载   
    //e.g. Person operator+(Peson &p1,int num){}
    Person p(10,10);
    //p.m_A = 10;
    //p.m_B = 10;
    cout << p <<  " hello world" << endl;

    // cout << "p3.m_A = " << p3.m_A << endl;
    // cout << "p3.m_B = " << p3.m_B << endl;

}


ostream & operator<<(ostream &cout, MyInteger myint)
{
    cout << myint.m_Num;
    return cout;
}

void test02()
{
    MyInteger myint;
    //cout << ++myint <<endl;
}

int main()
{
    test02();

    return 0;
}
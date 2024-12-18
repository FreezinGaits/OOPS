#include<iostream>
using namespace std;
/*
Syntax for initialization list in constructor:
constructor (argument-list) : initilization-section
{
    assignment + other code;
}
*/
class Test
{
    int a;
    int b;

public:
//	Test(int i, int j) : b(j), a(i+b) // Wrong -->RED Flag this will create provlems because a will be initialized first. a will throw garbage value.
//  it can work if we initalize b firstly and then a as: int b; int a;
	Test(int i, int j) : a(i), b(a + j) // Right
//	Test(int i, int j) : a(i), b(i + j) // Right
//    Test(int i, int j) : a(i), b(j) // Right
    {
        cout << "Constructor executed"<<endl;
        cout << "Value of a is "<<a<<endl;
        cout << "Value of b is "<<b<<endl;
    }
};

int main()
{
    Test t(4, 6);

    return 0;
}


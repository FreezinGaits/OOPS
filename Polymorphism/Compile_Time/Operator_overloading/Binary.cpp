#include <iostream>
using namespace std;

class test
{
    int a, b;

public:
    test()
    {
        a = 0;
        b = 0;
    }
    test(int x, int y)
    {
        a = x;
        b = y;
    }
    test operator+(test t);
    void display();
};

test test::operator+(test t)
{
    test temp;
    temp.a = a + t.a; // 10 + 30;
    temp.b = b + t.b; // 20 + 40;
    return temp;
}

void test::display()
{
    cout << a << " ";
    cout << b << endl;
}

int main()
{
    test t1, t2, t3;
    t1 = test(10, 20);
    t2 = test(30, 40);
    t3 = t1 + t2; // t3 = t1.add(t2);
    t1.display();
    t2.display();
    t3.display();
    return 0;
}
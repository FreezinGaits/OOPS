#include<iostream>
using namespace std;
//Forward declaration
class A;
class B{
    public:
    void show (A &a);
};
class A{
    int value;
    public:
    A(int value) : value(value){}
    friend class B;
};
void B::show(A &a){
    cout<<"Value of A: "<<a.value<<endl;
}
int main() {
    A a(30);
    B b;
    b.show(a);
    return 0;
}
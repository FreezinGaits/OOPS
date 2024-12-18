#include <iostream>
using namespace std;

class ClassA; // Forward declaration

class ClassB {
public:
    void show(ClassA& a);
};

class ClassA {
private:
    int data;

public:
    ClassA() : data(0) {}
    friend class ClassB; // Declare ClassB as a friend
};

void ClassB::show(ClassA& a) {
    cout << "ClassA data: " << a.data << endl; // Access private member of ClassA
}

int main() {
    ClassA a;
    ClassB b;
    b.show(a); // Output: ClassA data: 0
    return 0;
}

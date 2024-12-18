#include<iostream>
using namespace std;
class Box{
    int value;
    public:
    void cox(int value){
        this->value = value;
    }
    friend void Set(Box);
};

void Set(Box b){
    cout<<b.value<<endl;
}
int main() {
    Box b;
    b.cox(5);
    Set(b);
}
#include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
    Employee() {}
};

/*
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
	//class memberss/methods/etc...
}
Note:
1. Default visibility mode is private
2. Public visibility mode: Public members of the class becomes Public members of the derived class
3. Private visibility mode: Public members of the class becomes Private members of the derived class
4. Private members are never Inherited.
*/

// Creating a Programmer class derived from Employee Base class
class Programmer : Employee
{
public:
    int languageCode;
    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }
    void getData(){
        cout<<id<<endl;
    }
};
int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << skillF.languageCode<<endl;
//    cout << skillF.id<<endl; //Need the derived class to be public // Because we have inherited it privately.
    skillF.getData();
    return 0;
}

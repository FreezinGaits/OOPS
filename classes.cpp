#include<iostream>
#include<string>
using namespace std;
class Teacher {
    private:
    double salary;

    public:
    //Constructor:
    //Same name as class.
    //It doesn't have a return type.
    //constructor is only called once(automatically) at the time of object creation.
    //Always declare it in public because it gets called by main function automatically.
    //Memory allocation happens when constructor is called.
    Teacher() {
        cout<<"Hi, I'm a constructor\n";
        dept = "Computer Science";
    }
    //properties/attributes
    string name;
    string dept;
    string subject;

    //methods/member functions
    void changeDept(string newDept) {
        dept = newDept;
    }

//setter
    void setSalary(double s) {
        salary = s;
    }

//getter
    double getSalary() {
        return salary;
    }
};

int main()
{
    Teacher t1; // object of Teacher class //constructor call
    t1.name = "John Doe";
    // t1.dept = "Computer Science";
    t1.subject = "C++ Programming";
    t1.setSalary(25000);
    
    cout << "Teacher Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;//using constructor
    cout << "Subject: " << t1.subject << endl;
    cout << "Salary: $" << t1.getSalary() << endl;
    
    return 0;
}
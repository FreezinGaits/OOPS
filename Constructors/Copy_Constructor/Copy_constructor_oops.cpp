#include <iostream>
using namespace std;
class myClass
{
public:
	int value;
	myClass(int v)
	{
		value = v;
	}
	myClass(const myClass &obj)
	{
		cout << "Copy constructor is called !!!!!" << endl;
		value = obj.value;
	}
};
int main()
{
	myClass obj1(10), obj2(obj1);
	// myClass obj2 = obj1;
	cout << "obj1 value: " << obj1.value << endl;
	cout << "obj2 value: " << obj2.value << endl;
	return 0;
}

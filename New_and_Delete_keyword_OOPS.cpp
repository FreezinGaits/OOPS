#include<iostream>
using namespace std;

int main() {

	int a = 4;
	int* ptr = &a;
	cout<<"The value of a is "<<*(ptr)<<endl;

	cout<<"/*--------------------------------------------------------------------------*/\n";

	float *p = new float(40.78);
	cout << "The value at address p is " << *(p) << endl;

	cout<<"/*--------------------------------------------------------------------------*/\n";

	int *arr = new int[3];
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	cout << "The value of arr[0] is " << arr[0] << endl;
	cout << "The value of arr[1] is " << arr[1] << endl;
	cout << "The value of arr[2] is " << arr[2] << endl;

	cout<<"/*--------------------------------------------------------------------------*/\n";

	int *arr2 = new int[3];
	arr2[0] = 10;
	arr2[1] = 20;
	arr2[2] = 30;
	delete[] arr2;
	cout << "The value of arr2[0] is " << arr2[0] << endl;
	cout << "The value of arr2[1] is " << arr2[1] << endl;
	cout << "The value of arr2[2] is " << arr2[2] << endl;

	return 0;
}


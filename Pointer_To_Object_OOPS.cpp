#include<iostream>
using namespace std;

class Complex {
		int real, imaginary;
	public:
		void getData() {
			cout<<"The real part is "<< real<<endl;
			cout<<"The imaginary part is "<< imaginary<<endl;
		}

		void setData(int a, int b) {
			real = a;
			imaginary = b;
		}

};
int main() {
	Complex *ptr0 = new Complex;
	(*ptr0).setData(1, 2);
	(*ptr0).getData();

	Complex *ptr = new Complex;
	ptr->setData(3, 4);
	ptr->getData();

	// Array of Objects
//	Complex *ptr1 = new Complex[4];
//	ptr1->setData(5, 6);
//	ptr1->getData();

// Array of Objects
	Complex *ptr1 = new Complex[4];
	for (int i = 0; i < 4; i++) {
		ptr1[i].setData(i + 1, (i + 1) * 2);
		ptr1[i].getData();
	}
	// Free allocated memory
	delete ptr0;
	delete ptr;
	delete[] ptr1;
	return 0;
}


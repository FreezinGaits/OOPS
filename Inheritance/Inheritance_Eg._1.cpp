#include<iostream>
using namespace std;
class abc{
	public:
		int a;
		void getx(int x){
			a=x;
		}
};
class xyz:public abc{
	public:
		int b;
		void gety(int y){
			b=y;
		}
		int c;
		void calculateSum(){
			c=a+b;
		}
};
class pqr:public xyz{
	public:
		void show(){
			cout<<"The sum of a and b is: "<<c<<endl;
		}
};
int main()
{
	pqr obj;
	obj.getx(64);
	obj.gety(98);
	obj.calculateSum();
	obj.show();
	return 0;
}

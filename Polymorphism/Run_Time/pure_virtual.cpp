#include<iostream>
using namespace std;
class base{
	int b;
	public: 
	virtual void input()=0;
	virtual void output(){
	}
};
class derived:public base{
	int d;
	public:
		void input(){
			cout<<"Enter the value of d: ";
//			cin>>d;
		}
		void output(){
			cout<<"ddd";
		}
};
int main(){
	base *p;
	derived d1;
	p = &d1;
	p->input();
	p->output();
	return 0;
}

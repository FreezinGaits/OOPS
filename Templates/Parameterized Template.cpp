#include<iostream>
using namespace std;
template<class T1 = int, class T2 = char>
class myClass{
	public:
		T1 data1; //int
		T2 data2; //char
		myClass(T1 a, T2 b){
			data1 = a;
			data2 = b;
		}
		
		void display(){
			cout<<this->data1<<"\t"<<this->data2<<endl<<endl;
		}
};
int main(){
	myClass<> obj(1, 'c');
	myClass<float, int> obj2(1.565, 43);
	obj.display();
	obj2.display();
	return 0;
}

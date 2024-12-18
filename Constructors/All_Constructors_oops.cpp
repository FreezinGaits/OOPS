#include<iostream>
#include<string>
using namespace std;
class Person{
	private: 
		string name;
		int age;
		float height;
	public:
//		Person(){
//			name = "NULL";
//			age = 0;
//			height = 0.0f;
//		}
		Person(string name_a = "NULL", int age_a = 0, float height_a = 0.0f){
			name = name_a;
			age = age_a;
			height = height_a;
		}
		Person(Person &obj_2){
			name = obj_2.name;
			age = obj_2.age;
			height = obj_2.height;
		}
		void getData(){
			cout<<endl<<"Name: "<<name;
			cout<<endl<<"Age: "<<age;
			cout<<endl<<"Height: "<<height;
		}
};

int main(){
	Person obj, obj_2("Gautam", 19, 170), obj_3(obj_2);
	obj.getData();
	obj_2.getData();
	obj_3.getData();
	return 0;
}

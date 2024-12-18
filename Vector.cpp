#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& v){
	for(int i=0; i<v.size(); i++){
//		cout<<v[i]<<"\t";
		cout<<v.at(i)<<"\t"; //does the same working.
	}
}
int main(){
	vector<int> vec1; //vector of size 0
	vector<int> vec2(3); //vector of size 3
	vector<int> vec3(vec2); 
	vector<int> vec4(6, 3); // 333333
//	int element, size;
//	cout<<"Enter the size of the vector: ";
//	cin>>size;
//	for(int i=0; i<size; i++){
//		cout<<"Enter the element to add into vector: ";
//		cin>>element;
//		vec1.push_back(element);
//	}
//	vec1.pop_back();
//	vector<int>::iterator iter = vec1.begin();
//	vec1.insert(iter, 2, 999);
//	display(vec1);
	display(vec4);
	cout<<vec1.size();
	return 0;
}

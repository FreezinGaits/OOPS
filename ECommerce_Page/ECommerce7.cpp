#include<iostream>
using namespace std;
int main(){
	char startValue;
	float onlineShopping(void);
	cout<<"Press 's' to Start Shopping."<<endl;
	cin>>startValue;
	start:
	if(startValue == 's' || startValue == 'S'){
		float totalAmount = onlineShopping();
	}
	else{
		cout<<"You have Entered wrong character, Please Enter 's'"<<endl;
		goto start;
	}
}

float onlineShopping(){
	char choice;
	char item;
	int quantity;
	float billAmount = 0;
	cout<<"****************************** WELCOME TO MYNTRA ******************************"<<endl;
	cout<<"--------------------------- FOLLOW THE INSTRUCTIONS ---------------------------"<<endl;
	
	cout<<"(1) Enter 'm' to order Mobile Phones"<<endl;
	cout<<"(2) Enter 'l' to order Laptops"<<endl;
	cout<<"(3) Enter 'd' to order Desktops"<<endl;
	cout<<"(4) Enter 's' to order Speaker"<<endl;
	cout<<"(5) Enter 'h' to order HeadPhones"<<endl;
	cin>>choice;
	
	if(choice == 'm' || choice == 'M'){
		cout<<"Mobile details"<<endl;
		cout<<"(1) Apple   =>  Price  :  40000"<<endl;
		cout<<"(2) Apple   =>  Price  :  40000"<<endl;
		cout<<"(3) Apple   =>  Price  :  40000"<<endl;
		cout<<"(4) Apple   =>  Price  :  40000"<<endl;
		cout<<"(5) Apple   =>  Price  :  40000"<<endl;
		cout<<"(6) Apple   =>  Price  :  40000"<<endl;
		cout<<"Please Enter your choice: "<<endl;
		cin>>item;
		if(item == '1'){
			cout<<"Enter quantity: "<<endl;
			cin>>quantity;
			billAmount = billAmount+ quantity*40000;
		}
	}
}

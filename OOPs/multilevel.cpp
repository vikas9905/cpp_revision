#include<iostream>
using namespace std;
class Base1{
	Base1(){
		cout<<"Constructor of Base";
	}
};
class Base2:public Base1{
	Base2(){
		cout<<"Base2\n";
	}
};
class derive:public Base2{
	derive(){
		cout<<"Derive\n";
	}
};
int main(){
	derive obj;
}
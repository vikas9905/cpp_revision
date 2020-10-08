#include<iostream>
using namespace std;
class Base{

public:
	Base(){
		cout<<"Base class constructor\n";
	}
};

class Base2{
public:
	Base2(){
		cout<<"Base2 class constructor";
	}
};
class derive:public Base,public Base2{
public:
	derive(){
		cout<<"derive class constructor";
	}
}
int main(){
	derive obj;
}
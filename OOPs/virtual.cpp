#include<bits/stdc++.h>
using namespace std;
class Base{
public:
	Base(){
		cout<<"Base Class Called\n";
	}
	void virtual fun(int i,int j){
	   cout<<i*j<<"\n";
	}
	void show(){
		cout<<"Method of Base Class\n";
	}
};
class derived:public Base
{
public:
	derived(){
		cout<<"In derived class\n";
	}

};
int main(){
	derived obj;
	Base *b=&obj;
	b->fun(9,8);
	obj.show();
	return 0;

}

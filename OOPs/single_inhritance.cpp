#include<iostream>
using namespace std;
class Base{
   public:
   	Base(){
   		cout<<"Base class constructor\n";
   	}
};
class derive:public Base{
    public:
    derive(){
    	cout<<"constructor in derived\n";

    }
};
int main(){

	derive obj;
}

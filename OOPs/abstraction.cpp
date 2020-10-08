#include<iostream>
using namespace std;
class Base{
private:
	int a, b;
    public:

    	void SetData(int a,int b){
    		this->a=a;
    		this->b=b;
    	}
    	void mul(){
    		cout<<this->a*this->b<<"\n";
    	}

};
int main(){
	Base obj;
	obj.SetData(9,8);
	obj.mul();
	return 0;

}

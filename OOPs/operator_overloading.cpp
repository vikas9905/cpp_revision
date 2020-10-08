#include<bits/stdc++.h>
using namespace std;

class complex{
private:
	int real,imag;
public:
	complex(int r=0,int i=0){
		this->real=r;
		this->imag=i;
	}
	complex operator +(complex const &obj){
		complex res;
		res.real=real+obj.real;
		res.imag=imag+obj.imag;
		retur res;
	}
	void print(){
		cout<<real<<" +i"<<imag<<"\n";
	}
};

int main(){
  complex c1(10,5),c2(2,4);
  complex c3=c1+c2;
  c3.print()
}
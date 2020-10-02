#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<s1+s2<<"\n";
	s1.append(s2);
	cout<<s1<<"\n";
	s1.insert(5,"mishra");
	cout<<s1<<"\n";
	cout<<s1.substr(2,5);


}

#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
    cin>>s;
	bool val=next_permutation(s.begin(),s.end());
	while(val){
        cout<<s<<"\n";
        val=next_permutation(s.begin(),s.end());
	}
}

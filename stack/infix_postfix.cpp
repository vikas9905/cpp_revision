#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	stack<char>st;
	st.push('N');
	int len=s.length();
	int i=0;
	string ns;
	while(i<l){
		if((s[i]>='a' && s[i]<='z') && (s[i]>='A' && s[i]<='Z')){
			ns+=s[i];
		}
		else if(s[i]=='(' || s.empty()){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			while(s[i]!='(' && !s.empty()){
				ns+=st.top();
				st.pop();
			}
		}
		else{
			if(prec(s[i])>prec(st.top())){
				s.push(s[i]);
			}
			else{
				while(st.top()!=')')
			}
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
int main(){

	int n;
	cin>>n;
	multimap<int,int>mp;
	for(int i=0;i<n;i++){
		int key,val;
		cin>>key>>val;
		mp.insert({key,val});
	}
	multimap<int,int>::iterator i;
	for(i=mp.begin();i!=mp.end();i++){
		cout<<i->first<<" "<<i->second<<"\n";
	}
	//lower and upper bound in mutimap
	//lower bound for key 5
	cout<<mp.lower_bound(6)->first<<" "<<mp.lower_bound(6)->second<<"\n";
//	cout<<mp.at(4)->first<<" "<<mp.at(4)->second<<"\n";
}

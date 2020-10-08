#include<bits/stdc++.h>
using namespace std;

int Hist_area(vector<int>arr,int n){
	stack<int>s;
	int area_with_top;
	int max_are=0;
	int tp;
	int i=0;
	while(i<n){
		if(s.empty() || arr[i]>=arr[s.top()]){
			s.push(i++);
		}
		else{
			tp=s.top();
			s.pop();
			area_with_top=arr[tp]*((s.empty())? i:i-s.top()-1);
			if(area_with_top>max_are){
				max_are=area_with_top;
			}
		}
	}
	while(!s.empty()){
		int tp=s.top();
		s.pop();
		area_with_top=arr[tp]*((s.empty())?i:i-s.top()-1);
		if(max_are<area_with_top)
			max_are=area_with_top;
	}
	return max_are;
}

int main(){
	vector<int>arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}
	int ans=Hist_area(arr,n);
	cout<<ans<<"\n";
}
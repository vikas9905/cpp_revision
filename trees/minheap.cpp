#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}
	minheap(arr);
}
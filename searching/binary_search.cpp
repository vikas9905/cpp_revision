#include<bits/stdc++.h>
using namespace std;

int binary_search(int *arr,int n,int data){
	int low=0,hi=n-1;
	while(low<=hi){
		int mid=lo+(hi-low)/2;
		if(arr[mid]==data)
			return 1;
		if(arr[mid]>data){
			hi=mid-1;
		}
		else if(arr[mid]<data)
			low=mid+1;
	}
	return -1;
	
}

int main(){
	int n;
	cin>>n;
	int *arr=new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int data;
	cin>>data;
	cout<<binary_search(arr,n,data);
}
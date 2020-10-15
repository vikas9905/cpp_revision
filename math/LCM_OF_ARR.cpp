#include<bits/stdc++.h>
using namespace std;

int LCM(int a,int b){
	int lcm=a;
	while(1){
		if(lcm%b==0 && lcm%a==0){
			break;
		}
		lcm++;
	}
	return lcm;
}

void calculate_lcm(int *arr){
	int res=arr[0];
	for(int i=1;i<arr.length;i++){
		res=LCM(res,arr[i]);
	}
	cout<<res;
}
int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	calculate_lcm(arr);
}
#include<bits/stdc++.h>
using namespace std;

int ceil_ind(int*,int,int,int);

void LIS(int *arr,int n){
    int table[n];
    memset(table,0,sizeof table);
    table[0]=arr[0];
    int s=1;
    for(int i=1;i<n;i++){
        if(arr[i]<table[0]){
            table[0]=arr[i];
        }
        else if(arr[i]>table[s-1]){
            table[s]=arr[i];
            s+=1;
        }
        else{
            table[ceil_ind(table,-1,s-1,arr[i])]=arr[i];
        }
    }
  cout<<"LIS SIZE IS "<<s<<"\n";
  for(int i=0;i<s;i++){
    cout<<table[i]<<" ";
  }
}

int ceil_ind(int table[],int l,int r,int key){
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(table[mid]>=key){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return r;

}

int main(){
   int n;
   cin>>n;
   int *arr=new int[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   LIS(arr,n);
 return 0;
}

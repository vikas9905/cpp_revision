#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(arr[i]<arr[j]){
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}

int main(){
   int n;
   cin>>n;
   int *arr=new int[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   bubble_sort(arr,n);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   return 0;
}

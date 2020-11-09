// is subset of array sum is equal to given sum;

#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int *arr,int n,int sum){
     int dp[n+1][sum+1];
     for(int i=0;i<=n;i++){
        dp[i][0]=true;
     }
     for(int i=1;i<=sum;i++){
        dp[0][i]=false;
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else if(arr[i-1]<j){
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
     }
    return dp[n][sum];
}

int main(){
   int n,sum;
   cin>>n>>sum;
   int *arr=new int[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   cout<<subset_sum(arr,n,sum);
   return 0;
}

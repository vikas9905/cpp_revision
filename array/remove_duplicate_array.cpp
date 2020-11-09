/*#include<bits/stdc++.h>
using namespace std;

int *deleteArr(int *arr,int len){
     for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(arr[i]==arr[j]){
                for(int k=j;k<len-1;k++){
                    arr[k]=arr[k+1];
                }
                len-=1;
                j-=1;
            }
        }
     }
     return arr;
}

int main(){
   int arr[]={2,3,2,2,5,6,6,7};
   int len=8;
   int *res=deleteArr(arr,len);
   for(int i=0;i<4;i++){
    cout<<res[i]<<" ";
   }
   return 0;
}
*/
  res=1/(float)(positiveExponent(basevalue,abs(exponentValue)));
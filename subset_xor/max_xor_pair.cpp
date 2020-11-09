#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* left;
    TrieNode* right;

};

void Insert(TrieNode *head,int n){
    TrieNode *curr=head;
    for(int i=31;i>=0;i--){
        int b=(n>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left=new TrieNode();
            }
            curr=curr->left;
        }
        else{
            if(!curr->right){
                curr->right=new TrieNode();
            }
            curr=curr->right;
        }
    }
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();

        TrieNode *head=new TrieNode();
        for(int i=0;i<n;i++){
            Insert(head,nums[i]);
        }
        int max_xor=INT_MIN;
        for(int i=0;i<n;i++){
            TrieNode* curr=head;
            int curr_xor=0;
            int val=nums[i];
            for(int j=31;j>=0;j--){
                int b=(val>>j)&1;
                if(b==0){
                    if(curr->right){
                        curr_xor+=pow(2,j);
                        curr=curr->right;
                    }else{
                        curr=curr->left;
                    }
                }
                else{
                    if(curr->left){
                        curr_xor+=pow(2,j);
                        curr=curr->left;
                    }
                    else{
                        curr=curr->right;
                    }
                }
            }
            if(curr_xor>max_xor){
                max_xor=curr_xor;
            }
        }
        
        return max_xor;
    }
};

int main(){
   int n;
   cin>>n;
   vector<int>arr;
   for(int i=0;i<n;i++){
     int num;
     cin>>num;
     arr.push_back(num);
   }
   TrieNode *head=new TrieNode();
   for(int i=0;i<n;i++){
      Insert(head,arr[i]);
   }
   Solution obj;
   cout<<obj.findMaximumXOR(arr);
}

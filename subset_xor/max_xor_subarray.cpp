#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
	TrieNode* left;
	TrieNode* right;
};

void Insert(int n,TrieNode* head){
	TrieNode* curr=head;
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

int query(TrieNode* head,int preXOR){
	TrieNode* curr=head;
	int curr_xor=0;
	for(int i=31;i>=0;i--){
		int b=(preXOR>>i)&1;
		if(b==0){
			if(curr->right){
				curr_xor+=pow(2,i);
				curr=curr->right;
			}else{
				curr=curr->left;
			}
		}
	}
	return preXOR^(curr_xor);
}

int MaxSubarrayXOR(vector<int>&arr){
	int n=arr.size();
	TrieNode* head=new TrieNode();
	int preXOR=0;
	int res=INT_MIN;
	for(int i=0;i<n;i++){
		preXOR^=arr[i];
		Insert(preXOR,head);
		res=max(res,query(head,preXOR));
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}

	cout<<MaxSubarrayXOR(arr);
	return 0;
}

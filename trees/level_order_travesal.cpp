#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *new_node(int data){
   Node *tmp=new Node();
   tmp->data=data;
   tmp->left=NULL;
   tmp->right=NULL;
   return tmp;
}

void level_order(Node *root,vector<vector<int>>&ans){
	if(root==NULL)
		return;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		queue<Node*>tmp;
		vector<int>temp;
		while(!q.empty()){
			Node* tp=q.front();
			q.pop();
			if(tp->left!=NULL)
				tmp.push(tp->left);
			if(tp->right!=NULL)
				tmp.push(tp->right);
			temp.push_back(tp->val);
		}
		ans.push_back(temp);
		q=tmp;
	}
}

void print_level(vector<vector<int>>ans){
	for(int i=0;i<ans.size();i++){
		for(auto j:ans[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	int n;
	cin>>n;
	Node *root=NULL;
	queue<Node*>q;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}
	root=new_node(arr[0]);
	q.push(root);
	int j=1;
	while(j<n){
		Node *tp=q.front();
		q.pop();
		if(tp->left==NULL){
			tp->left=new_node(arr[j]);
			q.push(tp->left);
			j+=1;
		}
		if(tp->right==NULL){
			tp->right=new_node(arr[j]);
			q.push(tp->right);
			j+=1;
		}

	}
	vector<vector<int>>ans;
	level_order(root,ans);
	print_level(ans);
}

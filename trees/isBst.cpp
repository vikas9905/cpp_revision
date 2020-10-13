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

bool check_BST(Node *root,Node *l,Node *r){
	if(root==NULL)
		return true;
	if(l!=NULL && root->data<=l->data)
		return false;
	if(r!=NULL && root->data>=r->data)
		return false;
	return check_BST(root->left,l,root) && check_BST(root->right,root,r);
}

bool isBST(Node *root){
	return check_BST(root,NULL,NULL);
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
	cout<<isBST(root);
}

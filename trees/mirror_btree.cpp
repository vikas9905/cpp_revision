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
void invert(Node *root){
     if(root==NULL)
        return;
     ;
     invert(root->left);
     invert(root->right);
     swap(root->left,root->right);
}
void Inorder(Node *root){
	if(root==NULL)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
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
	Inorder(root);
	invert(root);
	Inorder(root);
}

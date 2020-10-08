#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *new_node(int data){
	Node *tmp=new Node();
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->data=data;
	return tmp;
}

Node *Insert(Node *start,int data){
	if(start==NULL){
		return new_node(data);
	}
	else if(start->data>data){
		start->left=Insert(start->left,data);
	}
	else{
		start->right=Insert(start->right,data);
	}
}

void traverse(Node *tmp,int s=0){
	if(tmp==NULL)
		return;
	traverse(tmp->right,s);
	cout<<tmp->data+s;
	traverse(tmp->left,s);
}

int main(){
	int n;
	cin>>n;
	Node *start=NULL;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		start=Insert(start,num);
	}
	traverse(start);
}
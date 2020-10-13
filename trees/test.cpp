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

int subtree_sum(Node* root,int &suml,int &sumr){
	if(root==NULL){
		return 0;
	}
	suml+=subtree_sum(root->left,suml,sumr);
	sumr+=subtree_sum(root->right,suml,sumr);
	return max(suml+root->data*sumr,suml*(sumr+root->data))
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
	int suml=sumr=1;
	cout<<subtree_sum(root,suml,sumr);
	cout<<"\n"<<
}

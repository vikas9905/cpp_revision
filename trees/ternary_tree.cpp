#include<bits/stdc++.h>
using namespace std;
struct TernaryTree{
	char data;
	int isEnd;
	TernaryTree *left,*right,*mid;
};
TernaryTree *new_node(char data){
	TernaryTree *tmp=new TernaryTree();
	tmp->data=data;
	tmp->left=tmp->right=tmp->mid=NULL;
	tmp->isEnd=0;
	return tmp;
}

void Insert(TernaryTree **root,char *word){
	if(!(*root)){
		*root=new_node(*word);
	}
	if((*root)->data>(*word)){
		Insert(&((*root)->left),word);
	}
	else if((*root)->data<(*word)){
		Insert(&((*root)->right),word);
	}
	else{
		if(*word+1){
			Insert(&((*root)->mid),word+1);
		}
		else{
			(*root)->isEnd=1;
		}
	}
}

void TraverseUtil(TernaryTree *root,char *arr,int d){
	if(root){
		TraverseUtil(root->left,arr,d);
		arr[d]=root->data;
		if(root->isEnd){
			arr[d+1]='\0';
			cout<<arr<<"\n";
		}
		TraverseUtil(root->mid,arr,d+1);
		TraverseUtil(root->right,arr,d);
	}
}

void Traverse(TernaryTree *root){
	char arr[500];
	TraverseUtil(root,arr,0);
}

int main(){
	int n;
	cin>>n;
	TernaryTree *root=NULL;
	for(int i=0;i<n;i++){
		char *str;
		cin>>str;
		Insert(&root,str);
	}
	Traverse(root);
}

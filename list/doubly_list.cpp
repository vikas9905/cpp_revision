#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node *prev;
};

Node *Insert(Node *start,int data){
	if(start==NULL){
		Node *tmp=new Node();
		tmp->data=data;
		tmp->next=NULL;
		tmp->prev=NULL;
		return tmp;
	}
	Node *p=start;
	while(p->next){
		p=p->next;
	}
	Node *tmp=new Node();
	tmp->data=data;
	tmp->next=NULL;
	tmp->prev=p;
	p->next=tmp;
	return start;
}

void traverse(Node *start){
	while(start){
		cout<<start->data<<"->";
		start=start->next;
	}
}

void traverse_reverse(Node *start){
	Node *p=start;
	while(p->next){
		p=p->next;
	}
	while(p->prev){
		cout<<p->data<<"->";
		p=p->prev;
	}
}

int main(){
	int n;
	cin>>n;
	Node *start=NULL;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		start=Insert(start,data);
	}
	traverse(start);
	traverse_reverse(start);
}

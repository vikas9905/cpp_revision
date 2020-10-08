#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};

Node* Insert(Node *head,int data){
	if(head==NULL){
		Node *tmp=new Node();
		tmp->data=data;
		tmp->next=NULL;
		return tmp;
	}
	Node *p=head;
	while(p->next){
		p=p->next;
	}
	Node *tmp=new Node();
	tmp->data=data;
	tmp->next=NULL;
	p->next=tmp;
	return head;

}

void traverse(Node *start){
	while(start){
		cout<<start->data<<"-> ";
		start=start->next;
	}
}
Node *Insert_pos(Node *start,int pos,int data){
	if(pos==0){
		Node *tmp=new Node();
		tmp->data=data;
		tmp->next=start;
		return tmp;
	}
	pos=pos-2;
	int i=0;
	Node *p=start;
	while(i!=pos && p){
		i+=1;
		p=p->next;
	}
	Node *tmp=new Node();
	tmp->data=data;
	Node *var=p->next;
	p->next=tmp;
	tmp->next=var->next;
	var->next=NULL;
	free(var);
	return start;
}

Node *del_ele(Node *start,int data){
	if(start->data==data){
		Node *p=start->next;
		start->next=NULL;
		free(start);
		return p;
	}
	Node *p=start;
	while(p->next){
		if(p->next->data!=data)
			p=p->next;
		else
			break;
	}
	if(p==NULL){
		cout<<"data not found";
	 	return start;
	 }
	Node *tmp=p->next;
	p->next=p->next->next;
	tmp->next=NULL;
	free(tmp);
	return start;
}

int main(){
	Node* start=NULL;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin>>data;
		start=Insert(start,data);
	}
	traverse(start);
	cout<<"Enter pos to insert\n";
	int pos,data;
	cin>>pos>>data;
	start=Insert_pos(start,pos,data);
	traverse(start);
	cout<<"Enter element to delete\n";
	int ele;
	cin>>ele;
	start=del_ele(start,ele);
	traverse(start);
}
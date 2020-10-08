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

Node *reverse_list(Node *start){
	Node *prev=NULL,*curr=start,*next=NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
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
	cout<<"enter node to swap\n";
	int n1,n2;
	cin>>n1>>n2;
	start=reverse_list(start);
	traverse(start);
	return 0;
}
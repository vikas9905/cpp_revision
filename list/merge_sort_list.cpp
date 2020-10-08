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

void split(Node *start,Node **a,Node **b){
	Node *slow=start,*fast=start->next;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	*a=start;
	*b=slow->next;
	slow->next=NULL;
}

Node *sorted_merge(Node *a,Node *b){
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	Node *result;
	if(a->data<=b->data){
		result=a;
		result->next=sorted_merge(a->next,b);
	}
	else{
		result=b;
		result->next=sorted_merge(a,b->next);
	}
	return result;
}

void *mergesort_list(Node **head){
    Node *start=*head;
	if(start==NULL || start->next==NULL)
		return start;
	Node *a,*b;
	split(start,&a,&b);
	mergesort_list(&a);
	mergesort_list(&b);
	*head=sorted_merge(a,b);
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
	mergesort_list(&start);
	traverse(start);
	return 0;
}

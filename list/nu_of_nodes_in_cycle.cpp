#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
}

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

};

int count_node(Node *head){
	Node *p=head;
	int c=1;
	while(p->next!=head){
		c+=1;
		p=p->next;
	}
	return c;
}

int cnt_loop(Node *start){
	if(start==NULL)
		return 0;
	Node *slow_ptr,*fast_ptr;
	slow_ptr=start;
	fast_ptr=start;
	while(slow_ptr && fast_ptr && fast_ptr->next){
		slow_ptr=slow_ptr->next;
		fast_ptr=fast_ptr->next->next;
		if(slow_ptr==fast_ptr){
			return count_node(slow_ptr);
			break;
		}
	}
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
	start->next->next->next->next-next=start->next;
	cout<<cnt_loop(start);
}
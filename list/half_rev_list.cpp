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

Node reverse(Node *start){
	Node *prev=NULL,*curr=start,*next=NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

Node *reverse_list(Node *start){
	int n=0,mid;
	Node *tmp=start;
	while(tmp){
		n+=1;
		tmp=tmp->next;
	}
	if(n%2==0){
		mid=n/2;
	}
	else{
		mid=n/2+1;
	}
	int i=0;
	Node *curr=start;
	while(i<mid){
		curr=curr->next;
		i+=1;
	}
	Node *mid_node=curr->next;
	Node *list1=start;
	curr->next=NULL;
	Node *list2=mid_node->next;
	mid_node->next=NULL;
	Node *tmp=reverse(list1);
	Node *curr=tmp;
	Node *tmp2=reverse(list2);
	while(curr->next){
		curr=curr->next;
	}
	curr->next=mid_node;
	mid_node->next=tmp2;
	return tmp;
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
	start=reverse_list(start);
	traverse(start);
	return 0;
}
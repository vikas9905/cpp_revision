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

Node *swap_node(Node *start,int n1,int n2){
	if(x==y){
		return;
	}
	Node *prevx=NULL,*currx=start;
	while(currx && currx->data!=n1){
		prevx=currx;
		currx=currx->next;
	}
	Node *prevy=NULL,*curry=start;
	while(curry && curry->data!=n2){
		prevy=curry;
		curry=curry->next;
	}
	if(curry==NULL || currx==NULL)
		return;
	if(prevx!=NULL)
		prevx->next=curry;
	else
		start=prevx;
	if(prevy!=NULL)
		prevy->next=currx;
	else
		start=prevy;
	Node *tmp=curry->next;
	curry->next=currx->next;
	currx->next=tmp;
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
	cout<<"enter node to swap\n";
	int n1,n2;
	cin>>n1>>n2;
	start=swap_node(start,n1,n2);
	traverse(start);
	return 0;
}
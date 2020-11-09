#include<bits/stdc++.h>
using namespace std;
struct Node{
     int data;
     Node *next;

};
Node *top=NULL;
void push(int data){
    Node *tmp=new Node();
    tmp->data=data;
    tmp->next=top;
    top=tmp;
}

int isEmpty(){
   return top==NULL;
}

int peek(){
   if(!isEmpty()){
      return top->data;
   }
   else{
    exit(1);
   }
}
int pop(){
    Node *temp;
    if(top==NULL){
        cout<<"Underflow\n";
        return 0;
    }
    else{
        temp=top;
        int d=temp->data;
        top=top->next;
        temp->next=NULL;
        free(temp);
        return d;
    }

}

void display(){
    if(top==NULL){
        cout<<"Underflow\n";
    }
    else{
        Node *p=top;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
}

int main(){

   cout<<"Enter -1 to exit/n";

   while(1){
      int num;
      cin>>num;
      if(num==-1)
        break;
      push(num);
   }
   cout<<pop();
   cout<<peek();

}

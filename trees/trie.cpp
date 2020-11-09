#include<bits/stdc++.h>
using namespace std;
struct Node{
     int isEnd;
     Node *children[26];

};

Node* get_node(){
    Node *tmp=new Node();
    tmp->isEnd=0;
    memset(tmp->children,NULL,sizeof(tmp->children));
    return tmp;
}
void Insert(string s,Node *root){
    Node *p=root;
    for(int i=0;i<s.length();i++){
         int ind=s[i]-'a';
        if(!p->children[ind]){
            p->children[ind]=get_node();
        }
        p=p->children[ind];
    }
    p->isEnd=1;
}

bool search(string s,Node* root){
     Node *p=root;
     for(int i=0;i<s.length();i++){
        int ind=s[i]-'a';
        if(!p->children[ind]){
            return false;
        }
        p=p->children[ind];
     }
    return (p!=NULL && p->isEnd);
}


int main(){
    int n;
    cin>>n;
    vector<string>arr;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    Node *root=get_node();
    for(int i=0;i<n;i++){
        Insert(arr[i],root);
    }
    string s;
    cin>>s;
    cout<<search(s,root);
}

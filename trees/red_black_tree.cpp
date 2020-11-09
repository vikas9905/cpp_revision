#include<bits/stdc++.h>
using namespace std;

enum color{RED,BLACK};

struct Node{
	int data;
	bool color;
	Node *left,*right,*parent;
	Node(int data){
		this->data=data;
		left=right=parent=NULL;
		this->color=RED;
	}
}

class RBTree{
   private:
   	Node *root;
   protected:
   	void rotateLeft(Node *&,Node *&);
   	void rotateRight(Node*&,Node *&);
   	void fix(Node *&,Node*&);
   public:
   	RBTree(){
   		root=NULL;
   	}
   	void Insert(int &n);
   	void Inorder();
   	void levelOrder();

};

void inorderHelper(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    inorderHelper(root->left); 
    cout << root->data << "  "; 
    inorderHelper(root->right); 
} 
void levelOrderHelper(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    std::queue<Node *> q; 
    q.push(root); 
  
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        cout << temp->data << "  "; 
        q.pop(); 
  
        if (temp->left != NULL) 
            q.push(temp->left); 
  
        if (temp->right != NULL) 
            q.push(temp->right); 
    } 
} 

void RBTree::rotateLeft(Node *&root,Node *&pt){
	Node *pt_right = pt->right; 
  
    pt->right = pt_right->left; 
  
    if (pt->right != NULL) 
        pt->right->parent = pt; 
  
    pt_right->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_right; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_right; 
  
    else
        pt->parent->right = pt_right; 
  
    pt_right->left = pt; 
    pt->parent = pt_right; 
}
void RBTree::rotateRight(Node *&root, Node *&pt) 
{ 
    Node *pt_left = pt->left; 
  
    pt->left = pt_left->right; 
  
    if (pt->left != NULL) 
        pt->left->parent = pt; 
  
    pt_left->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_left; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_left; 
  
    else
        pt->parent->right = pt_left; 
  
    pt_left->right = pt; 
    pt->parent = pt_left; 
} 
  

Node *BSTInsert(Node *root,Node *tmp){
	if(root==NULL)
		return tmp;
	if(tmp->data<root->data){
		root->left=BSTInsert(root->left,tmp);
		root->left->parent=root;
	}
	else if(root->data<tmp->data){
		root->right=BSTInsert(root->right,tmp);
		root->right->p=root;
	}
	return root;
}

void RBTree::fix(Node *&root,Node *&tmp){
	Node *parent_tmp=NULL;
	Node *grand_parent_tmp=NULL;
	while((tmp!=root)&&(tmp->color!=BLACK)&&(tmp->parent->color==RED)){
		parent_tmp=tmp->parent;
		grand_parent_tmp=tmp->parent->parent;
		//CASE A 
		if(parent_tmp==grand_parent_tmp->left){
			Node *uncle_pt=grand_parent_tmp->right;
			if(uncle_pt!=NULL && uncle_pt->color==RED){
				grand_parent_tmp->color=RED;
				parent_tmp->color=BLACK;
				uncle_pt->color=BLACK;
				tmp=grand_parent_tmp;
			}
			else{
				if(tmp==parent_tmp->right){
					rotateLeft(root,parent_tmp);
					tmp=parent_tmp;
					parent_tmp=tmp->parent;
				}
				rotateRight(root,grand_parent_tmp);
				swap(parent_tmp->color,grand_parent_tmp->color);
				tmp=parent_tmp;
			}
		}
		else{
			Node *uncle_pt=grand_parent_tmp->left;
			if((uncle_pt!=NULL)&&(uncle_pt->color==RED)){
				grand_parent_tmp->color=RED;
				parent_tmp->color=BLACK;
				uncle_pt->color=BLACK;
				tmp=grand_parent_tmp;
			}
			else{
				if(pt==parent_tmp->left){
					rotateRight(root,parent_tmp);
					pt=parent_tmp;
					parent_tmp=tmp->parent;
				}
				rotateLeft(root,grand_parent_tmp);
				swap(parent_tmp->color,grand_parent_tmp->color);
				tmp=parent_tmp;
			}
		}
	}
	root->color=BLACK;
}

void RBTree::Insert(int &n){
	Node *tmp=new Node();
	root=BSTInsert(root,tmp);
	fix(root,tmp);
}
void RBTree::inorder()     {  inorderHelper(root);} 
void RBTree::levelOrder()  {  levelOrderHelper(root); } 

int main(){
	int n;
	cin>>n;
	RBTree tree;
	while(n--){
		int num;
		cin>>num;
		tree.Insert(num);
	}
	cout<<"Inorder\n";
	tree.Inorder();
	cout<<"\n LevelOrder\n";
	tree.levelOrder();
	return 0;
}
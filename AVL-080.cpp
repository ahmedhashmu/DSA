#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    int height;
};

int height(Node *n){
    if(n==NULL) return 0;
    return n->height;
}

Node* createNode(int key){
    Node* node=new Node();
    node->key=key;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}

int getBalance(Node *n){
    if(n==NULL) return 0;
    return height(n->left)-height(n->right);
}

// right rotation
Node* rightRotate(Node *y){
    Node *x=y->left;
    Node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

// left rotation
Node* leftRotate(Node *x){
    Node *y=x->right;
    Node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}

Node* insert(Node* node,int key){
    if(node==NULL)
        return createNode(key);

    if(key < node->key)
        node->left=insert(node->left,key);
    else if(key > node->key)
        node->right=insert(node->right,key);
    else
        return node;

    node->height=1+max(height(node->left),height(node->right));

    int balance=getBalance(node);

    if(balance>1 && key < node->left->key)   //LL case
        return rightRotate(node);

    if(balance<-1 && key > node->right->key)  //RR case
        return leftRotate(node);

    if(balance>1 && key > node->left->key){   //LR case
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance<-1 && key < node->right->key){  //RL case
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

int main(){
    Node *root=NULL;
    int arr[]={120,110,150,130,140,146,136,134,138,160,154,156,132,125,128};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)
        root=insert(root,arr[i]);

    cout<<"Inorder Traversal:"<<endl;
    inorder(root);
    cout<<endl;

    return 0;
}
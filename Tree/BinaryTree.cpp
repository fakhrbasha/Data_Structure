#include<iostream>
using namespace  std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// create new node
Node* newNode(int value){
    Node* nNode=new Node; 
    nNode->data=value;
    nNode->left=NULL;
    nNode->right=NULL;
    return nNode;
}
// pre Order root left right
void preOrder(Node* temp){
    if(temp!=NULL){
        cout << temp->data <<" ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}
// In Order left root right
void inOrder(Node* temp){
    if(temp!=NULL){
        inOrder(temp->left);
        cout << temp->data << " ";
        inOrder(temp->right);
    }
}
// post order left right root
void postOrder(Node* temp){
    if(temp!=NULL){
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data << " ";
    }
}
int height(Node* h){
    if(h==NULL){
        return -1;
    }else{
        int l_height=height(h->left);
        int r_height=height(h->right);
        return max(l_height,r_height);
    }
}
int count(Node* c){
    if(c==NULL){
        return 0;
    } 
    if (c->left==NULL && c->right==NULL){
        return 1;
    }else{
        return count(c->left)+count(c->right);
    }
}
 // anothr way to com number of node
 int size(Node *r){
    if(r==NULL){
        return 0;
    }else{
        return size(r->left)+1+size(r->right);
    }
}
int main(){

    /*
          5
        /  \
       15   9
     /     / \
    3     2   11

    */
    Node *root=newNode(5);
    root->left=newNode(15);
    root->left->left=newNode(3);
    root->right=newNode(9);
    root->right->left=newNode(2);
    root->right->right=newNode(11);
    
    preOrder(root); // 5 15 3 9 2 11
    cout << endl;
    inOrder(root); // 3 15 5 2 9 11
    cout << endl;
    postOrder(root); // 3 15 2 11 9 5
    cout << endl;
}
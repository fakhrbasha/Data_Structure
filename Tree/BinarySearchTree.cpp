#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node* left;
    Node* right;
};
// create New Node
Node* newNode(int item){
    Node* nNode = new Node;
    nNode->key=item;
    nNode->left=nNode->right=NULL;
    return nNode;
}
Node* insert(Node* node , int key){
    if(node==NULL){ // if tree empty return newNode()
        return newNode(key);
    }
    if(key<node->key){
        node->left=insert(node->left,key);
    }else if(key>node->key){
        node->right=insert(node->right,key);
    }
    return node;
}
Node* search(Node* root, int key){
    if(root==NULL ){
        return root;
    }
    if(root->key < key){
        return search(root->right,key);
    }
    return search(root->left,key);
}
int size(Node *r){
    if(r==NULL){
        return 0;
    }else{
        return size(r->left)+1+size(r->right);
    }
}

// delete  أجب بنفسك
// one child  أجب بنفسك
// two child  أجب بنفسك

void inorder(Node* root){ // left root right
    if(root!=NULL){
        inorder(root->left);
        cout << root->key<< " ";
        inorder(root->right);
    }
}
int main(){
    Node* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    inorder(root);
}
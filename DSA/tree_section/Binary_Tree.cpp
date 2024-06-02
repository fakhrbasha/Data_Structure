#include<iostream>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
// new node creation
struct node* newNode (int data){
    struct node*nNode=new node;
    nNode->data=data;
    nNode->left=NULL;
    nNode->right=NULL;
    return(nNode);
    
}
// pre order   root left right
void preOrder(node * temp){
    if(temp!=NULL){
        cout << temp->data<<" ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}
// in order left root right 
void inOrder(node* temp){
    if(temp!=NULL){
        inOrder(temp->left);
        cout << temp->data<<" ";
        inOrder(temp->right);
    }
}
// post order left right root
void postOrder(node * temp){
    if(temp!=NULL){
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data<<" ";
    }
}
 // tree height
int tree_height(node * h){
    if(h==NULL){
        return -1;
    }else{
        // find the height of both dub tree and use larger one
        int l_height=tree_height(h->left);
        int r_height=tree_height(h->right);
        return max(l_height,r_height)+1;
    }
}
// another way no. of leaf nodes
int tree_leaves_count (node * r){
    if(r==NULL){
        return 0 ;
    } if (r->left==NULL && r->right==NULL){
        return 1;
    } else{
        return tree_leaves_count(r->left)+tree_leaves_count(r->right);
    }
}
// another way Computes the number of nodes in a tree.
int size(node * r){
    if(r==NULL){
        return 0;
    }else{
        return (size(r->left)+1+size(r->right));
    }
}
int main(){
    /*Code To Test the logic
	  Creating an example tree
	            10
			   / \
			 17   55
			/    / \
		   3    14  144       */

    node *root =newNode(10);
    root->left=newNode(17);
    root->left->left=newNode(3);
    root->right=newNode(55);
    root->right->left=newNode(14);
    root->right->right=newNode(144);
    preOrder(root);
    cout << endl; // root left right
    inOrder(root); // left root right
    cout << endl;
    postOrder(root); // left right root
    cout << endl;
    cout << "Tree Height : "<<tree_height(root)<<endl;
    cout<< "Tree Leaves count "<<tree_leaves_count(root)<<endl;
    cout << "Tree Nodes Count "<<size(root)<<endl;

}
#include<iostream>
using namespace std;
struct node{
    int key;
    node* left;
    node* right;
};
// create new BST
struct node* newNode(int item){
    node* temp= new node;
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
}
// insert node 
node *insert(node* item , int key){
    // check tree is empty return nowNode
    if(item==NULL){
        return newNode(key);
    }

    // recur
    if(key<item->key){
        item->left=insert(item->left,key);
    }else if(key>item->key){
        item->right=insert(item->right,key);
    }
    return item;
}
// search node
node* search(node* root,int key){
    // base case : check root if empty or present at root
    if(root==NULL ){
        return root;
    }
    // key greater than  root 
    if(key>root->key){
        return search(root->right,key);
    }
    return search(root->left,key);
}
node *minValueNode(node * item){
    node* current=item;
    // loop to down smallest leaf
    while(current&&current->left!=NULL){
        current=current->left;
    }
    return current;
}
node *deleteNode(node * root , int key){
    //base case 
    if(root==NULL){
        return root;
    }
    // if key smaller than root key lies in the left subtree
    if(key<root->key){
        root->left=deleteNode(root->left,key);
    }
    // if key greater than root key lies in the right subtree
    else if(key>root->key){
        root->right=deleteNode(root->right,key);
    }
    else{
        // node be deleted one child or no
        if(root->left==NULL){
            node *temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            node*temp=root->left;
            free(root);
            return temp;
        }
        // node with two child
        node*temp=minValueNode(root->right);
        root->key=temp->key;
        root->right=deleteNode(root->right,temp->key);
    }
    return root;
}
// inorder treversal left root right
void inOrder(node * item){
    if(item!=NULL){
        inOrder(item->left);
        cout << item->key << " ";
        inOrder(item->right);
    }
}
// root left right
void preOrder(node *item){
    if(item!=NULL){
        cout << item->key<< " ";
        preOrder(item->left);
        preOrder(item->right);
    }
}
void postOrder(node *item){
    if(item!=NULL){
        postOrder(item->left);
        postOrder(item->right);
        cout<< item->key<<" ";
    }
}
// preOrder
// postOrder
int main(){
     /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
  node * root=NULL;
  root=insert(root,50);
  insert(root,30);
  insert(root,20);
  insert(root,60);
  insert(root,80);
  insert(root,70);
  insert(root,40);

  inOrder(root); // left root left
  // 20 30 40 50 60 70 80
   cout << endl;

  preOrder(root); // root left right
  // 50 30 20 40 70 60 80 error
  cout<<endl;
  postOrder(root); // left right root

  // 20 40 30 60 80 70 50 error
  // 20 40 30 70 80 60 50

}
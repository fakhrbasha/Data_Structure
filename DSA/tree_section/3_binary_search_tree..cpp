// insert & traverse(inorder , preorder, postorder) & count nodes (size) & count leaf nodes , interior & search
#include<iostream>
using namespace std;

struct TreeNode {
  int data;
  TreeNode * left;
  TreeNode * right;
};
  
  TreeNode * root = NULL;
//..........................

  void insertNode(int value) {
  	
        TreeNode * new_node = new TreeNode;
	    new_node->data = value;
	    new_node->left = NULL;
	    new_node->right = NULL;
	      
	    if (root == NULL) {
	      root = new_node;
	      cout << "Value Inserted as root node " << endl;}
		   
		else {
	      TreeNode * temp = root;
	      
	      while (temp != NULL) {
	        if (new_node->data == temp->data){
	        	cout << "Value Already exist ,Insert another value " << endl;
	        	return;
				 }
	          
	        else if ((new_node->data < temp->data) && (temp->left == NULL)){
	        	temp->left = new_node;
	        	cout << "Value Inserted to the left " << endl;
	          	break; }

	        else if (new_node->data < temp->data) 
	        	temp = temp->left;
	        	
	        else if ((new_node->data > temp->data) && (temp->right == NULL)){
	            temp->right = new_node;
	            cout << "Value Inserted to the right " << endl;
	            break; }
	            
	        else 
	            temp = temp->right;
       }
    }
}

//.........................
  void Search(int value){
	    if (root == NULL)
	      cout<<"not founded \n";
	    else {
	      TreeNode * temp = root;
	      while (temp != NULL) {
	        if (value == temp->data){
	        	cout<<" founded \n";
	        	return; }
	        else if (value < temp->data) 
	        	temp = temp->left;
	        else 
	            temp = temp->right;
	       }
	    if(temp == NULL)
	    	cout<<"not founded \n";
	   }
}

//_______________
// another way for search using recursion
  TreeNode * recursiveSearch(TreeNode * r, int value) {
  	
    if (r == NULL || r->data == value)
      return r;

    else if (value < r->data)
      return recursiveSearch(r->left, value);

    else
      return recursiveSearch(r->right, value);
  }

//...........................
  
//-> using any travrse type we can count leaf nodes,size , interior nodes,sum , get max , min ,search , .... 
  void printPreorder(TreeNode * r) //(current node, Left, Right)  
  {
	    if (r != NULL){
	    /* first print data of node */
	    cout << r->data << " ";
	    /* then recur on left sutree */
	    printPreorder(r->left);
	    /* now recur on right subtree */
	    printPreorder(r->right);}
  } 
  
  /* or 
  void printPreorder(TreeNode * r){
      if(r == NULL)'
	  	 return;	
	  cout << r->data << " ";
      printPreorder(r->left);
      printPreorder(r->right);  }
  */
	    
     
  void printInorder(TreeNode * r) //  (Left, current node, Right)
  {
	    if (r != NULL){
	    printInorder(r->left);
	    cout << r->data << " ";
	    printInorder(r->right);}
  }

  void printPostorder(TreeNode * r) //(Left, Right, Root)
  {
	    if (r != NULL){
	    printPostorder(r->left);
	    printPostorder(r->right);
	    cout << r->data << " ";}
  } 
  

// Computes the number of nodes in a tree.
void size(TreeNode * r, int &count) {
	if (r != NULL) {
		size(r->left, count);
		size(r->right, count);
		count++;
	}
}

/* Function to get the count of leaf nodes in a binary tree*/
void getleafcount(TreeNode * r, int & count) {
	if (r != NULL) {
		getleafcount(r->left, count);
		getleafcount(r->right, count);
	    if(r->left == NULL && r->right == NULL)
			count++;
	}
}

//...display....
void print2D(TreeNode * r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += 10; // Increase distance between levels   2
    print2D(r->right, space); // Process right child first 3 
    cout << endl;
    for (int i = 10; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r->data << "\n"; // 6
    print2D(r->left, space); // Process left child  7
  }

//

int main() {
  int option, value;

  do {
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Print/Traversal BST values" << endl;
    cout << "4. size of tree"<<endl;
    cout << "5. count leaf nodes"<<endl;
    cout << "6. print 2D " << endl;
    cout << "7. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;
    // ------------------------------
    cin >> option;

    switch (option) {
    case 0:
      	break;
      
    case 1:{
	    cout <<"Enter value to insert in BST: ";
	    cin >> value;
	    insertNode(value);;  
     	break;}
      
    case 2:{
     	cout << "Enter value to search in BST: ";
      	cin >> value;
      	Search(value);
     	 //((recursiveSearch(root,value))==NULL)? cout<<"not founded \n" :cout<<"founded \n";
      	break;}
      	
      	
    case 3:{
    	cout <<"PRE-ORDER: ";
        printPreorder(root);
        cout<<endl;
       	cout <<"IN-ORDER: ";
      	printInorder(root);
      	cout<<endl;
      	cout <<"POST-ORDER: ";
      	printPostorder(root);
      	cout<<endl;
     	break;}
      
    case 4:{
      int count = 0;
	  size(root,count);
	  cout << "Size of the tree is : "<< count <<endl;
      break; }
      
    case 5:{
      int count = 0;
	  getleafcount(root,count);
	  cout << "number of the leaf nodes : "<< count <<endl;
      break; }
	       
    case 6:{
      print2D(root,10);
      break;}
      
    case 7:{
      system("cls");
      break;}
      
    default:{
      cout << "Enter valid Option number " << endl;}
    }
    
	cout << "___________________ " << endl;
  } while (option != 0);

  return 0;
}

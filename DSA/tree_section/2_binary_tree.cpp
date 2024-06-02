// insert & traverse(inorder , preorder, postorder) & count nodes & count leaf nodes & search
#include <iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
};


// New node creation
struct node* newNode(int data) {
	struct node* nNode = new node;

	nNode->data = data;

	nNode->left = NULL;
	nNode->right = NULL;
	return (nNode);
}

// Traverse Preorder
void traversePreOrder(node * temp) {
	if (temp != NULL) {
	    cout<<" "<<temp->data;
		traversePreOrder(temp->left);
		traversePreOrder(temp->right);
	}
}

// Traverse Inorder
void traverseInOrder(struct node* temp) {
	if (temp != NULL) {
		traverseInOrder(temp->left);
		cout << " " << temp->data;
		traverseInOrder(temp->right);
	}
}

// Traverse Postorder
void traversePostOrder(struct node* temp) {
	if (temp != NULL) {
		traversePostOrder(temp->left);
		traversePostOrder(temp->right);
		cout << " " << temp->data;
	}
}

int tree_height(struct node * r) {
	// Get the height of the tree
	if (r == NULL)
		return -1;
	else {
		// Find the height of both subtrees
		// and use the larger one
		int l_height = tree_height(r->left);
		int r_height = tree_height(r->right);
        return max(l_height,r_height)+1;
	}
}

// another way no. of leaf nodes 
int getLeavesCount(node * r) {
	if (r == NULL)
		return 0;
	if (r->left == NULL && r->right == NULL)
		return 1;
	else
		return getLeavesCount(r->left) + getLeavesCount(r->right);
}
// another way Computes the number of nodes in a tree.
int size(node* r)
{
    if (r == NULL)
        return 0;
    else
        return(size(r->left) + 1 + size(r->right));
}

int main()
{
		/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			 15   9
			/    / \
		   3    2  11       */
	node* root = newNode(5);
	root->left = newNode(15);
	root->left->left = newNode(3);
	root->right = newNode(9);
	root->right->left = newNode(2);
	root->right->right = newNode(11);
	
	traversePreOrder(root);
	cout << endl;
	traverseInOrder(root);
	cout << endl;
	traversePostOrder(root);
	cout << endl;
	cout<<"tree height = "<<tree_height(root) << endl;
	cout << " tree nodes count " << size(root) << endl;
	cout << " tree leaves count " << getLeavesCount(root) << endl;
	root = NULL;
	cout << "tree height = " << tree_height(root);
}



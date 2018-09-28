# include <iostream>
# include <stdlib.h>

//didn't use whole std namespace since the build would become bulkier
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

// data structure
struct NODE {
	int data;
	NODE *left;
	NODE *right;
};

// insert function
// got help from a person on the internet! thank you Discord!
NODE* Insert_Node (NODE *root, int& data) {
	if (root == NULL) {
		root = new NODE;
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	else if (data < root->data) {
		root->left = Insert_Node (root->left, data);
	}
	else if (root->data < data) {
		root->right = Insert_Node (root->right, data);
	}
}

// delete function
/* NODE* Delete_Node (NODE *root, int& data) {
	// do something
} */

// traverse tree
// inorder traversal. made this on the first try!!! BOI!!!
void InOrder (NODE *root) {	
	 if (root->left != NULL) InOrder (root->left);
	 cout << root->data << " ";
	 if (root->right != NULL) InOrder (root->right);
}

// preorder traversal. Thanks to BHups!
void PreOrder (NODE *root) { 
	if (root == NULL) return;
	cout << root->data << " ";
	PreOrder (root->left);
	PreOrder (root->right);
}

// search function
// sub-function for searching
int Exists (NODE *root, int& data) { 
	if (root->data == data) {
		return 1;
	}
	else {
		if (root->left != NULL) Exists (root->left, data);
		if (root->right != NULL) Exists (root->right, data);
	}
}

// searching using Exists function
void Search (NODE *root, int& data) { 
	int flag = 0;
	flag = Exists (root, data);
	if (flag != 0) cout << data << " found!" << endl;
	else cout << data << " not found!" << endl;
}

NODE * minValueNode(NODE* node) 
{ 
    NODE* current = node; 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
NODE* DeleteNode(NODE* root, int data) 
{ 
    if (root == NULL) return root; 
  
    // If the data to be deleted is smaller than the root's data, 
    // then it lies in left subtree 
    if (data < root->data) 
        root->left = DeleteNode(root->left,data); 
  
    else if (data > root->data) 
        root->right = DeleteNode(root->right, data);   
        
    /* if data is same as root's data, then This is the node 
    to be deleted */
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            NODE *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            NODE *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        /* node with two children: Get the inorder successor (smallest 
         in the right subtree) */ 
        NODE* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = DeleteNode(root->right, temp->data); 
    } 
    return root; 
} 
// main
int main () {
	NODE *root = NULL;
	//int datum[] = {2, 0, 1, 5, 3, 4};
	int d, N, data;
	cout << "Enter number of elements to be inserted: ";
	cin >> N;
	for (int i = 0; i < N ; i++) { //sample input: 2, 0, 1, 5, 3, 4
		cout << "Enter data element: ";
		cin >> data;
		root = Insert_Node (root, data);
	}

	cout << "Tree in IN-ORDER traversal: " << endl;
	InOrder (root);
	cout << "\nTree in PRE-ORDER traversal: " << endl;
	PreOrder (root);
	cout << "\nEnter element to be searched: ";
	cin >> data;
 	Search (root, data);
 	cout<<"\nEnter Data to delete : ";
 	cin>>d;
    root = DeleteNode(root, d); 
    printf("Inorder traversal of the modified tree \n"); 
    InOrder(root); 
	return 0;
}

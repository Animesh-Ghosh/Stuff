#include <iostream>

using namespace std;

// data structure
struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *start = NULL;

// helper function to create node element
Node* CreateNode (int data) {
	Node *element = new Node;
	element->data = data;
	element->left = element->right = NULL;
	return element;
}

// insert function
// got help from a person on the internet! thank you Discord!
Node* Insert (Node *root, Node* element) {
	if (root == NULL) 
		root = element;
	else if (element->data < root->data) 
		root->left = Insert (root->left, element);
	else if (root->data < element->data) 
		root->right = Insert (root->right, element);
	return root;
}

// delete function
// no one helped me :'( except the video specified below
// https://www.youtube.com/watch?v=wcIRPqTR3Kc
Node* Delete (Node *root, Node *element) {
	Node *tempParent, *tempChild;
	if (element->data < root->data) 
		root->left = Delete (root->left, element);
	else if (root->data < element->data) 
		root->right = Delete (root->right, element);
	else if (root->data == element->data) {
		if ((root->left == NULL) && (root->right == NULL)) 
			root = NULL; // no child nodes
		else if (root->left == NULL) // one child node
			root = root->right;
		else if (root->right == NULL) 
			root = root->left;
		else { // two child node (still not working)
			tempParent = root;
			tempChild = root->right;
			while (tempChild->left != NULL) {
				tempParent = tempChild;
				tempChild = tempChild->left;
			}
			// code that does something correct
			tempParent->left = Delete (tempParent->left, tempChild);
			tempChild->left = root->left; tempChild->right = root->right;
			root = tempChild;
		}
		delete element;
	}
	return root;
}

// traverse tree
// inorder traversal
// made this on the first try!!! BOI!!!
void InOrder (Node *root) {
	if (root->left != NULL) InOrder (root->left);
	cout << root->data << " ";
	if (root->right != NULL) InOrder (root->right);
}

// preorder traversal. Thanks to BHups!
void PreOrder (Node *root) { 
	cout << root->data << " ";
	if (root->left != NULL) PreOrder (root->left);
	if (root->right != NULL) PreOrder (root->right);
}

// wrapping inorder, preorder printing
void Print (Node *root) { 
	cout << "Tree in PRE-ORDER traversal: " << endl;
	PreOrder (root);
	cout << "\nTree in IN-ORDER traversal: " << endl;
	InOrder (root);
	cout << endl;
}

// sub-function for searching
int Exists (Node *root, int data) { 
	if (root->data == data) return 1;
	else if ((data < root->data) && (root->left != NULL)) 
		return Exists (root->left, data);
	else if ((root->data < data) && (root->right != NULL)) 
		return Exists (root->right, data);
	else return 0;
}

// search function using Exists function
void Search (Node *root, int data) { 
	if (!Exists (root, data)) cout << data << " not found!" << endl;
	else cout << data << " found!" << endl;
}

// function to initialise the tree
Node* Create (Node *root) {
	int N, data;
	cout << "Enter number of elements to be inserted: ";
	cin >> N;
	cout << "Enter elements: ";
	for (int i = 0; i < N ; i++) {
		cin >> data;
		root = Insert (root, CreateNode (data));
	}
	Print (root);
	return root;
}

// Tree function
void Tree () {
	int data, choice;
	char ans = 'Y';
	cout << "Create Tree: " << endl;
	start = Create (start);
	do {
		cout << "1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
			case 1: cout << "Enter data: ";
				cin >> data;
				start = Insert (start, CreateNode (data));
				cout << "Data element inserted!" << endl;
				break;
			case 2: cout << "Enter data to be deleted: ";
				cin >> data;
				if (Exists (start, data)) {
					start = Delete (start, CreateNode (data));
					cout << "Data element deleted!" << endl;
				}
				else cout << data << " not in tree. Can't delete." << endl;
				break;
			case 3: cout << "Enter data to be searched: ";
				cin >> data;
				Search (start, data);
				break;
			case 4:	Print (start);
				break;
			case 5: cout << "Exiting..." << endl;
				return; // exit (1);
			default: cout << "Invalid input!" << endl;
		}
		cout << "Continue? (Y/N): ";
		cin >> ans;
	} while (ans == 'Y' || ans == 'y');
}

int main (void) {
	Tree ();
	return 0;
}
#include <iostream>
#include "../ClearScreen/clearscreen.h" // can be removed

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
		// return root;
	else if (element->data < root->data) 
		root->left = Insert (root->left, element);
	else if (root->data < element->data) 
		root->right = Insert (root->right, element);
	// else if (root->data == element->data) 
	// 	return root; // repeating data elements not inserted
	return root;
}

// delete function
// no one helped me :'( except the video specified below
// https://www.youtube.com/watch?v=wcIRPqTR3Kc
Node* Delete (Node *root, Node *element) {
	Node *tempParent, *temp, *left, *right;
	if (element->data < root->data) {
		root->left = Delete (root->left, element);
	}
	else if (root->data < element->data) {
		root->right = Delete (root->right, element);
	}
	else if (root->data == element->data) {
		delete element;
		// no child
		if ((root->left == NULL) && (root->right == NULL)) 
			return NULL;
		// one child
		else if (root->left == NULL) 
			return root->right; //
		else if (root->right == NULL) 
			return root->left;
		// if two childs still not working
		else { 
			tempParent = root;
			left = tempParent->left;
			right = tempParent->right;
			temp = root->right;
			while (temp->right != NULL) {
				tempParent = temp;
				temp = temp->right;
			}
			temp = tempParent->left;
			temp->left = left;
			temp->right = right;
			tempParent->left = NULL;
			delete (tempParent->left);
			return temp;
		}
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
void Print (int order) {
	switch (order) {
		case '1': cout << "Tree in PRE-ORDER traversal: " << endl;
			PreOrder (start);
			break;
		case '2': cout << "Tree in IN-ORDER traversal: " << endl;
			InOrder (start);
			break;
		default: cout << "Invalid input!";
	}
}

// sub-function for searching
int Exists (Node *root, int data) { 
	if (root->data == data) return 1;
	else if ((data < root->data) && (root->left != NULL)) return Exists (root->left, data);
	else if ((root->data < data) && (root->right != NULL)) return Exists (root->right, data);
	else return 0;
}

// search function using Exists function
void Search (Node *root, int data) { 
	if (!Exists (root, data)) cout << data << " not found!";
	else cout << data << " found!";
}

// creating the tree
Node* Create (Node *root) {
	int N, data;
	cout << "Enter number of elements to be inserted: ";
	cin >> N;
	cout << "Enter elements: ";
	for (int i = 0; i < N ; i++) {
		cin >> data;
		root = Insert (root, CreateNode (data));
	}
	cout << "Tree in IN-ORDER traversal: " << endl;
	InOrder (root);
	return root;
}

// Tree function
void Tree () {
	// Node *root = NULL;
	int data;
	char ans = 'Y', ch;
	cout << "Create Tree: " << endl;
	start = Create (start);
	printf("\n");
	do {
		// system ("cls");
		cout << "1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
		cout << "Enter choice: ";
		cin >> ch;
		switch (ch) {
			case '1': cout << "Enter data: ";
				cin >> data;
				start = Insert (start, CreateNode (data));
				cout << "Data element inserted!";
				break;
			case '2': cout << "Enter data to be deleted: ";
				cin >> data;
				if (Exists (start, data)) {
					start = Delete (start, CreateNode (data));
					cout << "Data element deleted!";
				}
				else cout << "Data element not in tree. Can't delete.";
				break;
			case '3': cout << "Enter data to be searched: ";
				cin >> data;
				Search (start, data);
				break;
			case '4': cout << "1.Pre-Order\n2.In-Order\n";
				cout << "Enter choice: ";
				cin >> ch;
				Print (ch);
				break;
			case '5': cout << "Exiting..." << endl;
				return; // exit (1);
			default: cout << "Invalid input!";
		}
		cout << "\nContinue? (Y/N): ";
		cin >> ans;
		ClearScreen ();
	} while (ans == 'Y' || ans == 'y');
}

int main (void) {
	Tree ();
	return 0;
}

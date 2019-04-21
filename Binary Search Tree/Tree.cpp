#include <iostream>
#include "clearscreen.h"
// #include <process.h> // for exit ()

//didn't use whole std namespace since the build would become bulkier
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

// data structure
struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *start = NULL;

Node* CreateNode (int data) {
	Node *element = new Node;
	element->data = data;
	element->left = element->right = NULL;
	return element;
}

// insert function
// got help from a person on the internet! thank you Discord!
Node* Insert (Node *root, Node* element) {
	if (root == NULL) {
		root = element;
		return root;
	}
	else if (element->data < root->data) {
		root->left = Insert (root->left, element);
	}
	else if (root->data < element->data) {
		root->right = Insert (root->right, element);
	}
}

// delete function
Node* Delete (Node *root, int &data) {
	// do something
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

// search function
// sub-function for searching
int Exists (Node *root, int &data) { 
	if (root->data == data) return 1;
	else if ((data < root->data) && (root->left != NULL)) Exists (root->left, data);
	else if ((root->data < data) && (root->right != NULL)) Exists (root->right, data);
	else return 0;
}

// using Exists function
void Search (Node *root, int &data) { 
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
	Node *root = NULL;
	char ans = 'Y', ch;
	int data;
	cout << "Create Tree: " << endl;
	root = Create (root);
	do {
		// system ("cls");
		ClearScreen ();
		cout << "1.Insert\n2.Search\n3.Display\n4.Exit\n";
		cout << "Enter choice: ";
		cin >> ch;
		switch (ch) {
			case '1': cout << "Enter data: ";
				 cin >> data;
				 root = Insert (root, CreateNode (data));
				 cout << "Data element inserted!";
				 break;
			case '2': cout << "Enter data to be searched: ";
				 cin >> data;
				 Search (root, data);
				 break;
			case '3': cout << "1.Pre-Order\n2.In-Order\n";
				 cout << "Enter choice: ";
				 cin >> ch;
				 switch (ch) {
				 	case '1': cout << "Tree in PRE-ORDER traversal: " << endl;
						 PreOrder (root);
				 		 break;
					case '2': cout << "Tree in IN-ORDER traversal: " << endl;
						InOrder (root);
						break;
		  	   		default: cout << "Invalid input!";
				 }
				 break;
			case '4': cout << "Exiting..." << endl;
				 // exit (1);
				return;
			default: cout << "Invalid input!";
		}
		cout << "\nContinue? (Y/N): ";
		cin >> ans;
	} while (ans == 'Y' || ans == 'y');
}

int main (void) {
	Tree ();
	return 0;
}
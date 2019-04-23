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

// helper function
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
	else if (element->data < root->data) 
		root->left = Insert (root->left, element);
	else if (root->data < element->data) 
		root->right = Insert (root->right, element);
	else if (root->data == element->data) 
		return root; // repeating data elements not inserted
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
		// if two childs
		else { 
			tempParent = root;
			left = tempParent->left;
			right = tempParent->right;
			temp = root->left;
			while (temp->left != NULL) {
				tempParent = tempParent->left;
				temp = temp->left;
			}
			temp = tempParent->right;
			temp->left = left;
			temp->right = right;
			tempParent->right = NULL;
			delete (tempParent->right);
			return temp;
		}
	}
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
				switch (ch) {
					case '1': cout << "Tree in PRE-ORDER traversal: " << endl;
						PreOrder (start);
				 		break;
					case '2': cout << "Tree in IN-ORDER traversal: " << endl;
						InOrder (start);
						break;
		  	   		default: cout << "Invalid input!";
				}
				break;
			case '5': cout << "Exiting..." << endl;
				 // exit (1);
				return;
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
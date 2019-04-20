#include <iostream>
#include <windows.h>
// #include <process.h> // for exit ()

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

// http://www.cplusplus.com/articles/4z18T05o/#Windows
void ClearScreen () { 
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = {0, 0};

	hStdOut = GetStdHandle (STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	// Get the number of cells in the current buffer
	if (!GetConsoleScreenBufferInfo (hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire buffer with spaces
	if (!FillConsoleOutputCharacter (
		hStdOut, 
		(TCHAR) ' ', 
		cellCount, 
		homeCoords, 
		&count)
	) return;

	// Fill the entire buffer with the current colors and attributes
	if (!FillConsoleOutputAttribute (
		hStdOut, 
		csbi.wAttributes, 
		cellCount, 
		homeCoords, 
		&count)
	) return;

	// Move the cursor home
	SetConsoleCursorPosition (hStdOut, homeCoords);
}

// insert function
// got help from a person on the internet! thank you Discord!
NODE* Insert (NODE *root, int& data) {
	if (root == NULL) {
		root = new NODE;
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	else if (data < root->data) {
		root->left = Insert (root->left, data);
	}
	else if (root->data < data) {
		root->right = Insert (root->right, data);
	}
}

// delete function
NODE* Delete (NODE *root, int& data) {
	// do something
}

// traverse tree
// inorder traversal
// made this on the first try!!! BOI!!!
void InOrder (NODE *root) {
	 if (root->left != NULL) InOrder (root->left);
	 cout << root->data << " ";
	 if (root->right != NULL) InOrder (root->right);
}

// preorder traversal. Thanks to BHups!
void PreOrder (NODE *root) { 
	cout << root->data << " ";
	if (root->left != NULL) PreOrder (root->left);
	if (root->right != NULL) PreOrder (root->right);
}

// search function
// sub-function for searching
int Exists (NODE *root, int& data) { 
	if (root->data == data) return 1;
	else if ((data < root->data) && (root->left != NULL)) Exists (root->left, data);
	else if ((root->data < data) && (root->right != NULL)) Exists (root->right, data);
	else return 0;
}

// using Exists function
void Search (NODE *root, int& data) { 
	if (!Exists (root, data)) cout << data << " not found!";
	else cout << data << " found!";
}

// creating the tree
NODE* Create (NODE *root) {
	int N, data;
	cout << "Enter number of elements to be inserted: ";
	cin >> N;
	cout << "Enter elements: ";
	for (int i = 0; i < N ; i++) {
		cin >> data;
		root = Insert (root, data);
	}
	cout << "Tree in IN-ORDER traversal: " << endl;
	InOrder (root);
	return root;
}

// Tree function
void Tree () {
	NODE *root = NULL;
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
				 root = Insert (root, data);
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
	}while (ans == 'Y' || ans == 'y');
}

// main
int main () {
	Tree (); // call to main
	return 0;
}

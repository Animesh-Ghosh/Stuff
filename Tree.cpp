# include <iostream>

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
NODE* Delete_Node (NODE *root, int& data) {
	// do something
}

// traverse tree
void InOrder (NODE *root) {	// inorder traversal
	 // made this on the first try!!! BOI!!!
	 if (root->left != NULL) InOrder (root->left);
	 cout << root->data << " ";
	 if (root->right != NULL) InOrder (root->right);
}

void PreOrder (NODE *root) { // preorder traversal. Thanks to BHups!
	//NODE*cur=root;
	if (root == NULL) return;
	cout << root->data << " ";
	PreOrder (root->left);
	PreOrder (root->right);
}

// search function
int Exists (NODE *root, int& data) { // sub-function for searching
	if (root->data == data) {
		return 1;
	}
	else {
		if (root->left != NULL) Exists (root->left, data);
		if (root->right != NULL) Exists (root->right, data);
	}
}

void Search (NODE *root, int& data) { // using Exists function
	int flag = 0;
	flag = Exists (root, data);
	if (flag != 0) cout << data << " found!" << endl;
	else cout << data << " not found!" << endl;
}


// main
int main () {
	NODE *root = NULL;
	//int datum[] = {2, 0, 1, 5, 3, 4}; //sample input: 2, 0, 1, 5, 3, 4
	int N, data;
	cout << "Enter number of elements to be inserted: ";
	cin >> N;
	for (int i = 0; i < N ; i++) {
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
	return 0;
}

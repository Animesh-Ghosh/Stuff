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

// traverse tree
void Traverse (NODE *root) {
	 // made this on the first try!!! BOI!!!
	 NODE *cur = root;
	 if (cur->left != NULL) Traverse (cur->left);
	 cout<<cur->data<<" ";
	 if (cur->right != NULL) Traverse (cur->right);
}

// main
int main () {
	NODE *root = NULL;
	//int datum[] = {2, 0, 1, 5, 3, 4}; //sample input: 2, 0, 1, 5, 3, 4
	int N, data;
	cout<<"Enter number of elements to be inserted: ";
	cin>>N;
	for (int i = 0; i < N ; i++) {
		cout<<"Enter data element: ";
		cin>>data;
		root = Insert_Node (root, data);
	}
	/*
	cout<<"Level 0:\t"<<root->data<<endl;
	cout<<"Level 1:\t"<<root->left->data<<"\t"<<root->right->data<<endl;
	cout<<"Level 2:\t"<<root->left->right->data<<"\t"<<root->right->left->data<<endl;
	cout<<"Level 3:\t"<<root->right->left->right->data<<endl;
	*/
	cout<<"Tree in INORDER traversal: "<<endl;
	Traverse (root);
	return 0;
}

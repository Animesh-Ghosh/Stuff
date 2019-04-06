#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// linked list vanilla implementation

typedef struct NODE Node;
struct NODE {
	int data;
	Node *next;
};

Node *start = NULL;

Node* CreateNode (int data)  {
	Node *element = (Node*) malloc (sizeof (Node));
	element->data = data;
	element->next = NULL;
	return element;
}

Node* Insert (Node *head, Node *element, int position) {
	Node *prev, *current = head;
	int counter = 0;
	if (head == NULL) head = element;
	else if (position == -1) {
		while (current->next != NULL) 
			current = current->next;
		current->next = element;
	}
	else {
		while (current->next != NULL && counter < position) {
			prev = current;
			current = current->next;
			counter++;
		}
		prev->next = element;
		element->next = current;
	}
	return head;
}

Node* Delete (Node *head, int position) {
	Node *prev, *current = head;
	int counter = 0;
	if (position == 0) {
		head = head->next;
		free (current);
	}
	else if (position == -1) {
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		free (current);
	}
	else {
		while (current->next != NULL && counter < position) {
			prev = current;
			current = current->next;
			counter++;
		}
		prev->next = current->next;
		free (current);
	}
	return head;
}

void Print (Node *head) {
	Node *current = head;
	while (current != NULL) {
		printf("%d ", (current->data));
		current = current->next;
	}
}

int main (int argc, char const *argv[]) {
	int i, size = atoi (argv[1]), value;
	srand (time (0));
	if (argc < 2) {
		printf("Enter size of list: \n");
		scanf ("%d", &size);
	}
	printf("Generating a list of random values...\n");
	for (i = 0; i < size; i++) {
		value = rand () % size + 1;
		start = Insert (start, CreateNode (value), -1);
	}
	printf("List: \n");
	Print (start);
	printf ("\nDeleting a node from the start of the list.\n");
	start = Delete (start, 0);
	printf("Altered list: \n");
	Print (start);
	printf ("\nEnter position from which element is to be deleted: ");
	scanf ("%d", &value);
	start = Delete (start, value);
	printf("Altered list: \n");
	Print (start);
	printf ("\nDeleting a node from the end of the list.\n");
	start = Delete (start, -1);
	printf("Altered list: \n");
	Print (start);
	return 0;
}
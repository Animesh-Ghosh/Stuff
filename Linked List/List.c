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
	Node *previous, *current = head;
	int counter = 0;
	if (head == NULL) head = element;
	else if (position == 0) {
		element->next = head;
		head = element;
	}
	else if (position == -1) {
		while (current->next != NULL) 
			current = current->next;
		current->next = element;
	}
	else {
		while (current->next != NULL && counter < position) {
			previous = current;
			current = current->next;
			counter++;
		}
		previous->next = element;
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

void List () {
	int value, choice, position;
	char answer = 'y';
	printf ("\n");
	do {
		printf ("1. Insert into list\n2. Delete from list\n3. Print the list\n");
		printf ("Enter choice: ");
		scanf ("%d", &choice);
		switch (choice) {
			case 1: 
				printf ("Enter value and position: ");
				scanf ("%d %d", &value, &position);
				start = Insert (start, CreateNode (value), position);
				printf ("Altered list: \n");
				Print (start);
				break;
			case 2: 
				printf ("Enter position: ");
				scanf ("%d", &position);
				start = Delete (start, position);
				printf ("Altered list: \n");
				Print (start);
				break;
			case 3: 
				printf ("List: \n");
				Print (start);
				break;
			default: printf ("Invalid choice!\n");
		}
		printf ("\nContinue (Y/N)?: ");
		// fflush (stdin);
		while ((getchar ()) != '\n');
		scanf ("%c", &answer);
	} while (answer == 'Y' || answer == 'y');
}

int main (int argc, char const *argv[]) {
	int i, size = atoi (argv[1]), value;
	srand (time (0));
	if (argc < 2) {
		printf("Enter size of list: \n");
		scanf ("%d", &size);
	}
	printf ("Generating a list of 0 indexed random values...\n");
	for (i = 0; i < size; i++) {
		value = rand () % size + 1;
		start = Insert (start, CreateNode (value), -1);
	}
	printf ("List: \n");
	Print (start);
	List ();
	return 0;
}
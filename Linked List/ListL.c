#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define null NULL

// linked list using triple ref
// Original code at http://www.eprg.org/computerphile/tripref.c

struct NODE {
	int data;
	struct NODE *next;
};
typedef struct NODE Node;

Node *start = null;

Node* Create (int data) {
	Node* element = (Node*) malloc (sizeof (Node));
	element->data = data;
	element->next = null;
	return element;
}

void Insert (Node **head, Node* element) {
	Node **current = head; /* double pointer so that 
	start can be passed by "reference" */
	if (*head == null) {
		*head = element; /* value pointed to by head
		viz. start will now point to element */
	}
	else {
		/* while the value pointed to by current's 
		next field ie. start->next is not NULL */
		while ((*current)->next != null) {
			current = &(*current)->next; // right way
			// *current = (*current)->next; // wrong way
			/* current is assigned the address of the 
			next field of the value pointed to by current
			ie. start->next */
		}
		(*current)->next = element;
		/* value pointed to by current's next field 
		now points to element */
	}
}

void Print (Node *head) {
	Node *current = head;
	while (current != null) {
		printf("%d ", (current->data));
		current = current->next;
	}
}

int main (int argc, char const *argv[]) {
	int i, size = atoi (argv[1]);
	Node *current;
	srand (time (0));
	for (i = 0; i < size; i++) {
		current = Create (rand () % size + 1);
		Insert (&start, current); // passing start by "reference"
		// printf ("%p\n", start);
	}
	printf("List: \n");
	Print (start);
	printf ("\nData at the start of list (hex): %p\n", *start);
	printf ("Address of start pointer: %p\n", &start);
	printf ("Address of node at the start of list: %p\n", &*start);
	printf ("Address of node at the start of list: %p", &(*start));
	return 0;
}
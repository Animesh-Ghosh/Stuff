#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define null NULL

// linked list using triple ref in vanilla fashion
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

void Insert (Node **head, Node* element, int position) {
	Node **tracer = head; /* double pointer, holds address of start, can hold 
	address of next pointers of the list */
	int counter = 0;
	if (*head == null) {
		*head = element; /* *head or start holds address of element
		(*head or start points to element) */
	}
	else if (position == -1) {
		/* while next of *tracer or next of current node is not null */
		while ((*tracer)->next != null) {
			tracer = &(*tracer)->next;
			/* tracer holds address of next field of *tracer or current node 
			which can be used to access next node in the list by dereferencing 
			it once */
			/* tracer = &(*tracer)->next; // right way
			   *tracer = (*tracer)->next; // wrong way
			   tracer = &((*tracer)->next); // same way */
		}
		/* finally, tracer holds address of next field of node one before the 
		last node, last node can be accessed using *tracer */
		(*tracer)->next = element;
		/* next of *tracer (or next of last node) points to element or 
		next of node pointed to by next field of previous to last node holds 
		address of element */
	}
	else {
		while ((*tracer)->next != null && counter < position) {
			tracer = &(*tracer)->next;
			counter++;
		}
		/* element's next points to the node at the specified position by 
		accessing *tracer */
		element->next = (*tracer);
		/* *tracer which is the next field of a previous node (since tracer holds
		address of next field of a previous node) points to the element */
		(*tracer) = element;
	}
}

void Print (Node *head) {
	Node *current = head;
	while (current != null) {
		printf("%d ", current->data);
		current = current->next;
	}
}

int main (int argc, char const *argv[]) {
	int i, size = atoi (argv[1]), value, position;
	Node *current;
	srand (time (0));
	if (argc < 2) {
		printf("Enter size of list: \n");
		scanf ("%d", &size);
	}
	printf("Generating a list of random values...\n");
	for (i = 0; i < size; i++) {
		current = Create (i);
		Insert (&start, current, -1); // passing start by "reference"
		// printf ("%p\n", current);
	}
	printf("List: \n");
	Print (start);
	printf ("\nValue of data at start of list(hex): %p\n", *start);
	printf ("Address of start pointer: %p\n", &start);
	printf ("Address of node at the start of list: %p\n", &*start);
	printf ("Address of node at the start of list: %p\n", &(*start));
	printf ("Address of node at the start of list: %p\n", start);
	printf ("Enter value to be inserted and it's position in the list: ");
	scanf ("%d %d", &value, &position);
	Insert (&start, Create (value), position);
	printf ("Altered list: \n");
	Print (start);
	return 0;
}
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
	Node **tracer = head; /* double pointer holds address of start 
	only points to the next pointers of the list */
	int counter = 0;
	if (*head == null) {
		*head = element; /* *head points to element or 
		start points to element */
	}
	else if (position == -1) {
		/* while next of *tracer is not null or 
		while next of current node is not null */
		while ((*tracer)->next != null) {
			tracer = &(*tracer)->next;
			/* tracer holds address of next field of current node */
			/* tracer = &(*tracer)->next; // right way
			   *tracer = (*tracer)->next; // wrong way
			   tracer = &((*tracer)->next); // same way */
		}
		/* finally, tracer holds address of next field of last node */
		(*tracer)->next = element;
		/* next of *tracer points to element or 
		next of node holds address of element */
	}
	else {
		while ((*tracer)->next != null && counter < position) {
			tracer = &(*tracer)->next;
			counter++;
		}
		element->next = (*tracer); // don't get it
		(*tracer) = element; // this either
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
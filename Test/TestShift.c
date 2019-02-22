#include <stdio.h>
#include  <conio.h>

int main () {
	printf ("-1 left-shifted once: %d\n", ((-1 >> 1)));
	((-1 >> 1) < 0) ? printf ("Arithmetic Shift") : printf ("Logical Shift");
	getch ();
	return 0;
}

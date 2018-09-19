# include <stdio.h>
# include <string.h>
# include  <conio.h>

int main () {
	((-1 >> 1) < 0) ? puts ("Arithmetic Shift") : puts ("Logical Shift");
	printf ("%d", ((-1 >> 1)));
	getch ();
	return 0;
}

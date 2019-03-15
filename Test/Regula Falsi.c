#include <stdio.h>

double pow (double a, int b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else return a * pow (a, (b - 1));
}

double func (double x, int y) {
	return pow (x, y) - y;
}

int main () {
	double x0, x1, x2, input;
	int count = 0, root;
	printf ("Enter number: ");
	scanf ("%lf", &input);
	printf ("Enter the root's order: ");
	scanf ("%d", &root);
	printf ("Enter the lower-bound of the interval: ");
	scanf ("%lf", &x0);
	printf ("Enter the upper-bound of the interval: ");
	scanf ("%lf", &x1);
	printf ("%.15lf %d %.15lf %.15lf\n", input, root, x0, x1);
	while ((x1 - x0) > 1e-15) {
		printf ("x0 = %.15lf\tx1 = %.15lf\t", x0, x1);
		x2 = x1 - (((x1 - x0) * func (x1, root)) / (func (x1, root) - func (x0, root)));
		printf ("x2 = %.15lf\n", x2);
		if (func (x2, root) * func (x0, root) > 0) 
			x0 = x2;
		else if (func (x2, root) * func (x0, root) < 0)
			x1 = x2;
		count++;
	}
	printf ("Loop Count: %d\n", count);
	printf ("Final estimation: %.15lf", x2);
	return 0;
}

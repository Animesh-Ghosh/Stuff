#include <stdio.h>

double myPow (double a, int b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else return a * myPow (a, (b - 1));
}

double func (double a, int power, double number) {
	return myPow (a, power) - number;
}

int main () {
	double x0, x1, x2, input;
	int root, count = 0;
	printf ("Enter number: ");
	scanf ("%lf", &input);
	printf ("Enter the root's order: ");
	scanf ("%d", &root);
	printf ("Enter the lower-bound of the interval: ");
	scanf ("%lf", &x0);
	printf ("Enter the upper-bound of the interval: ");
	scanf ("%lf", &x1);
	while (count < 1000) {
		x2 = x1 - (((x1 - x0) * func (x1, root, input)) / (func (x1, root, input) - func (x0, root, input)));
		if (func (x2, root, input) * func (x0, root, input) > 0) 
			x0 = x2;
		else if (func (x2, root, input) * func (x0, root, input) < 0)
			x1 = x2;
		count++;
	}
	printf ("Final estimation: %.15lf", x2);
	return 0;
}

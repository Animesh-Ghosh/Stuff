#include <stdio.h>

// power function for integral powers
double myPow (double a, int b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else return a * myPow (a, (b - 1));
}

// estimating lower and upper bounds for applying false position method
void estimateBounds (double number, int root, double *lbound, double *ubound) {
	double lower = 0, upper = 1;
	while (1) {
		if (myPow (lower, root) < number && number < myPow (upper, root)) 
			break;
		lower = upper;
		upper += 1;
	}
	*lbound = lower;
	*ubound = upper;
}

// function whose root needs to be estimated
double func (double number1, int power, double number2) {
	return myPow (number1, power) - number2;
}

// implementation of regula falsi method
double RegulaFalsi (double number, double root, double x0, double x1) {
	int count = 0;
	double x2;
	while (count < 1000) {
		// main iteration statement
		x2 = x1 - (((x1 - x0) * func (x1, root, number)) / (func (x1, root, number) - func (x0, root, number)));
		if (func (x2, root, number) * func (x0, root, number) > 0) 
			x0 = x2;
		else if (func (x2, root, number) * func (x0, root, number) < 0)
			x1 = x2;
		count++;
	}
	return x2;
}

int main () {
	double lbound, ubound, number, estimate;
	int root;
	printf ("Enter number: ");
	scanf ("%lf", &number);
	printf ("Enter the root's order: ");
	scanf ("%d", &root);
	estimateBounds (number, root, &lbound, &ubound);
	printf("Lower bound: %lf\t Upper bound: %lf\n", lbound, ubound);
	estimate = RegulaFalsi (number, root, lbound, ubound);
	printf ("Final estimation: %.15lf", estimate);
	return 0;
}
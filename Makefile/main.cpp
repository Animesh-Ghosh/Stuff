#include <iostream>
#include "complex.h"

using namespace std;

int main (void) {
	Complex c1, c2 (3, -5);
	c1.setValue ();
	cout << "Complex number c1: ";
	c1.printComplex ();
	cout << "Complex number c2: ";
	c2.printComplex ();
	return 0;
}
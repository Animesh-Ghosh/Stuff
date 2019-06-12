#include <iostream>
#include "complex.hpp"

using namespace std;

int main (void) {
	Complex c1, c2 (3, -5), c3;
	c1.setValue ();
	cout << "Complex number c1: ";
	c1.printComplex ();
	cout << "Complex number c2: ";
	c2.printComplex ();
	cout << "Adding c1 and c2..." << endl;
	c3 = c1 + c2;
	cout << "c1 + c2 = ";
	c3.printComplex ();
	return 0;
}
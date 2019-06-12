#include <iostream>
#include "complex.h"

using namespace std;

void Complex::setValue () {
	cout << "Enter real part: ";
	cin >> a;
	cout << "Enter imaginary part: ";
	cin >> b;
	this->a = a; this->b = b;
}

void Complex::printComplex () {
	if (b < 0) cout << a << " - i" << ((-1) * b) << endl;
	else cout << a << " + i" << b << endl;
}
#include <iostream>
#include "complex.hpp"

void Complex::setValue () {
	std::cout << "Enter real part: ";
	std::cin >> a;
	std::cout << "Enter imaginary part: ";
	std::cin >> b;
	this->a = a; this->b = b;
}

void Complex::printComplex () {
	if (b == 0) std::cout << a << " + i0" << std::endl;
	else if (b < 0) std::cout << a << " - i" << ((-1) * b) << std::endl;
	else std::cout << a << " + i" << b << std::endl;
}

Complex Complex::operator + (Complex &c) {
	Complex temp;
	temp.a = this->a + c.a;
	temp.b = this->b + c.b;
	return temp;
}
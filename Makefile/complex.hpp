#ifndef COMPLEX_HPP
	#define COMPLEX_HPP

	class Complex {
	private:
		double a, b;
	public:
		Complex (): a(0), b(0) {}
		Complex (double a, double b): a (a), b (b) {}
		void setValue ();
		void printComplex ();
		Complex operator + (Complex&);
	};

#endif
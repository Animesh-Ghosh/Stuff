#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int Fibonacci (int N) {
	int size = 3;
	static int *fib = new int[size];
	fib[1] = 0; fib[2] = 1;
	if (N == 1) return fib[1];
	else if (N == 2) return fib[2];
	else {
		// memoize this shit
	}
}

int main () {
	int n;
	cout << "Enter number of terms: ";
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cout << Fibonacci (i) << " ";
	return 0;
}

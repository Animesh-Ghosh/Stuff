#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long Fibonacci (int N) {
    static unsigned long long fib[100] = {}; 
    // initialises the array with all elements as 0
    fib[1] = 0; fib[2] = 1;
	if (N == 1 || N == 2) return fib[N];
	else if (fib[N] != 0) return fib[N];
	else {
	    fib[N] = Fibonacci (N - 1) + Fibonacci (N - 2);
	    return fib[N];
	}
}

int main (int argc, char const *argv[]) {
	int n;
	if (argc == 2) n = atoi (argv[1]);
	else {
		cout << "Enter number of terms: ";
		cin >> n;
	}
	// works correctly till i = 93 for signed long long
	// works correctly till i = 94 for unsigned long long
	unsigned long long prev = Fibonacci (1);
	for (int i = 1; i <= n; i++) {
		if  (prev > Fibonacci (i)) {
			n = i - 1;
			break;
		}
		prev = Fibonacci (i);
	}
	cout << "First " << n << " terms of Fibonacci series: " << endl; 
	for (int i = 1; i <= n; i++) 
		cout << Fibonacci (i) << endl;
	return 0;
}
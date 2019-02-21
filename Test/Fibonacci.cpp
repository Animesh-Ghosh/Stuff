#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int Fibonacci (int N) {
	static int *fib = new int[3];
	fib[0] = -1;
	fib[1] = 0; fib[2] = 1;
	int size = sizeof (fib))/sizeof (int);
	if (N > size) {
		int *ftemp = new int[2 * N];
		ftemp[0] = -1;
		for (int i = 1; i < 2 * N; i++) {
			if (i < size) ftemp[i] = fib[i];
			else ftemp[i] = 0;
		}
		
	}
	if (N == 1) return 0;
	else if (N == 2) return 1;
	return Fibonacci (N - 1) + Fibonacci (N - 2);
}

int main () {
	int n;
	cout << "Enter number of terms: ";
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cout << Fibonacci (i) << " ";
	return 0;
}

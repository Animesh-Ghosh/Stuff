# include <iostream>
# include <conio.h>
# include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;

// thought of using binary search in my mind
int BinSearch (int &val, int Ar[], int &N) {
	int low = 0, high = N - 1, mid;
	while (low != high) {
		mid = (low + high) / 2;
		if (val < Ar[mid]) high = mid - 1;
		else if (Ar[mid] < val) low = mid + 1;
		else return 1;
	}
}

/* Sieve of Eratosthenes (for reference)
1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
2. Initially, let p equal 2, the smallest prime number.
3. Enumerate the multiples of p by counting to n from 2p in increments of p, and mark them in the list 
(these will be 2p, 3p, 4p, ...; the p itself should not be marked).
4. Find the first number greater than p in the list that is not marked. If there was no such number, stop.
Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
5. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.
*/

void Prime (int &N) {
	int *Sieve = new int[N - 1];
	for (int i = 2; i < (N + 1); i++) Sieve[i - 2] = i;
	int prime = Sieve[0];
	for (int j = prime; j < (N - 1); prime+=prime) {
		if (Sieve[j] % prime == 0) {
			Sieve[j] = 0;
		}
		cout << Sieve[j] << " ";
	}
}

int main () {
	int x;
	cin >> x;
	Prime (x);
//	if (Prime (x)) cout << "Prime!" << endl;
//	else cout << "Composite!" << endl;
	getch ();
	return 0;
}

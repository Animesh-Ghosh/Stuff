# include <iostream>
# include <conio.h>
# include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;

// thought of using binary search in my mind
int BinSearch (int &val, int Ar[], int &N) {
	int low = 0, high = N - 1, mid, flag = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (val < Ar[mid]) high = mid - 1;
		else if (Ar[mid] < val) low = mid + 1;
		else {
			flag = 1;
			break;
		}
	}
	if (flag) return flag;
	else return flag;
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
	cout << "Generating list..." << endl;
	for (int i = 2; i < (N + 1); i++) Sieve[i - 2] = i; // generating list
	
	int prime = Sieve[0]; // initialising prime to 2
	for (i = 0; i < (N - 1); i++) cout << Sieve[i] << " ";
	
	cout << endl << "Marking multiples of " << prime << "..." << endl;
	for (i = prime; i < (N - 1); i += prime) // marking multiples of selected prime
		if (Sieve[i] % prime == 0) Sieve[i] = 0;
	for (i = 0; i < (N - 1); i++) cout << Sieve[i] << " ";
	
	int count = 0;
	cout << endl << "Counting zero elements..." << endl;
	for (i = 0; i < (N - 1); i++)  // counting zero elements
		if (Sieve[i] == 0) count++;
	cout << "Zero element count: " << count << endl;
	
	int *tSieve = new int[N - 1 - count];
	int k = 0;
	cout << "Creating sieved list..." << endl;
	for (int j = 0; j < (N - 1); j++) {
		if (Sieve[j] != 0) {
			cout << "Found non-zero element! ";
			tSieve[k] = Sieve[j];
			cout << tSieve[k] << endl;
			k++;
		}
	}
	for (int j = 0; j < (N - 1 - count); j++) cout << tSieve[j] << " ";
	
	cout << endl << "Selected prime: " << prime << endl;;
	prime = tSieve[1];
	cout << "New prime: " << prime << endl;
	delete []Sieve;
	Sieve = tSieve;
	delete []tSieve;
	cout << "Sieved list: " << endl;
	for (i = 0; i < (N - 1 - count); i++) cout << Sieve[i] << " ";
	int size = N - 1 - count;
	//if (BinSearch (N, Sieve, size)) cout << "Number still in sieve!" << endl;
	//else cout << "Number not prime!" << endl;
}

int main () {
	
//	int Ar[] = {2, 3, 4, 6, 7, 8, 10}, N = 7;
//	for (int i = 0; i < N; i++) {
//		if (BinSearch (Ar[i], Ar, N)) cout << Ar[i] << " found!" << endl;
//		else cout << Ar[i] << " not found!" << endl;
//	}
	
	getch ();
	return 0;
}

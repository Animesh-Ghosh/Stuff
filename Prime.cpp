# include <iostream>
# include <conio.h>

using std::cin;
using std::cout;
using std::endl;

/*
1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
2. Initially, let p equal 2, the smallest prime number.
3. Enumerate the multiples of p by counting to n from 2p in increments of p, and mark them in the list 
(these will be 2p, 3p, 4p, ...; the p itself should not be marked).
4. Find the first number greater than p in the list that is not marked. If there was no such number, stop.
Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
5. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.
*/

int BinSearch (int &val, int Ar[], int N) {
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

void Generate (int List[], int N) {
	cout << "Generating list: " << endl;
	for (int i = 0; i < N; i++) List[i] = i;
	List[0] = List[1];
}

void Show (int List[], int N, int prime) {
	for (int i = prime; i < N; i++) cout << List[i] << " ";
	cout << endl;
}

void Mark (int List[], int N, int &prime) {
	cout << "Marking multiples of " << prime << ": " << endl;
	for (int i = prime * prime; i < N; i += prime) 
		if (List[i] % prime == 0) List[i] = 0;
}

int zeroCount (int List[], int N, int &prime) {
	int count = 0;
	cout << "Counting zero-elements: " << endl;
	for (int i = prime; i < N; i++) 
		if (List[i] == 0) count++;
	return count;
}

void Generate (int Sieve[], int List[], int N, int &prime) {
	int k = 0;
	cout << "Generating sieved list: " << endl;
	for (int i = prime; i < N; i++) {
		if (List[i] != 0) {
			Sieve[k] = List[i];
			k++;
		}
	}
}

void Prime (int &N) {
	int *List = new int[N + 1];
	int i;
	Generate (List, (N + 1));
	int prime = List[2];
	Show (List, (N + 1), prime);
	Mark (List, (N + 1), prime);
	Show (List, (N + 1), prime);
	int count = 0;
	count = zeroCount (List, (N + 1), prime);
	cout << "Zero-element count: " << count << endl;
	int *Sieve = new int[N - 1 - count];
	Generate (Sieve, List, (N + 1), prime);
	Show (Sieve, (N - 1 - count), 0);
	if (BinSearch (N, Sieve, (N + 1))) cout << N << " in list!" << endl;
	else cout << N << " not in list!" << endl;
	cout << "Current prime: " << prime << endl;
	prime = Sieve[1];
	cout << "New prime: " << prime << endl;
	delete []Sieve;
}

int main () {
	int x;
	cin >> x;
	Prime (x);
	getch ();
	return 0;
}

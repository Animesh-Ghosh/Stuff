# include <iostream>

using std::cin;
using std::cout;
using std::endl;

// pseudo rng
/*
int main () {
	int seed, alpha = 300, beta = 100, range, rand;
	cout << "Enter seed value: ";
	cin >> seed;
	cout << "Enter range: ";
	cin >> range;
	for (int i = 0; i < range; i++) {
		rand = (alpha * seed + beta) % range;
		for (int j = 0; j < range; j++) rand = (alpha * rand + beta) % range;
		cout << "Random number: " << rand << endl;
		seed = rand;
	}
	return 0;
}
*/

// x = (a*x +b)%m, a, b, m are very large

# include <cstdlib>
# include <ctime>

int main() {
    srand ((unsigned) time (0));
	int random_integer = rand ();
	cout << random_integer << endl;
}

# include <iostream>
# include <conio.h>

using std::cin;
using std::cout;
using std::endl;

int BinSearch (int val, int Ar[], int N) {
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

int main () {
	int ar[] = {2};
	if (BinSearch (2, ar, 1)) cout << "Found!" << endl;
	else cout << "Not found!" << endl;
	getch ();
	return 0;
}

# include <iostream>
# include <ctype.h>
# include <stdlib.h>

using namespace std;

void convertDigit (char &S, int key) {
	S = (S + key) % (57 - key);
}

void convertAlpha (char &S, int key) {
	if (isupper (S)) {
		if (S == 90) {
			S = 65;
			S += (key - 1);
		}
		else S += key;
	}
	else if (islower (S)) {
		if (S == 122) {
			S = 97;
			S += (key - 1);
		}
		else S += key;
	}
}

int main () {
	char x = '0';
	for (int i = 0; i < 10; i++) {
		convertDigit ((x + i), 4);
		cout << i << endl;
	}
    return 0;
}

#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {
	char x = 'A', y = 'a', z = '0';
	for (int i = 0; i < 26; i++) 
		cout << (char) (x + i) << " = " << (int) (x + i) << "\t" << (char) (y + i) << " = " << (int) (y + i) << endl;
	for (int i = 0; i < 10; i++) 
		cout << (char) (z + i) << " = " << (int) (z + i) << endl;
//	for (int i = 0; i < 256; i++) 
//		cout << i << " = " << "\'" << (char) i << "\'" << endl;
	return 0;
}

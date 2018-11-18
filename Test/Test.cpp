#include <iostream>

using namespace std;

int main() {
	int bytes = sizeof (int) * 100000;
	cout << "MBs: " << (float) bytes / (1024 * 1024) << endl;
	return 0;
}

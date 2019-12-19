#include <iostream>
#include <vector>
#include <string>

// generate the entry of Pascal's triangle
unsigned long pascal(int n, int k) {
	static std::vector<std::vector<unsigned long>> v = { { 1 } };
	int K = (k > n - k) ? n - k : k;  // pascal(n, k) = pascal(n, n - k)
	if (n != 0 && k == 0) {
		v.push_back({ 1 });
	}
	else if (n % 2 == 1 && v[n].size() < (n + 1) / 2) {  // odd row
		auto entry = pascal(n - 1, K - 1) + pascal(n - 1, K);
		v[n].insert(v[n].begin() + K, entry);
	}
	else if (n % 2 == 0 && v[n].size() < (n / 2) + 1) {  // even row
		auto entry = pascal(n - 1, K - 1) + pascal(n - 1, K);
		v[n].insert(v[n].begin() + K, entry);
	}
	return v[n][K];
}

// helper function to print each row of Pascal's triangle
void pascal_triangle(int rows) {
	bool overflow = false;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j <= i; ++j) {
			auto entry = pascal(i, j);
			if (entry < 0) {  // checking for overflow
				std::cout << "Overflow\n";
				overflow = true;
				break;
			}
			std::cout << entry << ' ';
		}
		if (overflow)
			break;
		std::cout << '\n';
	}
}

// driver function
int main(const int argc, const char* argv[]) {
	if (argc == 1) { // interactive
		std::cout << "Enter number of rows of Pascal's triangle: ";
		int rows;
		std::cin >> rows;
		std::cout << "First " << rows << "row(s) of Pascal's triangle:\n";
		pascal_triangle(rows);
	}
	else {
		pascal_triangle(std::stoi(argv[1]));
	}
	return 0;
}

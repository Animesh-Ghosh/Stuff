#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

void Enter (int**, int&);
void Minor (int**, int**, int, int, int&);
int detA (int**, int);

// determinant using dynamic memory allocation
int main () {
	int **A, N, det;
	cin >> N;
	A = new int*[N]; // allocating memory for matrix
	for (int i = 0; i < N; i++)
		A[i] = new int[N];
	Enter (A, N);
	det = detA (A, N);
	cout << det;
	for (int i = 0; i < N; i++) // deallocating memory after use
		delete A[i];
	delete A;
	return 0;
}

void Enter (int **A, int &n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
}

int detA(int **A, int n) {
	int det = 0, i;
	int **M;
	M = new int*[n - 1]; // allocating memory for minor matrix
	for (int i = 0; i < n - 1; i++)
		M[i] = new int[n - 1];
	if (n==1) return A[0][0];
	else {
		for (i=0; i<n; i++) {
			if (A[0][i] == 0) continue;
			else {
				Minor (A, M, 0, i, n);
				det = det + (pow (-1, i) * A[0][i] * detA (M, n - 1));
			}
		}
		return det;
	}
	for (int i = 0; i < n - 1; i++) // deallocating memory after use
		delete M[i];
	delete M;
}

void Minor(int **A, int **M, int I, int J, int &n) {
	int i, j, k = 0, l = 0;
	for (i = 0; i < n; i++) {
		if (i != I) {
			for (j = 0; j < n; j++) {
				if (j != J) {
					M[k][l] = A[i][j];
					l++;
				}
			}
			l=0;
		k++;
		}
	}
}

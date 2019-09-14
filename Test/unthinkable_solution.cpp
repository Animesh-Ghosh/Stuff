#include <iostream>

int diff_sum_diag (int **M, int N) {
    int major_diag_sum = 0, minor_diag_sum = 0, diff;
    for (int i = 0; i < N; i++)
        major_diag_sum += M[i][i];
    for (int j = 0, k = N; j < N, k > 0; j++, k--)
        minor_diag_sum += M[j][k - 1];
    diff = major_diag_sum - minor_diag_sum;
    return diff;
}

int main () {
    int N;
    int **M;
    std::cin >> N;
    M = new int *[N];
    for (int i = 0; i < N; i++)
        M[i] = new int[N];
    for (int j = 0; j < N; j++)
        for (int k = 0; k < N; k++)
            std::cin >> M[j][k];
    int result = diff_sum_diag (M, N);
    std::cout << result;
    for (int i = 0; i < N; i++)
        delete M[i];
    delete[] M;
    return 0;
}
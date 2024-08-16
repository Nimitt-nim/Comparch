#include <iostream>
#include <vector>
#include <ctime> // For std::clock and std::clock_t

void multiply_matrices(const std::vector<std::vector<long>>& A, const std::vector<std::vector<long>>& B, std::vector<std::vector<long>>& C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    std::vector<int> sizes = {64, 128, 256, 512, 1024};
    for (int N : sizes) {
        std::vector<std::vector<long>> A(N, std::vector<long>(N, 1));
        std::vector<std::vector<long>> B(N, std::vector<long>(N, 1));
        std::vector<std::vector<long>> C(N, std::vector<long>(N, 0));

        struct timespec start, end;
        struct rusage usage;
        clock_gettime(CLOCK_MONOTONIC, &start);

        multiply_matrices(A, B, C, N);
        clock_gettime(CLOCK_MONOTONIC, &end);
        getrusage(RUSAGE_SELF, &usage);
        printf("Int Matrix Size %d:\n", N);
        printf("User CPU Time: %ld.%06ld sec\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
        printf("System CPU Time: %ld.%06ld sec\n\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    }
    return 0;
}
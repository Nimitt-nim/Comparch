#include <iostream>
#include <vector>
#include <ctime>

std::vector<long long> memo(51, -1);

long long fibonacci_memo(int n) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
    return memo[n];
}

void print_fibonacci_memo(int terms) {
    for (int i = 0; i < terms; ++i) {
        std::cout << fibonacci_memo(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int TERMS = 50;

    clock_t start = clock();
    print_fibonacci_memo(TERMS);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}

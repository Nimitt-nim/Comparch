#include <iostream>
#include <vector>
#include <ctime>

int fibonacci_rec(long long n) {
    if (n <= 1) return n;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

void print_fibonacci_rec(int terms) {
    for (int i = 0; i < terms; ++i) {
        std::cout << fibonacci_rec(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int TERMS = 50;

    clock_t start = clock();
    print_fibonacci_rec(TERMS);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}


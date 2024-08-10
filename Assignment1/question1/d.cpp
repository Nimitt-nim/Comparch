#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> fibonacci_loop_memo(int terms) {
    std::vector<int> fib(terms);
    if (terms > 0) fib[0] = 0;
    if (terms > 1) fib[1] = 1;

    for (int i = 2; i < terms; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

int main() {
    const int TERMS = 50;

    clock_t start = clock();
    std::vector<int> fib = fibonacci_loop_memo(TERMS);
    for (int num : fib) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}

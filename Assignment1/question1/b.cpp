#include <iostream>
#include <vector>
#include <ctime>

void print_fibonacci_loop(int terms) {
    std::vector<long long> fib(terms);
    if (terms > 0) fib[0] = 0;
    if (terms > 1) fib[1] = 1;

    for (int j = 2; j < terms;++j){
        for (int i = 2; i < terms; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }

    for (int i = 0; i < terms; i++) {
        std::cout << fib[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int TERMS = 50;

    clock_t start = clock();
    print_fibonacci_loop(TERMS);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}

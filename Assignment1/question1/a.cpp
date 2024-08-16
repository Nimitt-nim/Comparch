#include <iostream>
#include <vector>
#include <time.h>

long long fib_rec(long long n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int main() {

    struct timespec start, end;
    struct rusage usage;
    clock_gettime(CLOCK_MONOTONIC, &start);

    std::vector<long long> list;
    for (long long i = 0; i < 50; ++i) {
        list.push_back(fib_rec(i));
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    getrusage(RUSAGE_SELF, &usage);
    printf("User CPU Time: %ld.%06ld sec\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("System CPU Time: %ld.%06ld sec\n\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
}
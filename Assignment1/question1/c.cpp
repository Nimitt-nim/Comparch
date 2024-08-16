#include <iostream>
#include <vector>

std::vector<long long> memo(50,-1);

long long fib_rec_mem(long long n) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fib_rec_mem(n - 1) + fib_rec_mem(n - 2);
    return memo[n];
}

int main() {

    struct timespec t_start;
    struct timespec t_end;
    std::vector<long long> list;

    timespec_get(&t_start, TIME_UTC);
    for (long long i = 0; i < 50; ++i) {
            list.push_back(fib_rec_mem(i));
    }
    timespec_get(&t_end, TIME_UTC);

    printf("%ld",t_end.tv_nsec-t_start.tv_nsec);
    printf("\n");
    for (int i = 0; i < 50; i++){
        printf("%lld ",list[i]);
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>


long long fib_loop(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;

    long long prev = 0;
    long long ans = 1;
    long long temp;

    for (int j = 1; j < n;++j){
        temp = ans;
        ans = ans + prev;
        prev = temp;
    }

    return ans; 
}

int main() {

    struct timespec t_start;
    struct timespec t_end;
    std::vector<long long> list;

    timespec_get(&t_start, TIME_UTC);
    for (long long i = 0; i < 50; ++i) {
        list.push_back(fib_loop(i));
    }
    
    timespec_get(&t_end, TIME_UTC);
    printf("%ld",t_end.tv_nsec - t_start.tv_nsec);
    printf("\n");
    for (int i = 0; i < 50; i++){
        printf("%lld ",list[i]);
    }
    return 0;
}

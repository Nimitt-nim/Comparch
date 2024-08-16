#include <iostream>
#include <vector>
#include <ctime>



int main() {

    struct timespec t_start;
    struct timespec t_end;
    timespec_get(&t_start, TIME_UTC);

    std::vector<long long> list(50,-1);
    list[0] = 0;
    list[1] = 1;
    for (int i = 2; i < 50; ++i) {
        list[i] = list[i - 1] + list[i - 2];
    }
    timespec_get(&t_end, TIME_UTC);
    printf("%ld",t_end.tv_nsec - t_start.tv_nsec);
    printf("\n");
    for (int i = 0; i < 50; i++){
        printf("%lld ",list[i]);
    }
    return 0;
}

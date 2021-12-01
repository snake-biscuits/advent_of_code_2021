#include <cstdio>
#include <stdexcept>

#include "../common/readlines.hpp"


void print_usage(char name[]) {
    printf("USAGE: %s INPUT.TXT\n", name);
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return 0;
    }
    int depths[2000];
    int depths_count = readlines_int(argv[1], depths);
    int increases = 0;  // <- solution
    int last_window_sum = depths[0] + depths[1] + depths[2];
    for (int i = 1; i < depths_count - 2; i++) {
        int window_sum = last_window_sum - depths[i - 1] + depths[i + 2];
        if (window_sum > last_window_sum) {
            increases++;
        }
        last_window_sum = window_sum;
    }
    printf("Depth window increases %d times\n", increases);
    return 0;
}

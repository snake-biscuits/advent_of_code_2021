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
    int last_depth = depths[0];
    for (int i = 1; i < depths_count; i++) {
        int depth = depths[i];
        if (depth > last_depth) {
            increases++;
        }
        last_depth = depth;
    }
    printf("Depth increases %d times\n", increases);
    return 0;
}

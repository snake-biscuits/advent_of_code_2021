#include <cmath>
#include <cstdio>
#include <cstring>

#include "../common/readlines.hpp"


void print_usage(char name[]) {
    printf("USAGE: %s DIAGNOSTIC.TXT", name);
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    int bit[12];
    memset(bit, 0, sizeof(int) * 12);
    int masked_bit;

    int diagnostic[1000];
    int line_count = readlines_bin(argv[1], diagnostic);

    for (int i = 0; i < line_count; i++) {
        for (int j = 0; j < 12; j++) {
            masked_bit = diagnostic[i] >> j && 1;
            bit[j] += 2 * -masked_bit + 1;  // 0 = 1; 1 = -1;
        }
    }

    int gamma = 0;
    int epsilon = 0;
    int set_bit;
    for (int i = 0; i < 12; i++) {
        set_bit = pow(2, i);
        if (bit[i] < 0) {
            gamma += set_bit;
        }
        else {
            epsilon += set_bit;
        }
    }

    printf("gamma = %d, epsilon = %d\n", gamma, epsilon);
    printf("solution = %d\n", gamma * epsilon);
}

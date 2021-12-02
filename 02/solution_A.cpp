#include "../common/readlines.hpp"


void print_usage(char name[]) {
    printf("USAGE: %s DIRECTIONS.TXT", name);
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    // TODO: ... the solution
}

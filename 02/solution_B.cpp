#include <cstring>

#include "../common/readlines.hpp"


void print_usage(char name[]) {
    printf("USAGE: %s DIRECTIONS.TXT", name);
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char* lines[1000];
    int   line_count = readlines(argv[1], lines);
    char  xbuf[32];
    int   horizontal_position = 0;
    int   depth = 0;
    int   aim = 0;
    int   x;
    for (int i = 0; i < line_count; i++) {
        if (!strncmp(lines[i], "forward", 7)) {
            strcpy(xbuf, lines[i] + 7);
            x = atoi(xbuf);
            horizontal_position += x;
            depth += aim * x;
        }
        else if (!strncmp(lines[i], "back", 4)) {
            strcpy(xbuf, lines[i] + 4);
            x = atoi(xbuf);
            horizontal_position -= x;
        }
        else if (!strncmp(lines[i], "down", 4)) {
            strcpy(xbuf, lines[i] + 4);
            x = atoi(xbuf);
            aim += x;
        }
        if (!strncmp(lines[i], "up", 2)) {
            strcpy(xbuf, lines[i] + 2);
            x = atoi(xbuf);
            aim -= x;
        }
    }
    printf("horizontal_position = %d, depth = %d\n", horizontal_position, depth);
    printf("solution = %d\n", horizontal_position * depth);
}

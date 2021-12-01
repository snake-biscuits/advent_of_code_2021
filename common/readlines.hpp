// last year's get_numbers.h, as cpp
#include <cstdio>
#include <fstream>
#include <stdexcept>


// copies integers from each line of the given text file to int* output; returns number of lines read
int readlines_int(const char filename[], int* values) {
    std::fstream  file;
    file.open(filename, std::ios::in);
    if (!file) {
        fprintf(stderr, "Couldn't open %s\n", filename);
        throw std::runtime_error("FileNotFound\n");
    }

    int lines_read = 0;
    std::string line;
    while (std::getline(file, line)) {
            values[lines_read] = atoi(line.c_str());
            lines_read++;
    }
    file.close();
    return lines_read;
}
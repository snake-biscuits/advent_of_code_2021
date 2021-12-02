// last year's get_numbers.h, as cpp
#include <cstdio>
#include <fstream>
#include <stdexcept>
#include <vector>


// copies integers from each line of the given text file to int* output; returns number of lines read
int readlines_int(const char filename[], int* values) {
    std::fstream file;
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


void readlines_split(const char filename[], std::vector<std::vector<std::string>>* lines) {
    std::fstream file;
    file.open(filename, std::ios::in);
    if (!file) {
        fprintf(stderr, "Couldn't open %s\n", filename);
        throw std::runtime_error("FileNotFound\n");
    }

    std::string line;
    while (std::getline(file, line)) {
            std::vector<std::string> split_line;
            std::istringstream line_stream(line);
            std::string token;
            while (std::getline(line_stream, token, " ") {
                split_line.push_back(token);
            }
            lines->push_back(split_line);
    }
    file.close();
}

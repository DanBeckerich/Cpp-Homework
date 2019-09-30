#include "../include/util.hpp"
#include <sstream>

//convert chars 0-9 to an integer
int char_to_int(char character) {
    std::stringstream temp;
    temp << character;
    int x;
    temp >> x;
    return x;
}

//concatenate two ints
int concatenate(int i, int j) {
    return stoi(std::to_string(i) + std::to_string(j));
}

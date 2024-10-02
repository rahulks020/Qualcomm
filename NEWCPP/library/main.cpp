// main.cpp

#include <iostream>
#include "math_utils.h"

int main() {
    int result_add = MathUtils::add(5, 3);
    int result_subtract = MathUtils::subtract(10, 4);

    std::cout << "Addition Result: " << result_add << std::endl;
    std::cout << "Subtraction Result: " << result_subtract << std::endl;

    return 0;
}

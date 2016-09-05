#include <iostream>
#include <cmath>
#include <float.h>

int main(int argc, char *argv[]) {
    double number_d;

    std::cin >> number_d;

    if (number_d < 1) {
        std::cout << 0;
        return 0;
    }

    const size_t number = static_cast<size_t>(number_d);
    if (std::abs(number_d - static_cast<double>(number)) > DBL_EPSILON) {
        std::cout << 0;
        return 0;
    }

    const size_t sugg_ans = static_cast<size_t>(std::floor(std::sqrt(2 * number_d)));
    if ((sugg_ans * (sugg_ans + 1)) / 2 == number) {
        std::cout << sugg_ans;
    } else {
        std::cout << 0;
    }

    return 0;
}
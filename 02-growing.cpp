#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <cfloat>

std::string strip(const std::string &s) {
    size_t offset = 0;
    while (s[offset] == ' ') {
        offset++;
    }
    return s.substr(offset);
}

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, char *argv[]) {
    const std::string error("[error]");
    try {
        std::string N_str;
        std::cin >> N_str;
        const double N_d = std::stod(N_str);
        const size_t N = static_cast<size_t>(N_d);
        if (std::abs(N_d - static_cast<double>(N)) > DBL_EPSILON) {
            std::cout << error;
            return 0;
        }
        if (N == 1) {
            std::cout << error;
            return 0;
        }

        std::string line;
        std::getline(std::cin, line);
        const std::vector<std::string> numbers_s = split(strip(line), ' ');
        std::vector<double> numbers;
        for (size_t i = 0; i < N; ++i) {
            numbers.push_back(std::stod(numbers_s[i]));
        }

        size_t start = 0, length = 1, max_start = 0, max_length = 1;

        for (size_t i = 1; i < N; ++i) {
            if (numbers[i] < numbers[i - 1]) {
                length = 1;
                start = i;
            } else {
                length++;
                if (max_length < length) {
                    max_length = length;
                    max_start = start;
                }
            }
        }

        if (max_length == 1) {
            std::cout << 0;
        } else {
            std::cout << max_length << ' ' << (max_start + 1);
        }
    } catch (std::exception &e) {
        std::cout << error;
    }

    return 0;
}

//
// Created by longpham on 15/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_DECIMAL2HEXA_H
#define CPLUSPLUS_PRACTICE_DECIMAL2HEXA_H

#include <iterator>
#include <iostream>

namespace {
    const std::string encoded{"0123456789ABCDEF"};

    template <int input_base, int output_base>
    std::string convert_base(const std::string& input) {
        int value{0};
        for (auto it = std::begin(input); it != std::end(input); ++it) {
            value *= input_base;
            value += *it - '0';
        }

        std::string output{};
        while (value > 0) {
            int temp = value / output_base;
            if (temp > 0) {
                int remainder = value % temp;
                output = std::string{encoded[remainder]} + output;
                value = temp;
            } else {
                output = std::string{encoded[value]} + output;
                break;
            }
        }

        return output;
    }

    void run() {
        std::string base10{"256"};
        std::cout << "base 10 : " << base10 << "'\t-> base 2: " << convert_base<10, 2>(base10) << std::endl;
        std::cout << "base 10 : " << base10 << "'\t-> base 16: " << convert_base<10, 16>(base10) << std::endl;
    }
}
#endif //CPLUSPLUS_PRACTICE_DECIMAL2HEXA_H

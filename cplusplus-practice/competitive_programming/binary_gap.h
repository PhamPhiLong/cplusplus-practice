//
// Created by longpham on 20/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_BINARY_GAP_H
#define CPLUSPLUS_PRACTICE_BINARY_GAP_H

#include <algorithm>
#include <iostream>

// https://codility.com/programmers/lessons/1-iterations/binary_gap/start/

// A binary gap within a positive integer N is any maximal sequence of consecutive zeros
// that is surrounded by ones at both ends in the binary representation of N.

// For example, number 9 has binary representation 1001 and contains a binary gap of length 2.
// The number 529 has binary representation 1000010001 and contains two binary gaps:
// one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains
// one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.

namespace {
    using namespace std;

    int binary_gap(int N) {
        // write your code in C++14 (g++ 6.2.0)
        int gap{0}, temp{0};
        bool start = false;

        while (N > 0) {
            int bit = N & 1;
            if (bit == 1) {
                gap = std::max(gap, temp);
                temp = 0;
                start = true;
            } else {
                if (start) ++temp;
            }
            N >>= 1;
        }

        return gap;
    }

    void run() {
        int num{251};
        cout << num << "\t" << "binary gap: " << binary_gap(num);
    }
}
#endif //CPLUSPLUS_PRACTICE_BINARY_GAP_H

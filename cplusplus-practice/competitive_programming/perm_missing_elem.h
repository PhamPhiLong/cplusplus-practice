//
// Created by longpham on 20/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_PERM_MISSING_ELEM_H
#define CPLUSPLUS_PRACTICE_PERM_MISSING_ELEM_H

// https://codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/start/

//A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
//
//Your goal is to find that missing element.
//
//Write a function:
//
//int solution(vector<int> &A);
//that, given a zero-indexed array A, returns the value of the missing element.
//
//For example, given array A such that:
//
//A[0] = 2
//A[1] = 3
//A[2] = 1
//A[3] = 5
//the function should return 4, as it is the missing element.

#include <vector>
#include <iostream>

namespace  {
    int perm_missing_elem(std::vector<int> &A) {
        long sum{0};

        for (auto num : A) {
            sum += num;
        }

        long N = A.size();
        return (1 + N+1) * (N+1) / 2 - sum;
    }

    void run() {
        std::vector<int> A{1, 4, 2, 3, 6};
        std::cout << perm_missing_elem(A);
    }
}
#endif //CPLUSPLUS_PRACTICE_PERM_MISSING_ELEM_H

//
// Created by longpham on 20/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_ODD_OCCURANCE_IN_ARRAY_H
#define CPLUSPLUS_PRACTICE_ODD_OCCURANCE_IN_ARRAY_H

#include <unordered_map>
#include <vector>
#include <iostream>

// https://codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/start/

// Task description
// A non-empty zero-indexed array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.
//
// For example, in array A such that:
//
// A[0] = 9  A[1] = 3  A[2] = 9
// A[3] = 3  A[4] = 9  A[5] = 7
// A[6] = 9
// the elements at indexes 0 and 2 have value 9,
// the elements at indexes 1 and 3 have value 3,
// the elements at indexes 4 and 6 have value 9,
// the element at index 5 has value 7 and is unpaired.

namespace {
    using namespace std;

    int odd_occurrences(vector<int> &A) {
        unordered_map<int, int> map{};
        for (auto num : A) {
            map[num]++;
        }

        for (auto value : map) {
            if (value.second % 2 != 0) return value.first;
        }

        return -1;
    }

    void run() {
        vector<int> A{9, 3, 9, 3, 9, 7, 9};
        cout << odd_occurrences(A);
    }
}
#endif //CPLUSPLUS_PRACTICE_ODD_OCCURANCE_IN_ARRAY_H

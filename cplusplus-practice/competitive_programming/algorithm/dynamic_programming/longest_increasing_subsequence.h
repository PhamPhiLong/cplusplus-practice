//
// Created by Pham Phi Long on 9/10/2017.
//

#ifndef CPLUSPLUS_PRACTICE_LONGEST_INCREASING_SUBSEQUENCE_H
#define CPLUSPLUS_PRACTICE_LONGEST_INCREASING_SUBSEQUENCE_H

// The Longest Increasing Subsequence (LIS) problem is to find the length of
// the longest subsequence of a given sequence such that all elements of the
// subsequence are sorted in increasing order.
//
// For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80}
// is 6 and LIS is {10, 22, 33, 50, 60, 80}.

#include <vector>
#include <iostream>

namespace {
    template <typename T>
    int longest_increasing_subsequence(int index, const std::vector<T>& sequence, std::vector<int>& lis_cache) {
        if (index == 0) return 1;
        if (lis_cache[index] > 1) return lis_cache[index];

        int max_lis{1};

        for (int i=0; i<index; ++i) {
            if (sequence[index] <= sequence[i]) continue;
            max_lis = std::max(max_lis, longest_increasing_subsequence(i, sequence, lis_cache) +1);
        }

        lis_cache[index] = max_lis;
        return max_lis;
    }

    template <typename T>
    int find_longest_increasing_subsequence(const std::vector<T>& sequence) {
        std::vector<int> lis_cache(sequence.size(), 0);
        return longest_increasing_subsequence(sequence.size()-1, sequence, lis_cache);
    }
    void run() {
        std::vector<int> sequences{10, 22, 9, 33, 21, 50, 41, 60, 80};

        std::cout << "Length of longest increasing sub-sequence is " << find_longest_increasing_subsequence(sequence) << std::endl;
    }
};
#endif //CPLUSPLUS_PRACTICE_LONGEST_INCREASING_SUBSEQUENCE_H

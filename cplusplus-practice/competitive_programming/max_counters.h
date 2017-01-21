//
// Created by Pham Phi Long on 1/21/2017.
//

#ifndef CPLUSPLUS_PRACTICE_MAX_COUNTERS_H
#define CPLUSPLUS_PRACTICE_MAX_COUNTERS_H

#include <vector>
#include <iostream>

namespace {
    using namespace std;

    vector<int> max_counters(int N, vector<int> &A) {
        int max_pos = -1;
        int min_val = 0;
        vector<int> counters(N);
        for (auto operation : A) {
            --operation;
            if (operation < N) {
                if (counters[operation] < min_val) {
                    counters[operation] = min_val;
                }
                ++counters[operation];
                if (max_pos == -1) {
                    max_pos = operation;
                } else {
                    if (counters[operation] > counters[max_pos]) {
                        max_pos = operation;
                    }
                }
            } else {
                min_val = counters[max_pos];
                max_pos = -1;
            }
        }

        for (auto& counter : counters) {
            if (counter < min_val) counter = min_val;
        }

        return counters;
    }

    void run() {
        vector<int> operations{3, 4, 4, 6, 1, 4, 4};
        int N = 5;
        auto counters = max_counters(N, operations);
        for (auto counter : counters) {
            cout << counter << " ";
        }
    }
}
#endif //CPLUSPLUS_PRACTICE_MAX_COUNTERS_H

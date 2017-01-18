//
// Created by longpham on 19/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_COIN_CHANGE_H
#define CPLUSPLUS_PRACTICE_COIN_CHANGE_H

#include <vector>
#include <iostream>

namespace {
    std::vector<std::vector<long>>cache;

    long find(int n, int i, const std::vector<int>& coins) {
        if (n == 0) {
            cache[n][i] = 1;
            return 1;
        }

        if (n < 0 || i >= coins.size()) {
            return 0;
        }

        if (cache[n][i] >= 0) {
            return cache[n][i];
        }

        long result = find(n-coins[i], i, coins) + find(n, i+1, coins);
        cache[n][i] = result;
        return result;
    }

    void run() {
        int n=5;
        std::vector<int> coins{1, 2, 3};

        for (int i=0; i<n+1; ++i) {
            cache.emplace_back(coins.size()+1);
            for (int j=0; j<coins.size()+1; ++j) {
                cache[i][j] = -1;
            }
        }

        std::cout << find(n, 0, coins);
    }
}
#endif //CPLUSPLUS_PRACTICE_COIN_CHANGE_H

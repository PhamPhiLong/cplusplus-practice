//
// Created by longpham on 19/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_MINIMUM_COIN_CHANGE_H
#define CPLUSPLUS_PRACTICE_MINIMUM_COIN_CHANGE_H

#include <unordered_map>
#include <vector>
#include <iostream>

namespace {
    using namespace std;

    std::unordered_map<int, int> cache;

    int minimum_coin_change(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        auto it = cache.find(amount);
        if (it != cache.end()) {
            return it->second;
        }

        int min = -1;
        for (auto coin : coins) {
            auto temp = minimum_coin_change(coins, amount - coin);
            if (temp == -1) continue;
            if (min == -1) {
                min = temp + 1;
            } else {
                min = std::min(min, temp + 1);
            }
        }

        cache[amount] = min;
        return min;
    }


    void run() {
        vector<int> coins{1, 3, 5};
        cout << minimum_coin_change(coins, 18);
    }
}
#endif //CPLUSPLUS_PRACTICE_MINIMUM_COIN_CHANGE_H

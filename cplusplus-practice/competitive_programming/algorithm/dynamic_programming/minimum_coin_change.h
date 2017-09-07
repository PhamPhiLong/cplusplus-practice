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

    int minimum_coin_change(const vector<int>& coins, const int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        auto it = cache.find(amount);
        if (it != cache.end()) {
            std::cout << "amount = " << amount << "\tminimum coin = " << it->second << std::endl;
            return it->second;
        }

        int min_coin_num = -1;
        for (const auto& coin : coins) {
            auto coin_num = minimum_coin_change(coins, amount - coin);
            if (coin_num == -1) continue;
            if (min_coin_num == -1 || (coin_num + 1 < min_coin_num)) min_coin_num = coin_num + 1;
        }

        cache[amount] = min_coin_num;
        return min_coin_num;
    }


    void run() {
        vector<int> coins{1, 3, 5};
        cout << minimum_coin_change(coins, 50);
    }
}
#endif //CPLUSPLUS_PRACTICE_MINIMUM_COIN_CHANGE_H

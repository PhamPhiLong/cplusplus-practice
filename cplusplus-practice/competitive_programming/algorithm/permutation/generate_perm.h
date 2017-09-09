//
// Created by Pham Phi Long on 9/8/2017.
//

#ifndef CPLUSPLUS_PRACTICE_GENERATE_PERM_H
#define CPLUSPLUS_PRACTICE_GENERATE_PERM_H

#include <vector>
#include <list>
#include <iostream>
#include <iterator>

namespace {
    template <typename T>
    void dfs(std::list<T> current, std::list<T> remain) {
        if (remain.empty()) {
            for (auto& element : current) {
                std::cout << element;
            }
            std::cout << std::endl;
            return;
        }

        for (auto it = std::begin(remain); it != std::end(remain); ++it) {
            auto remain_copy = remain;
            auto current_copy = current;
            auto remain_copy_start = std::begin(remain_copy);
            std::advance(remain_copy_start, std::distance(std::begin(remain), it));
            remain_copy.erase(remain_copy_start);
            current_copy.push_back(*it);
            dfs(std::move(current_copy), std::move(remain_copy));
        }
    }

    void run() {
        std::list<int> initial{1, 2, 3};
        dfs(std::list<int>{}, std::move(initial));
    }
}
#endif //CPLUSPLUS_PRACTICE_GENERATE_PERM_H

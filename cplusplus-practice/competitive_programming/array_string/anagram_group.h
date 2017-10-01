//
// Created by Pham Phi Long on 9/10/2017.
//

#ifndef CPLUSPLUS_PRACTICE_ANAGRAM_GROUP_H
#define CPLUSPLUS_PRACTICE_ANAGRAM_GROUP_H

// Given a set of random string, write a function that returns a set that groups all the anagrams together.
//
// For example, suppose that we have the following strings:
// "cat", "dog", "act", "door", "odor"
//
// Then we should return these sets: {“cat”, “act”}, {“dog”}, {“door”, “odor”}.


#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

namespace {
    std::vector<std::vector<std::string>> find_anagram_group(const std::vector<std::string>& strings) {
        std::vector<std::pair<std::string, std::string>> sorted_string_list{};

        for (auto& str : strings) {
            sorted_string_list.emplace_back(str, str);
            auto& sorted_str = sorted_string_list.rbegin()->first;
            std::sort(sorted_str.begin(), sorted_str.end());
        }

        std::unordered_map<std::string, std::vector<std::string>> anagram_hashmap{};
        std::vector<std::vector<std::string>> anagram_groups{};

        for (auto& anagram : sorted_string_list) {
            anagram_hashmap[anagram.first].emplace_back(anagram.second);
        }

        for (auto& anagram_group : anagram_hashmap) {
            anagram_groups.push_back(std::move(anagram_group.second));
        }

        return anagram_groups;
    }

    void run() {
        std::vector<std::string> strings{"cat", "dog", "act", "door", "odor"};
        auto anagram_groups = find_anagram_group(strings);

        for (auto& anagram_group : anagram_groups) {
            for (auto& anagram : anagram_group) {
                std::cout << anagram << " ";
            }
            std::cout << std::endl;
        }
    }
}
#endif //CPLUSPLUS_PRACTICE_ANAGRAM_GROUP_H

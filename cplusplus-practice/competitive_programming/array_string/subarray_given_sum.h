//
// Created by Pham Phi Long on 10/2/2017.
//

#include <utility>
#include <iterator>
#include <vector>
#include <iostream>
#include <unordered_map>

#ifndef CPLUSPLUS_PRACTICE_SUBARRAY_GIVEN_SUM_H
#define CPLUSPLUS_PRACTICE_SUBARRAY_GIVEN_SUM_H

#endif //CPLUSPLUS_PRACTICE_SUBARRAY_GIVEN_SUM_H

// question 1: Given an array of non-negative numbers, find continuous subarray with sum to S.
// question 2: Given an array of numbers (both negative and non-negative), find continuous subarray with sum to S.
// question 3: Given an array of numbers (both negative and non-negative), find subarray with sum to S.

namespace std {
    template<>
    struct hash<std::pair<int, int>> {
    public:
        template <typename T, typename U>
        std::size_t operator()(const std::pair<T, U> &x) const
        {
            return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
        }
    };
}

namespace {
    class ContinousNonNegativeSubarrayGivenSum {
    public:
        template <typename I, typename T>
        std::pair<I, I> operator()(I begin, I end, T given_sum) {
            auto tail = begin;
            T sum{*begin};

            while (begin != end && tail != end) {
                if (sum == given_sum) {
                    return std::make_pair(begin, std::next(tail));
                } else if (sum < given_sum) {
                    std::advance(tail, 1);
                    sum += *tail;
                } else {
                    sum -= *begin;
                    std::advance(begin, 1);
                }
            }

            return std::make_pair(end, end);
        }
    };

    class ContinousSubarrayGivenSum {
    public:
        template <typename T, typename I>
        std::pair<I, I> operator()(I begin, I end, T given_sum) {
            std::unordered_map<T, I>  hashmap;
            auto current = begin;
            T sum{0};

            while (current != end) {
                sum += *current;
                hashmap[sum] = current;
                if (sum != given_sum) {
                    auto it = hashmap.find(sum - given_sum);
                    if (it != hashmap.end()) {
                        return std::make_pair(std::next(it->second), std::next(current));
                    }
                } else {
                    return std::make_pair(begin, std::next(current));
                }
                std::advance(current, 1);
            }

            return std::make_pair(end, end);
        }
    };

    class SubarrayGivenSum {
    public:

        template<typename T, typename I>
        std::vector<I> operator()(I begin, I end, I current, T given_sum) {
            static std::unordered_map<std::pair<int, T>, std::vector<I>> hashmap;
            std::vector<I> elements{};
            if (current == end) return elements;
            auto current_index = std::distance(begin, current);
            auto cache = hashmap.find(std::make_pair(current_index, given_sum));
            if (cache != hashmap.end()) {
                return cache->second;
            }

            if (*current == given_sum) {
                elements.push_back(current);
                return elements;
            }

            auto with_current = operator()(begin, end, std::next(current), given_sum - *current);
            if (!with_current.empty()) {
                with_current.push_back(current);
                hashmap[std::make_pair(current_index, given_sum)] = with_current;
                return with_current;
            }

            auto without_current = operator()(begin, end, std::next(current), given_sum);
            if (!without_current.empty()) {
                hashmap[std::make_pair(current_index, given_sum)] = without_current;
                return without_current;
            }

            hashmap[std::make_pair(current_index, given_sum)] = elements;
            return elements;
        }
    };

    template <typename R>
    void print_continous_subarray(R range) {
        std::cout << "[";
        while (range.first != range.second) {
            std::cout << *range.first << ", ";
            std::advance(range.first, 1);
        }
        std::cout << "]" << std::endl;
    }

    void run() {
        // question 1
        std::vector<int> A1{1, 2, 3, 4, 5};
        ContinousNonNegativeSubarrayGivenSum question1;
        auto range1 = question1(std::begin(A1), std::end(A1), 9);
        print_continous_subarray(range1);

        // question 2
        std::vector<int> A2{1, -2, 3, -5, 5};
        ContinousSubarrayGivenSum question2;
        auto range2 = question2(std::begin(A2), std::end(A2), -4);
        print_continous_subarray(range2);

        // question 3
        std::vector<int> A3{1, -2, 3, -5, 5};
        SubarrayGivenSum question3;
        auto result3 = question3(std::begin(A3), std::end(A3), std::begin(A3), -6);
        std::cout << "[";
        for (auto elenment : result3) {
            std::cout << *elenment << ", ";
        }
        std::cout << "]" << std::endl;
    }
}
//
// Created by ASUS on 2/9/2017.
//

#ifndef CPLUSPLUS_PRACTICE_RETURN_K_TO_LAST_H
#define CPLUSPLUS_PRACTICE_RETURN_K_TO_LAST_H

#include <memory>
#include <iostream>

namespace {
    using namespace std;

    template <typename T>
    struct node {
        T value;
        shared_ptr<node<T>> next_node;
        node(T value, shared_ptr<node<T>> next_node) : value{value}, next_node{next_node} {}
    };

    template <typename T>
    struct linked_list {
        shared_ptr<node<T>> head;
    };

    template <typename T>
    shared_ptr<node<T>> return_k_to_last(const int k, const linked_list<T>& list) {
        int pos{0};
        auto kth_node = list.head;

        while (kth_node != nullptr) {
            if (pos == k) break;
            kth_node = kth_node->next_node;
            ++pos;
        }

        return kth_node;
    }

    void run() {
        linked_list<int> list{};
        list.head = make_shared<node<int>>(1,
                    make_shared<node<int>>(2,
                    make_shared<node<int>>(3,
                    make_shared<node<int>>(4,
                    make_shared<node<int>>(5, nullptr)))));

        auto kth_node = return_k_to_last(3, list);

        while (kth_node != nullptr) {
            cout << kth_node->value << " ";
            kth_node = kth_node->next_node;
        }
    }
}
#endif //CPLUSPLUS_PRACTICE_RETURN_K_TO_LAST_H

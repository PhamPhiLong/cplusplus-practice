//
// Created by ASUS on 5/21/2017.
//

#ifndef CPLUSPLUS_PRACTICE_LINKED_LISTS_INTERSECTION_H
#define CPLUSPLUS_PRACTICE_LINKED_LISTS_INTERSECTION_H

#include <memory>
#include <cmath>
#include <iostream>

namespace {
    using namespace std;

    template <typename T>
    struct Node {
        T value;
        shared_ptr<Node> next_node;

        Node(T value, shared_ptr<Node> next_node) : value{move(value)}, next_node{move(next_node)} {}
    };

    template <typename T>
    pair<int, shared_ptr<Node<T>>> get_len_tail(shared_ptr<Node<T>> head) {
        if (head == nullptr) return make_pair(0, head);

        int len{1};
        while (head->next_node != nullptr) {
            ++len;
            head = head->next_node;
        }

        return make_pair(len, head);
    }

    template <typename T>
    shared_ptr<Node<T>> find_interset(shared_ptr<Node<T>> list1, shared_ptr<Node<T>> list2) {
        auto len_tail1 = get_len_tail(list1);
        auto len_tail2 = get_len_tail(list2);

        if (len_tail1.second != len_tail2.second) return nullptr;

        auto delta = abs(len_tail1.first - len_tail2.first);

        shared_ptr<Node<T>> start1{}, start2{};
        if (len_tail1.first <= len_tail2.first) {
            auto start_node = list2;
            while (delta > 0) {
                start_node = start_node->next_node;
                --delta;
            }
            start1 = list1;
            start2 = start_node;
        } else {
            auto start_node = list1;
            while (delta > 0) {
                start_node = start_node->next_node;
                --delta;
            }
            start1 = start_node;
            start2 = list2;
        }

        while (start1 != start2) {
            start1 = start1->next_node;
            start2 = start2->next_node;
        }

        return start1;
    }

    void run() {
        auto intersect_list = make_shared<Node<int>>(7,
                make_shared<Node<int>>(2,
                        make_shared<Node<int>>(1, nullptr)));

        auto list1 = make_shared<Node<int>>(3,
                make_shared<Node<int>>(1,
                        make_shared<Node<int>>(5,
                                make_shared<Node<int>>(9, intersect_list))));

        auto list2 = make_shared<Node<int>>(4,
                                            make_shared<Node<int>>(6, intersect_list));

        auto intersect_node = find_interset(list1, list2);

        while (intersect_node != nullptr) {
            cout << intersect_node->value << " ";
            intersect_node = intersect_node->next_node;
        }
    }
}
#endif //CPLUSPLUS_PRACTICE_LINKED_LISTS_INTERSECTION_H

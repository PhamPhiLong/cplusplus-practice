//
// Created by Pham Phi Long on 1/30/2017.
//

#ifndef CPLUSPLUS_PRACTICE_REMOVE_DUPS_H
#define CPLUSPLUS_PRACTICE_REMOVE_DUPS_H

#include <iostream>
#include <memory>

//Remove Dups: Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buﬀer is not allowed?
namespace {
    using namespace std;

    template <typename T>
    struct node {
        T value;
        shared_ptr<node> next_node;

        node(T value, shared_ptr<node> next_node) : value{value} , next_node{next_node} {}
    };

    template <typename T>
    struct linked_list {
        shared_ptr<node<T>> head;
    };

    template <typename T>
    void remove_dups(linked_list<T>& list) {
        if (list.head == nullptr) return;
        auto curr_node = list.head;
        auto prev_node = curr_node;
        auto check_node = curr_node->next_node;

        while (curr_node != nullptr) {
            while (check_node != nullptr) {
                if (check_node->value == curr_node->value) {
                    prev_node->next_node = check_node->next_node;
                    check_node = prev_node->next_node;
                } else {
                    prev_node = check_node;
                    check_node = prev_node->next_node;
                }
            }

            curr_node = curr_node->next_node;
            if (curr_node == nullptr) return;
            prev_node = curr_node;
            check_node = curr_node->next_node;
        }
    }

    template <typename T>
    void print_list(const linked_list<T>& list) {
        auto node = list.head;
        while (node != nullptr) {
            cout << node->value << " ";
            node = node->next_node;
        }
        cout << endl;
    }

    void run() {
        linked_list<int> list{};
        list.head = make_shared<node<int>>(1,
                    make_shared<node<int>>(2,
                    make_shared<node<int>>(2,
                    make_shared<node<int>>(3,
                    make_shared<node<int>>(4,
                    make_shared<node<int>>(5,
                    make_shared<node<int>>(5,
                    make_shared<node<int>>(5, nullptr))))))));

        print_list(list);
        remove_dups(list);
        print_list(list);
    }
}
#endif //CPLUSPLUS_PRACTICE_REMOVE_DUPS_H

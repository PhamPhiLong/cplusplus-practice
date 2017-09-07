//
// Created by ASUS on 6/3/2017.
//

#ifndef CPLUSPLUS_PRACTICE_REVERSE_LINKED_LIST_H
#define CPLUSPLUS_PRACTICE_REVERSE_LINKED_LIST_H

#include <memory>
#include <iostream>

using namespace std;

namespace {
    template <typename T>
    struct Node {
        T value;
        shared_ptr<Node<T>> next_node;

        Node(T value, shared_ptr<Node<T>> next_node) : value{move(value)}, next_node{move(next_node)}{}
    };

    template <typename T>
    shared_ptr<Node<T>> reverse_linked_list(shared_ptr<Node<T>> root) {
        if (root == nullptr) return root;
        auto prev_node = root;
        auto curr_node = prev_node->next_node;

        while (curr_node != nullptr) {
            auto next_node = curr_node->next_node;
            curr_node->next_node = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }

        root->next_node = nullptr;
        return prev_node;
    }

    template <typename T>
    void print_linked_list(shared_ptr<Node<T>> root) {
        while (root != nullptr) {
            cout << root->value << " ";
            root = root->next_node;
        }
        cout << endl;
    }

    void run() {
        auto root = make_shared<Node<int>>(0,
                    make_shared<Node<int>>(1,
                    make_shared<Node<int>>(2,
                    make_shared<Node<int>>(3, nullptr))));

        print_linked_list(root);

        auto new_root = reverse_linked_list<int>(root);

        print_linked_list(new_root);
    }
}
#endif //CPLUSPLUS_PRACTICE_REVERSE_LINKED_LIST_H

//
// Created by longpham on 17/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_INVERT_BINARY_SEARCH_TREE_H
#define CPLUSPLUS_PRACTICE_INVERT_BINARY_SEARCH_TREE_H

//                   4
//         2                 7
//   1          3        6         9

#include <memory>
#include <iostream>

namespace {
    template <typename T>
    struct Node {
        std::shared_ptr<Node<T>> left;
        std::shared_ptr<Node<T>> right;
        T value;

        Node(std::shared_ptr<Node<T>> left, std::shared_ptr<Node<T>> right, T value)
        : left{left}, right{right}, value{value} {}
    };

    template <typename T>
    std::shared_ptr<Node<T>> create_binary_search_tree() {
        auto left_left = std::make_shared<Node<T>>(nullptr, nullptr, 1);
        auto left_right = std::make_shared<Node<T>>(nullptr, nullptr, 3);
        auto left = std::make_shared<Node<T>>(left_left, left_right, 2);
        auto right_left = std::make_shared<Node<T>>(nullptr, nullptr, 6);
        auto right_right = std::make_shared<Node<T>>(nullptr, nullptr, 9);
        auto right = std::make_shared<Node<T>>(right_left, right_right, 7);
        auto root = std::make_shared<Node<T>>(left, right, 4);

        return root;
    }

    template <typename T>
    void invert_binary_search_tree(std::shared_ptr<Node<T>> root) {
        if (root == nullptr) { return; }
        auto temp = root->right;
        root->right = root->left;
        root->left = temp;
        invert_binary_search_tree(root->left);
        invert_binary_search_tree(root->right);
    }

    template <typename T>
    void print_tree(const std::shared_ptr<Node<T>> node) {
        if (node == nullptr) { return; }
        std::cout << node->value << " -> ";
        print_tree(node->left);
        print_tree(node->right);
    }

    void run() {
        auto root = create_binary_search_tree<int>();
        print_tree(root);
        std::cout << std::endl;
        invert_binary_search_tree(root);
        print_tree(root);
    }
}
#endif //CPLUSPLUS_PRACTICE_INVERT_BINARY_SEARCH_TREE_H

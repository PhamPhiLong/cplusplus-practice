//
// Created by Pham Phi Long on 9/10/2017.
//

#ifndef CPLUSPLUS_PRACTICE_PRINT_TREE_BY_COLUMN_H
#define CPLUSPLUS_PRACTICE_PRINT_TREE_BY_COLUMN_H

#include <memory>
#include <iostream>

namespace {
    template <typename T>
    struct Node {
        T value{};
        std::shared_ptr<Node<T>> left{nullptr};
        std::shared_ptr<Node<T>> right{nullptr};

        Node(T value, std::shared_ptr<Node<T>> left, std::shared_ptr<Node<T>> right)
                : value{std::move(value)}, left{std::move(left)}, right{std::move(right)} {}

        Node(T value) : Node(value, nullptr, nullptr) {}
        Node() : Node(T{}, nullptr, nullptr) {}
    };

    void find_width_binary_tree(std::shared_ptr<Node<int>> node, int cur_width, int& left_width, int& right_width) {
        if (not node) return;
        left_width = std::min(cur_width, left_width);
        right_width = std::max(cur_width, right_width);

        if (node->left) {
            find_width_binary_tree(node->left, cur_width-1, left_width, right_width);
        }

        if (node->right) {
            find_width_binary_tree(node->right, cur_width+1, left_width, right_width);
        }
    }

    void print_column(std::shared_ptr<Node<int>> node, int cur_col, const int desired_col) {
        if (not node) return;
        if (cur_col == desired_col) std::cout << node->value;
        print_column(node->left, cur_col-1, desired_col);
        print_column(node->right, cur_col+1, desired_col);
    }

    void run() {
        /* Create following Binary Tree
             0
           /    \
         1        2
        / \      / \
       3   4    5   6

       */
        std::shared_ptr<Node<int>> root = std::make_shared<Node<int>>(0,
                                                                      std::make_shared<Node<int>>(1, std::make_shared<Node<int>>(3), std::make_shared<Node<int>>(4)),
                                                                      std::make_shared<Node<int>>(2, std::make_shared<Node<int>>(5), std::make_shared<Node<int>>(6)));

        int left_width{0}, right_width{0};
        find_width_binary_tree(root, 0, left_width, right_width);

        for (; left_width <= right_width; ++left_width) {
            print_column(root, 0, left_width);
            std::cout << std::endl;
        }
    }
}

#endif //CPLUSPLUS_PRACTICE_PRINT_TREE_BY_COLUMN_H

//
// Created by Pham Phi Long on 9/10/2017.
//

#ifndef CPLUSPLUS_PRACTICE_PRINT_ALL_PATHS_H
#define CPLUSPLUS_PRACTICE_PRINT_ALL_PATHS_H

// For the above binary tree, we should print the following paths:
//
//            F
//           / \
//          B   G
//         / \   \
//        A  D    I
//          / \   /
//         C   E H
// F→B->A
// F→B->D->C
// F→B->D->E
// F→G->I->H

#include <memory>
#include <vector>
#include <iostream>

namespace {
    template <typename T>
    struct Node {
        T value;
        std::shared_ptr<Node<T>> left;
        std::shared_ptr<Node<T>> right;

        Node(T value, std::shared_ptr<Node<T>> left, std::shared_ptr<Node<T>> right)
        : value{std::move(value)}, left{std::move(left)}, right{std::move(right)} {}

        Node(T value) : Node(value, nullptr, nullptr) {}
        Node() : Node({}, nullptr, nullptr) {}
    };

    template <typename T>
    void inorder_dft(std::shared_ptr<Node<T>> node, std::vector<std::shared_ptr<Node<T>>> parent_list = {}) {
        if (not node) return;
        parent_list.push_back(node);
        if (not node->left and not node->right) {
            // this is leaf node, print path
            for (auto parent : parent_list) {
                std::cout << parent->value << " ";
            }
            std::cout << std::endl;
            return;
        }
        inorder_dft(node->left, parent_list);
        inorder_dft(node->right, std::move(parent_list));
    }

    void run() {
        std::shared_ptr<Node<std::string>> root = std::make_shared<Node<std::string>>("F",
            std::make_shared<Node<std::string>>("B",
                std::make_shared<Node<std::string>>("A"),
                std::make_shared<Node<std::string>>("D",
                    std::make_shared<Node<std::string>>("C"),
                    std::make_shared<Node<std::string>>("E"))),
            std::make_shared<Node<std::string>>("G",
                nullptr,
                std::make_shared<Node<std::string>>("I",
                    std::make_shared<Node<std::string>>("H"),
                    nullptr)
                )
        );

        inorder_dft(root);
    }
}

#endif //CPLUSPLUS_PRACTICE_PRINT_ALL_PATHS_H

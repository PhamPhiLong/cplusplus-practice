//
// Created by longpham on 16/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_CONVERT_BINARY_TREE_DOUBLE_LINKEDLIST_H
#define CPLUSPLUS_PRACTICE_CONVERT_BINARY_TREE_DOUBLE_LINKEDLIST_H

// Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL).
// The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
// The order of nodes in DLL must be same as Inorder of the given Binary Tree.
// The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

#include <memory>
#include <iostream>

namespace {
    template <typename T>
    struct Node {
        std::shared_ptr<Node<T>> left;
        std::shared_ptr<Node<T>> right;
        T value;

        Node(std::shared_ptr<Node<T>> left, std::shared_ptr<Node<T>> right, T value) : left{left}, right{right}, value{value} {}
    };

    template <typename T>
    std::shared_ptr<Node<T>> binary_tree_to_double_linkedlist(std::shared_ptr<Node<T>> root) {
        std::shared_ptr<Node<T>> left_list;

        if (root == nullptr) { return nullptr; }

        if (root->left != nullptr) {
            left_list = binary_tree_to_double_linkedlist(root->left);

            if (left_list->right == nullptr) {
                left_list->right = root;
            } else {
                auto ended_node = left_list->right;
                while (ended_node->right != nullptr) { ended_node = ended_node->right; }
                ended_node->right = root;
            }

        } else {
            left_list = root;
        }

        if (root->right != nullptr) {
            root->right = binary_tree_to_double_linkedlist(root->right);
        }

        return left_list;
    }

    template <typename T>
    std::shared_ptr<Node<T>> contruct_binary_tree() {
        auto left_left = std::make_shared<Node<T>>(nullptr, nullptr, 25);
        auto left_right = std::make_shared<Node<T>>(nullptr, nullptr, 30);
        auto left = std::make_shared<Node<T>>(nullptr, nullptr, 12);
        auto root = std::make_shared<Node<T>>(nullptr, nullptr, 10);
        auto right = std::make_shared<Node<T>>(nullptr, nullptr, 15);
        auto right_left = std::make_shared<Node<T>>(nullptr, nullptr, 36);

        left->left = left_left;
        left->right = left_right;
        right->left = right_left;
        root->left = left;
        root->right = right;

        return root;
    }

    void run() {
        auto root = contruct_binary_tree<int>();
        auto start = binary_tree_to_double_linkedlist<int>(root);
        while (start != nullptr) {
            std::cout << start->value << " -> ";
            start = start->right;
        }
    }
}

#endif //CPLUSPLUS_PRACTICE_CONVERT_BINARY_TREE_DOUBLE_LINKEDLIST_H

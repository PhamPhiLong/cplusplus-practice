//
// Created by Pham on 9/10/2017.
//

#ifndef CPLUSPLUS_PRACTICE_SUM_OF_EACH_BINARY_TREE_LEVEL_H
#define CPLUSPLUS_PRACTICE_SUM_OF_EACH_BINARY_TREE_LEVEL_H

#include <memory>
#include <vector>
#include <iostream>
#include <numeric>

namespace {
    template <typename T>
    struct Node {
        T value{};
        std::shared_ptr<Node<T>> left{nullptr};
        std::shared_ptr<Node<T>> right{nullptr};

        Node(T value, std::shared_ptr<Node<T>> left, std::shared_ptr<Node<T>> right)
                : value{value}, left{left}, right{right} {}

        Node(T value) : Node(value, nullptr, nullptr) {}
        Node() : Node(T{}, nullptr, nullptr) {}
    };

    void run() {
        std::shared_ptr<Node<int>> root = std::make_shared<Node<int>>(0,
                                                           std::make_shared<Node<int>>(1, std::make_shared<Node<int>>(3), std::make_shared<Node<int>>(4)),
                                                           std::make_shared<Node<int>>(2, std::make_shared<Node<int>>(5), std::make_shared<Node<int>>(6)));

        std::vector<std::shared_ptr<Node<int>>> bfs_queue{root};

        while (not bfs_queue.empty()) {
            std::vector<std::shared_ptr<Node<int>>> next_layer_nodes{};
            std::cout << std::accumulate(bfs_queue.begin(), bfs_queue.end(), 0, [](int sum, std::shared_ptr<Node<int>> node) {
                return sum + node->value;
            }) << std::endl;
            for (auto node : bfs_queue) {
                if (node->left != nullptr) next_layer_nodes.push_back(node->left);
                if (node->right != nullptr) next_layer_nodes.push_back(node->right);
            }

            bfs_queue = std::move(next_layer_nodes);
        }
    }
}
#endif //CPLUSPLUS_PRACTICE_SUM_OF_EACH_BINARY_TREE_LEVEL_H

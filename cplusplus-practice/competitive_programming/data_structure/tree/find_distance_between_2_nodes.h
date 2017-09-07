//
// Created by longpham on 03/03/2017.
//

#include <memory>
#include <vector>
#include <iostream>

#ifndef CPLUSPLUS_PRACTICE_FIND_DISTANCE_BETWEEN_2_nodeS_H
#define CPLUSPLUS_PRACTICE_FIND_DISTANCE_BETWEEN_2_nodeS_H

#endif //CPLUSPLUS_PRACTICE_FIND_DISTANCE_BETWEEN_2_nodeS_H

namespace {
    using namespace std;

    template <typename T>
    struct node {
        T val;
        shared_ptr<node<T>> left{nullptr};
        shared_ptr<node<T>> right{nullptr};

        node(shared_ptr<node<T>> left, shared_ptr<node<T>>right, T val) : val{val}, left{left}, right{right} {}
    };

    template <typename T>
    int find_depth_of_node(const shared_ptr<node<T>> current_node, const shared_ptr<node<T>> target_node) {
        if (current_node == target_node) return 0;

        if (current_node->left != nullptr) {
            auto left_depth = find_depth_of_node(current_node->left, target_node);
            if (left_depth >= 0) return left_depth + 1;
        }

        if (current_node->right != nullptr) {
            auto right_depth = find_depth_of_node(current_node->right, target_node);
            if (right_depth >= 0) return right_depth + 1;
        }

        return -1;
    }

    template <typename T>
    std::vector<shared_ptr<node<T>>> get_reverse_path_from_node_to_node(const shared_ptr<node<T>> current_node, const shared_ptr<node<T>> target_node) {
        if (current_node == target_node) {
            return std::vector<shared_ptr<node<T>>>{current_node};
        }

        if (current_node->left != nullptr) {
            auto reverse_left_path = get_reverse_path_from_node_to_node(current_node->left, target_node);
            if (!reverse_left_path.empty()) {
                reverse_left_path.push_back(current_node);
                return reverse_left_path;
            }
        }

        if (current_node->right != nullptr) {
            auto reverse_right_path = get_reverse_path_from_node_to_node(current_node->right, target_node);
            if (!reverse_right_path.empty()) {
                reverse_right_path.push_back(current_node);
                return reverse_right_path;
            }
        }

        return std::vector<shared_ptr<node<T>>>{};
    }

    template <typename T>
    shared_ptr<node<T>> find_lowest_common_node(shared_ptr<node<T>> root, shared_ptr<node<T>> node1, shared_ptr<node<T>> node2) {
        const auto reverse_path_to_node1 = get_reverse_path_from_node_to_node(root, node1);
        const auto reverse_path_to_node2 = get_reverse_path_from_node_to_node(root, node2);

        auto it1 = reverse_path_to_node1.rbegin();
        auto it2 = reverse_path_to_node2.rbegin();
        for (; it1 != reverse_path_to_node1.rend() && it2 != reverse_path_to_node2.rend(); ++it1, ++it2) {
            if (*it1 != *it2 && it1 != reverse_path_to_node1.rbegin()) return *(--it1);
        }

        if (it1 != reverse_path_to_node1.rend()) return *(--it2);
        else return *(--it1);
    }
    
    template <typename T>
    int find_distance(shared_ptr<node<T>> root, shared_ptr<node<T>> node1, shared_ptr<node<T>> node2) {
        auto node1_depth = find_depth_of_node(root, node1);
        auto node2_depth = find_depth_of_node(root, node2);
        auto lowest_common_node_depth = find_depth_of_node(root, find_lowest_common_node(root, node1, node2));
        return node1_depth + node2_depth - 2*lowest_common_node_depth;
    }

    void run() {
        auto right_right = std::make_shared<node<int>>(nullptr, nullptr, 7);
        auto right_left_right = std::make_shared<node<int>>(nullptr, nullptr, 8);
        auto right_left = std::make_shared<node<int>>(nullptr, right_left_right, 6);
        auto right = std::make_shared<node<int>>(right_left, right_right, 3);
        auto left_left = std::make_shared<node<int>>(nullptr, nullptr, 4);
        auto left_right = std::make_shared<node<int>>(nullptr, nullptr, 5);
        auto left = std::make_shared<node<int>>(left_left, left_right, 2);
        auto root = std::make_shared<node<int>>(left, right, 10);

        cout << "distance between node " << right_left_right->val << " and node " << left_right->val << " is " << find_distance(root, right_left_right, left_right) << endl;
    }
}
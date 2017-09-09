//
// Created by Pham Phi Long on 9/8/2017.
//

#ifndef CPLUSPLUS_PRACTICE_TRAVEL_UNDIRECTED_GRAPH_H
#define CPLUSPLUS_PRACTICE_TRAVEL_UNDIRECTED_GRAPH_H

#include <vector>
#include <iostream>

namespace {
    class Graph {
        std::vector<std::vector<int>> adjacency_list{
                {1},
                {0, 2},
                {1},
                {4},
                {3}
        };

        void dft(int curr_node, std::vector<int>& component, std::vector<bool>& is_vertice_traveled) {
            for (auto adjacent_node : adjacency_list[curr_node]) {
                if (is_vertice_traveled[adjacent_node]) continue;
                is_vertice_traveled[adjacent_node] = true;
                component.emplace_back(adjacent_node);
                dft(adjacent_node, component, is_vertice_traveled);
            }
        }
    public:
        std::vector<std::vector<int>> get_connected_components() {
            std::vector<std::vector<int>> components{};
            std::vector<bool> is_vertice_traveled(adjacency_list.size(), false);
            for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
                auto curr_node = std::distance(adjacency_list.begin(), it);
                if (is_vertice_traveled[curr_node]) continue;
                is_vertice_traveled[curr_node] = true;
                components.push_back({curr_node});
                dft(curr_node, *components.rbegin(), is_vertice_traveled);
            }
            return components;
        }
    };

    void run() {
        Graph graph{};
        auto components = graph.get_connected_components();
        for (auto& component : components) {
            for (auto& vertice : component) {
                std::cout << vertice << " ";
            }
            std::cout << std::endl;
        }
    }
}
#endif //CPLUSPLUS_PRACTICE_TRAVEL_UNDIRECTED_GRAPH_H

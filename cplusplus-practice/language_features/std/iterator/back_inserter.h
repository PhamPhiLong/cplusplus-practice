//
// Created by longpham on 19/02/2017.
//

#ifndef CPLUSPLUS_PRACTICE_BACK_INSERTER_H
#define CPLUSPLUS_PRACTICE_BACK_INSERTER_H

#include <vector>
#include <iostream>

namespace {
    template <typename T>
    void print_container(const T& container) {
        std::cout << "size = " << container.size() << std::endl;
        for (auto& ele : container) {
            std::cout << "\t" << ele << std::endl;
        }
    }

    void run() {
        std::vector<int> vec{0, 1, 2, 3, 4};
        print_container(vec);
        auto it = std::back_inserter(vec);
        print_container(vec);
        it++ = 5;
        print_container(vec);
    }
}
#endif //CPLUSPLUS_PRACTICE_BACK_INSERTER_H

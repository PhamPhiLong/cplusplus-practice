//
// Created by Pham Phi Long on 1/29/2017.
//

#ifndef CPLUSPLUS_PRACTICE_IS_UNIQUE_H
#define CPLUSPLUS_PRACTICE_IS_UNIQUE_H

#include <string>
#include <algorithm>
#include <iostream>

//Implement an algorithm to determine if a string has all unique characters. What if you
//cannot use additional data structures?

namespace {
    using namespace std;

    bool is_unique(string str) {
        sort(begin(str), end(str));
        for (auto it = str.begin(); it != str.end();) {
            auto next_it = next(it);
            if (next_it == str.end()) break;
            if (*it == *next_it) return false;
            it = next_it;
        }

        return true;
    }

    void run() {
        string str{"wahaa"};
        cout << str << " : " << (is_unique(str) ? "is unique" : "is not unique") << endl;

        str = "edcba";
        cout << str << " : " << (is_unique(str) ? "is unique" : "is not unique") << endl;
    }
}
#endif //CPLUSPLUS_PRACTICE_IS_UNIQUE_H

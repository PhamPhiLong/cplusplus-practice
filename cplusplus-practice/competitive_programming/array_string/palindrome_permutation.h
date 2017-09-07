//
// Created by Pham Phi Long on 1/30/2017.
//

#ifndef CPLUSPLUS_PRACTICE_PALINDROME_PERMUTATION_H
#define CPLUSPLUS_PRACTICE_PALINDROME_PERMUTATION_H

#include <string>
#include <unordered_map>
#include <iostream>

namespace {
    using namespace std;

    inline bool is_even(int num) {
        return (num % 2) == 0;
    }

    bool palindrome_permutation(const string& str) {
        unordered_map<char, int> appear_num{};
        for (auto cha : str) {
            appear_num[cha]++;
        }

        if (is_even(str.length())) {
            for (auto cha : appear_num) {
                if (!is_even(cha.second)) return false;
            }
        } else {
            bool odd{false};
            for (auto cha : appear_num) {
                if (!is_even(cha.second)) {
                    if (!odd) {
                        odd = true;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    void run() {
        string str{"abccre"};
        cout << str << " : " << (palindrome_permutation(str) ? "is palindrome permutation" : "is not palindrome permutation") << endl;

        str = "acb bca";
        cout << str << " : " << (palindrome_permutation(str) ? "is palindrome permutation" : "is not palindrome permutation") << endl;

        str = "acbbcadd"
                "";
        cout << str << " : " << (palindrome_permutation(str) ? "is palindrome permutation" : "is not palindrome permutation") << endl;
    }
}
#endif //CPLUSPLUS_PRACTICE_PALINDROME_PERMUTATION_H

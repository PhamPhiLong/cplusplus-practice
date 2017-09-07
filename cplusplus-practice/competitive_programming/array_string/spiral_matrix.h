//
// Created by ASUS on 5/20/2017.
//

#ifndef CPLUSPLUS_PRACTICE_SPIRAL_MATRIX_H
#define CPLUSPLUS_PRACTICE_SPIRAL_MATRIX_H

#include <iostream>
#include <vector>

namespace {
    using namespace std;
    template<class T>
    using matrix = vector<vector<T>>;

    template <class T>
    void matrix_spiral_traverse(const matrix<T>& ma, const int starti, const int startj, const int M, const int N) {
        if (N < 1 || M < 1) return;
        // go right
        for (int j{startj}; j < (startj+M); ++j) {
            cout << ma[starti][j] << " ";
        }

        // go down
        for (int i{1}; i < N; ++i) {
            cout << ma[starti+i][startj+M-1] << " ";
        }

        // go left
        for (int j{startj+M-2}; j >= startj ; --j) {
            cout << ma[starti+N-1][j] << " ";
        }

        // go up
        for (int i{starti+N-2}; i > starti ; --i) {
            cout << ma[i][startj] << " ";
        }

        matrix_spiral_traverse(ma, starti+1, startj+1, M-2, N-2);
    }

    void run() {
        const int N{5};
        matrix<int> ma{};
        for (int i=0; i<N; ++i) {
            ma.push_back(vector<int>{});
            for (int j=0; j<N; ++j) {
                ma[i].push_back(i*N+j+1);
            }
        }

        for (int i=0; i<ma.size(); ++i) {
            for (int j=0; j<ma.size(); ++j) {
                cout << ma[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl << endl;

        matrix_spiral_traverse(ma, 0, 0, N, N);
    }
}

#endif //CPLUSPLUS_PRACTICE_SPIRAL_MATRIX_H

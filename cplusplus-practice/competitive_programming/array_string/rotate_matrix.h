//
// Created by Pham Phi Long on 5/20/2017.
//

#ifndef CPLUSPLUS_PRACTICE_ROTATE_MATRIX_H
#define CPLUSPLUS_PRACTICE_ROTATE_MATRIX_H

#include <vector>
#include <iostream>

namespace {
    using namespace std;
    template<class T>
    using matrix = vector<vector<T>>;

    template <class T>
    bool rotate_matrix(const matrix<T>& ma) {
        auto ma_2 = ma;

        for (int i=0; i<ma.size(); ++i) {
            for (int j=0; j<ma.size(); ++j) {
                cout << ma[i][j] << " ";
            }
            cout << endl;
        }

        for (int i=0; i<ma.size(); ++i) {
            for (int j=0; j<ma.size(); ++j) {
                ma_2[j][ma.size()-1-i] = ma[i][j];
            }
        }

        cout << endl << endl;

        for (int i=0; i<ma.size(); ++i) {
            for (int j=0; j<ma.size(); ++j) {
                cout << ma_2[i][j] << " ";
            }
            cout << endl;
        }
    }


    template <class T>
    bool rotate_matrix_inplace(const matrix<T>& ma) {

        for (int i=0; i<ma.size(); ++i) {
            for (int j=0; j<ma.size(); ++j) {
                cout << ma[i][j] << " ";
            }
            cout << endl;
        }

        for (int i=0; i<ma.size(); ++i) {
            for (int j=0; j<ma.size(); ++j) {
                ma_2[j][ma.size()-1-i] = ma[i][j];
            }
        }

        cout << endl << endl;

        for (int i=0; i<ma.size(); ++i) {
            for (int j=0; j<ma.size(); ++j) {
                cout << ma_2[i][j] << " ";
            }
            cout << endl;
        }
    }

    void run() {
        const int N{3};
        matrix<int> ma{};
        for (int i=0; i<N; ++i) {
            ma.push_back(vector<int>{});
            for (int j=0; j<N; ++j) {
                ma[i].push_back(i*N+j+1);
            }
        }
        rotate_matrix(ma);
    }
}

#endif //CPLUSPLUS_PRACTICE_ROTATE_MATRIX_H

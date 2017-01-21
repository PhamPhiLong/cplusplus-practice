//
// Created by Pham Phi Long on 1/21/2017.
//

#ifndef CPLUSPLUS_PRACTICE_MISSING_INTEGER_H
#define CPLUSPLUS_PRACTICE_MISSING_INTEGER_H

#include <vector>
#include <iostream>

// https://codility.com/programmers/lessons/4-counting_elements/missing_integer/start/

//given a non-empty zero-indexed array A of N integers, returns the minimal positive integer (greater than 0) that does not occur in A.
//
//For example, given:
//
//A[0] = 1
//A[1] = 3
//A[2] = 6
//A[3] = 4
//A[4] = 1
//A[5] = 2
//the function should return 5.
//
//Assume that:
//
//N is an integer within the range [1..100,000];
//each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
//Complexity:
//
//        expected worst-case time complexity is O(N);
//expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
//Elements of input arrays can be modified.

namespace {
    using namespace std;

    int missing_integer(vector<int> &A) {
        // result must be in range of [1 size of array]
        vector<bool> appear(A.size());

        for (unsigned int i=0; i<A.size(); ++i) {
            if ((A[i] > 0) && (A[i] <= A.size())) {
                appear[A[i] - 1] = true;
            }
        }

        for (unsigned int i=0; i<appear.size(); ++i) {
            if (!appear[i]) return i+1;
        }

        return A.size() + 1;
    }

    void run () {
        vector<int> A{1, 6, 4, 3};
        cout <<  "Array: [";
        for (auto num : A) {
            cout << num << ", ";
        }
        cout << "]" << endl;
        cout << "smallest missing integer: " << missing_integer(A);
    }
}
#endif //CPLUSPLUS_PRACTICE_MISSING_INTEGER_H

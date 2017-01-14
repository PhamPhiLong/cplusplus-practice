//
// Created by longpham on 15/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_D_POINTER_H
#define CPLUSPLUS_PRACTICE_D_POINTER_H

#include <memory>

namespace {
    struct DPointerImpl;

    class DPointer {
    public:
        DPointer();
        void do_something();

    private:
        std::shared_ptr<DPointerImpl> impl;
    };

    void run() {
        DPointer dPointer;
        dPointer.do_something();
    }
}
#endif //CPLUSPLUS_PRACTICE_D_POINTER_H

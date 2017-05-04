//
// Created by longpham on 14/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H
#define CPLUSPLUS_PRACTICE_CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H

#include <iostream>
#include <memory>

namespace {
    template<typename T>
    struct Base {
        void foo() const {
            static_cast<const T*>(this)->foo();
        }
    };

    struct Derived1 : public Base<Derived1> {
        void foo() const {
            std::cout << "derrived1 class" << std::endl;
        }
    };

    struct Derived2 : public Base<Derived2> {
        void foo() const {
            std::cout << "derrived2 class" << std::endl;
        }
    };

    template <typename T>
    void do_something(const Base<T>& object) {
        object.foo();
    }

    void run() {
        Derived1 derived1;
        Derived2 derived2;
        do_something(derived1);
        do_something(derived2);
    }
}


#endif //CPLUSPLUS_PRACTICE_CURIOUSLY_RECURRING_TEMPLATE_PATTERN_H

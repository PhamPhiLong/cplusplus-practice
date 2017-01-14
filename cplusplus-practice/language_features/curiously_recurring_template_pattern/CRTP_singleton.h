//
// Created by longpham on 14/01/2017.
//

#ifndef CPLUSPLUS_PRACTICE_SINGLETON_H
#define CPLUSPLUS_PRACTICE_SINGLETON_H

#include <iostream>

namespace {
    template<typename T>
    class Singleton {
    public:
        static T &get_instance() {
            return instance;
        }

    private:
        static T instance;
    };

    template <typename T>
    T Singleton<T>::instance;

    struct Foo : public Singleton<Foo> {
        void bar() {
            std::cout << "hello world" << std::endl;
        }
    };

    void run() {
        auto instance = Foo::get_instance();
        instance.bar();
    }
}
#endif //CPLUSPLUS_PRACTICE_SINGLETON_H

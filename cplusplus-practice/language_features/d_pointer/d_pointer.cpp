//
// Created by longpham on 15/01/2017.
//


#include <iostream>
#include "d_pointer.h"
#include "d_pointer/d_pointer_impl.h"

void DPointer::do_something() {
    std::cout << impl->attr << std::endl;
}

DPointer::DPointer() : impl(new DPointerImpl{16061991}) {}
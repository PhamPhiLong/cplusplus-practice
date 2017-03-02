//
// Created by longpham on 19/02/2017.
//

#ifndef CPLUSPLUS_PRACTICE_MULTI_INDEX_CONTAINER_H
#define CPLUSPLUS_PRACTICE_MULTI_INDEX_CONTAINER_H

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>

namespace {
    namespace tags
    {
        struct x_asc {};
        struct y_desc{};
        struct unordered {};
    }

    struct A {
        A(int _x, int _y) :
                x(_x), y(_y) {}

        int x;
        int y;
    };

    using sorted_ints = boost::multi_index_container<
    A,                          // the stored object
    boost::multi_index::indexed_by<
        boost::multi_index::ordered_unique<           // first view
            boost::multi_index::tag<tags::x_asc>,       // tag used to access the view
            boost::multi_index::member<A, int, &A::x>,  // ordered on x...
            std::less<int>          // ... by ascending order
        >,

        boost::multi_index::ordered_unique<           // second view
            boost::multi_index::tag<tags::y_desc>,       // tag used to access the view
            boost::multi_index::member<A, int, &A::y>,  // ordered on y...
            std::less<int>          // ... by ascending order
        >
    >
    >;
}
#endif //CPLUSPLUS_PRACTICE_MULTI_INDEX_CONTAINER_H

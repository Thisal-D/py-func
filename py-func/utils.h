#ifndef PY_FUNC_UTILS_H
#define PY_FUNC_UTILS_H

#include <stddef.h>


namespace utils{
    template<typename T>
    void __fix_index_range(T& start_index, T& end_index, size_t size_);
}

#endif
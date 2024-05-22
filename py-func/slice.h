#ifndef PY_FUNC_SLICE_H
#define PY_FUNC_SLICE_H

#include <vector>
#include <string>
#include <typeinfo>


namespace pyfunc {

    template<typename T>
    std::vector<T> slice(std::vector<T> source, long long start_index, long long end_index, long long step);

    template<typename T>
    T* slice(T* source, size_t size, long long start_index, long long end_index, long long step);

    template<typename T>
    T* slice(const T* source, size_t size, long long start_index, long long end_index, long long step);

    std::string slice(std::string source, long long start_index, long long end_index, long long step);
}

#endif
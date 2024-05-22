#ifndef PY_FUNC_REPLACE_H
#define PY_FUNC_REPLACE_H

#include <vector>
#include <string>
#include <array>
#include <typeinfo>


namespace pyfunc {
    template <typename T, typename T2>
    std::string replace(std::string source, T search, T2 replacement);

    template <typename T>
    std::vector<T> replace(std::vector<T> source, T search, T replacement);

    template <typename T>
    T* replace(T* source, size_t size, T search, T replacement);

    template <typename T>
    T* replace(const T* source, size_t size, T search, T replacement);

    template <typename T, size_t size>
    std::array<T, size> replace(std::array<T, size> source, T search, T replacement);
}

#endif
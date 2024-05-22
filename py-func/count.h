#ifndef PY_FUNC_COUNT_H
#define PY_FUNC_COUNT_H

#include <vector>
#include <string>
#include <array>


namespace pyfunc {
    template <typename T2>
    T2 count(std::string source, std::string search);

    template <typename T2>
    T2 count(std::string source, char search_);

    template <typename T, typename T2>
    T2 count(std::vector<T> source, T search);

    template <typename T, typename T2>
    T2 count(T* source, size_t size, T search);

    template <typename T, typename T2>
    T2 count(const T* source, size_t size, T search);

    template <typename T, size_t size, typename T2>
    T2 count(std::array<T, size> source, T search);
}

#endif
#ifndef PY_FUNC_JOIN_H
#define PY_FUNC_JOIN_H

#include <vector>
#include <string>
#include <array>


namespace pyfunc {
    std::string join(std::string source, std::string join_by);
    std::string join(std::string source, char join_by);

    template<typename T>
    std::string join(std::vector<T> source, std::string join_by);

    template<typename T>
    std::string join(std::vector<T> source, char join_by);

    template<typename T, size_t size>
    std::string join(std::array<T, size> source, std::string join_by);

    template<typename T, size_t size>
    std::string join(std::array<T, size> source, char join_by);

    template<typename T>
    std::string join(T* source, size_t size, std::string join_by);

    template<typename T>
    std::string join(T* source, size_t size, char join_by);

    template<typename T>
    std::string join(const T* source, size_t size, std::string join_by);

    template<typename T>
    std::string join(const T* source, size_t size, char join_by);
}

#endif
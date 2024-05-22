#include "count.h"


template <typename T2>
T2 pyfunc::count(std::string source, std::string search) {
    size_t end_index;
    size_t search_len = search.length();
    T2 count = 0;
    while ((end_index = source.find(search)) != -1) {
        count++;
        source = source.substr(end_index + search_len);
    }
    return count;
}

template <typename T2>
T2 pyfunc::count(std::string source, char search_) {
    std::string search = (std::string)"" + search_;
    return pyfunc::count<T2>(source, search);
}

template <typename T, typename T2>
T2 pyfunc::count(std::vector<T> source, T search) {
    T2 count = 0;
    for (T src : source) {
        if (src == search) {
            count++;
        }
    }
    return count;
}

template <typename T, typename T2>
T2 pyfunc::count(T* source, size_t size, T search) {
    T2 count = 0;
    for (size_t index = 0; index < size; index++) {
        if (*source++ == search) {
            count++;
        }
    }
    return count;
}

template <typename T, typename T2>
T2 pyfunc::count(const T* source, size_t size, T search) {
    T2 count = 0;
    for (size_t index = 0; index < size; index++) {
        if (*source++ == search) {
            count++;
        }
    }
    return count;
}

template <typename T, size_t size, typename T2>
T2 pyfunc::count(std::array<T, size> source, T search) {
    T2 count = 0;
    for (T src : source) {
        if (src == search) {
            count++;
        }
    }
    return count;
}
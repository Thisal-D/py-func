#include "utils.h"
#include "range.h"
#include "slice.h"


std::string pyfunc::slice(std::string source, long long start_index, long long end_index, long long step) {
    std::string str_range = "";
    utils::__fix_index_range<long long>(start_index, end_index, source.length());
    std::vector<long long> index_range = range<long long>(start_index, end_index, step);
    for (size_t index : index_range) {
        str_range += source[index];
    }
    return str_range;
}

template<typename T>
T* pyfunc::slice(T* source, size_t size, long long start_index, long long end_index, long long step) {
    utils::__fix_index_range<long long>(start_index, end_index, size);
    std::vector<long long> index_range = range<long long>(start_index, end_index, step);
    T* T_array;
    if (typeid(T) == typeid(char)) {
        T_array = new T[index_range.size() + 1];
        T_array[index_range.size()] = '\0';
    }
    else {
        T_array = new T[index_range.size()];
    }
    for (size_t index = 0; index < index_range.size(); index++) {
        T_array[index] = source[index_range[index]];
    }
    return T_array;
}

template<typename T>
T* pyfunc::slice(const T* source, size_t size, long long start_index, long long end_index, long long step) {
    utils::__fix_index_range<long long>(start_index, end_index, size);
    std::vector<long long> index_range = range<long long>(start_index, end_index, step);
    T* T_array;
    if (typeid(T) == typeid(char)) {
        T_array = new T[index_range.size() + 1];
        T_array[index_range.size()] = '\0';
    }
    else {
        T_array = new T[index_range.size()];
    }
    for (size_t index = 0; index < index_range.size(); index++) {
        T_array[index] = source[index_range[index]];
    }
    return T_array;
}


/*
template<typename T, size_t size ,size_t size_2>
std::array<T, size_2> pyfunc::range(std::array<T, size> source, long long start_index, long long end_index, long long step) {
    utils::__fix_index_range(start_index, end_index, size);
    std::vector<long long> index_range = range<long long>(start_index, end_index, step);
    std::array<T, size_2 > T_t_array;
    for (size_t index = 0; index < index_range.size(); index++) {
        T_t_array[index] = source[index_range[index]];
    }
    return T_t_array;
}
*/

template<typename T>
std::vector<T> pyfunc::slice(std::vector<T> source, long long start_index, long long end_index, long long step) {
    std::vector<T> T_vector{};
    utils::__fix_index_range<long long>(start_index, end_index, source.size());
    std::vector<long long> index_range = range<long long>(start_index, end_index, step);
    for (size_t index : index_range) {
        T_vector.push_back(source[index]);
    }
    return T_vector;
}
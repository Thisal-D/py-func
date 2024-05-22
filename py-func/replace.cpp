#include "replace.h"


template <typename T, typename T2>
std::string pyfunc::replace(std::string source, T search, T2 replacement) {
    std::string search_ = (std::string)"" + search;
    std::string replacement_ = (std::string)"" + replacement;
    std::string replaced_string = "";
    int search_len = search_.length();
    int end_index = 0;
    while ((end_index = source.find(search_)) != -1) {
        replaced_string += source.substr(0, end_index) + replacement_;
        source = source.substr(end_index + search_len);
    }
    replaced_string += source;
    return  replaced_string;
}

template <typename T>
std::vector<T> pyfunc::replace(std::vector<T> source, T search, T replacement) {
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == search) {
            source[i] = replacement;
        }
    }
    return source;
}

template <typename T>
T* pyfunc::replace(T* source, size_t size, T search, T replacement) {
    T* replaced_array;
    if (typeid(T) == typeid(char)) {
        replaced_array = new T[size + 1];
        replaced_array[size] = '\0';
    }
    else {
        replaced_array = new T[size];
    }

    for (size_t index = 0; index < size; index++) {
        if (*source == search) {
            replaced_array[index] = replacement;
        }
        else {
            replaced_array[index] = *source;
        }
        source++;
    }
    return replaced_array;
}

template <typename T>
T* pyfunc::replace(const T* source, size_t size, T search, T replacement) {
    T* replaced_array;
    if (typeid(T) == typeid(char)) {
        replaced_array = new T[size + 1];
        replaced_array[size] = '\0';
    }
    else {
        replaced_array = new T[size];
    }

    for (size_t index = 0; index < size; index++) {
        if (*source == search) {
            replaced_array[index] = replacement;
        }
        else {
            replaced_array[index] = *source;
        }
        source++;
    }
    return replaced_array;
}

template <typename T, size_t size>
std::array<T, size> pyfunc::replace(std::array<T, size> source, T search, T replacement) {
    for (size_t index = 0; index < size; index++) {
        if (source[index] == search) {
            source[index] = replacement;
        }
    }
    return source;
}
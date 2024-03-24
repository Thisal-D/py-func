#ifndef PY_FUNC_H
#define PY_FUNC_H


#include <iostream>
#include <array>
#include <vector>
#include <string>

template<typename T>
void __fix_index_range(T& start_index, T& end_index, size_t size);

namespace py {
    template<typename T>
    std::vector<T> range(T start, T end, T step);

    template<typename T>
    std::vector<T> range(std::vector<T> source, long long start_index, long long end_index, long long step);

    template<typename T>
    T* range(T* source, size_t size, long long start_index, long long end_index, long long step);

    template<typename T>
    T* range(const T* source, size_t size, long long start_index, long long end_index, long long step);

    /*
    template<typename T, size_t size ,size_t size_2>
    std::array<T, size_2> range(std::array<T, size> source, long long start_index, long long end_index, long long step);
    */

    std::string range(std::string source, long long start_index, long long end_index, long long step);


    //replace
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

    //split
    std::vector<std::string> split(std::string source, std::string splitter);

    std::vector<std::string> split(std::string source, char splitter);

    //count
    template <typename T2>
    T2 count(std::string source, std::string search);

    template <typename T2>
    T2 count(std::string source, char search_);

    template <typename T, typename T2>
    T2 count(std::vector<T> source, T search) ;

    template <typename T, typename T2>
    T2 count(T* source, size_t size ,T search);

    template <typename T, typename T2>
    T2 count(const T* source, size_t size, T search);

    template <typename T, size_t size, typename T2>
    T2 count(std::array<T, size> source, T search);

    //join
    std::string join(std::string source, std::string join_by);

    std::string join(std::string source, char join_by);

    template<typename T>
    std::string join(std::vector<T> source, std::string join_by);

    template<typename T>
    std::string join(std::vector<T> source, char join_by);

    template<typename T, size_t size>
    std::string join(std::array<T,size> source, std::string join_by);

    template<typename T, size_t size>
    std::string join(std::array<T,size> source, char join_by);

    template<typename T>
    std::string join(T* source, size_t size, std::string join_by);

    template<typename T>
    std::string join(T* source, size_t size, char join_by);

    template<typename T>
    std::string join(const T* source, size_t size, std::string join_by);

    template<typename T>
    std::string join(const T* source, size_t size, char join_by);

};


template<typename T>
void __fix_index_range(T& start_index, T& end_index, size_t size_){
    long long int size = (long long int)size_;
    if (start_index < -size) start_index = -size;
    if (end_index < -size) end_index = -size - 1;
    if (start_index > size) start_index = size;
    if (end_index > size) end_index = size;
    if (start_index < 0) start_index += size;
    if (end_index < 0) end_index += size;
}

//working :D
template<typename T>
std::vector<T> py::range(T start, T end, T step) {
    std::vector<T> vector_range;
    if (start < end && step>0) {
        for (start; start < end; start += step) {
            vector_range.push_back(start);
        }
    }
    else if (start > end && step < 0) {
        for (start; start > end; start += step) {
            vector_range.push_back(start);
        }
    }
    return vector_range;
}
//working :D
std::string py::range(std::string source, long long start_index, long long end_index, long long step) {
    std::string str_range = "";
    __fix_index_range<long long>(start_index, end_index, source.length());
    std::vector<long long> index_range = range<long long>(start_index, end_index, step);
    for (size_t index : index_range) {
        str_range += source[index];
    }
    return str_range;
}

template<typename T>
T* py::range(T* source, size_t size, long long start_index, long long end_index, long long step) {
    __fix_index_range<long long>(start_index, end_index, size);
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
T* py::range(const T* source, size_t size, long long start_index, long long end_index, long long step) {
    __fix_index_range<long long>(start_index, end_index, size);
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
std::array<T, size_2> py::range(std::array<T, size> source, long long start_index, long long end_index, long long step) {
    __fix_index_range(start_index, end_index, size);
    std::vector<long long> index_range = range<long long>(start_index, end_index, step);
    std::array<T, size_2 > T_t_array;
    for (size_t index = 0; index < index_range.size(); index++) {
        T_t_array[index] = source[index_range[index]];
    }
    return T_t_array;
}
*/

template<typename T>
std::vector<T> py::range(std::vector<T> source, long long start_index, long long end_index, long long step) {
    std::vector<T> T_vector{};
    __fix_index_range<long long>(start_index, end_index, source.size());
    std::vector<long long> index_range = range<long long>(start_index, end_index, step);
    for (size_t index : index_range) {
        T_vector.push_back(source[index]);
    }
    return T_vector;
}

//replace
template <typename T, typename T2>
std::string py::replace(std::string source, T search, T2 replacement) {
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
std::vector<T> py::replace(std::vector<T> source, T search, T replacement) {
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == search) {
            source[i] = replacement;
        }
    }
    return source;
}

template <typename T>
T* py::replace(T* source, size_t size, T search, T replacement) {
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
T* py::replace(const T* source, size_t size, T search, T replacement) {
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
std::array<T, size> py::replace(std::array<T, size> source, T search, T replacement) {
    for (size_t index = 0; index < size; index++) {
        if (source[index] == search) {
            source[index] = replacement;
        }
    }
    return source;
}

//same as pythom string split method
//split
std::vector<std::string> py::split(std::string source, std::string splitter) {
    std::vector<std::string> splitted_sources;
    std::string splitted_source = "";
    int end_index = 0;
    int splitter_len = splitter.length();
    while ((end_index = source.find(splitter)) != -1) {
        splitted_sources.push_back(source.substr(0, end_index));
        //splitted_sources.push_back(range(source ,0, end_index, 1));
        source = source.substr(end_index + splitter_len);
        //source = range(source, end_index+splitter_len, source.length(), 1);
    }
    splitted_sources.push_back(source);
    return splitted_sources;
}

std::vector<std::string> py::split(std::string source, char splitter){
    std::string splitter_ = (std::string)"" + splitter;
    return py::split(source, splitter_);
}

//count 
template <typename T2>
T2 py::count(std::string source, std::string search) {
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
T2 py::count(std::string source, char search_) {
    std::string search = (std::string)"" + search_;
    return py::count<T2>(source, search);
}

template <typename T, typename T2>
T2 py::count(std::vector<T> source, T search) {
    T2 count = 0;
    for (T src : source) {
        if (src == search) {
            count++;
        }
    }
    return count;
}

template <typename T, typename T2>
T2 py::count(T* source, size_t size, T search) {
    T2 count = 0;
    for (size_t index = 0; index < size; index++) {
        if (*source++ == search) {
            count++;
        }
    }
    return count;
}

template <typename T, typename T2>
T2 py::count(const T* source, size_t size, T search) {
    T2 count = 0;
    for (size_t index = 0; index < size; index++) {
        if (*source++ == search) {
            count++;
        }
    }
    return count;
}

template <typename T, size_t size, typename T2>
T2 py::count(std::array<T, size> source, T search) {
    T2 count = 0;
    for (T src : source) {
        if (src == search) {
            count++;
        }
    }
    return count;
}

//join
std::string py::join(std::string source, std::string join_by){
    std::string joined_str = "";
    for (size_t index=0; index<source.length()-1; index++){
        joined_str += source[index];
        joined_str += join_by; 
    }
    joined_str+=source[source.length()-1];
    return joined_str;
}

std::string py::join(std::string source, char join_by){
    std::string join_by_ = (std::string)""+join_by;
    return py::join(source, join_by_);
}

template<typename T>
std::string py::join(std::vector<T> source, std::string join_by){
    //bool string_convert = false;
    std::string joined_str = "";
    /*if (std::is_same<T,int>::value || std::is_same<T,long>::value || std::is_same<T,long long>::value || 
    std::is_same<T,unsigned int>::value || std::is_same<T,unsigned long>::value ||std::is_same<T,unsigned long long>::value || 
    std::is_same<T,float>::value|| std::is_same<T,double>::value || std::is_same<T,long double>::value ){
        string_convert = true;
    }*/
    for (size_t index=0; index<source.size()-1; index++){
        //if (string_convert) joined_str += std::to_string(source[index]);
        joined_str += source[index];
        joined_str += join_by;
    }
    //if (string_convert) joined_str += std::to_string(source[source.size()-1]);
    joined_str += source[source.size()-1];
    return joined_str;
}

template<typename T>
std::string py::join(std::vector<T> source, char join_by){
    std::string join_by_ = (std::string)""+join_by;
    return py::join(source, join_by_);
}

template<typename T, size_t size>
std::string py::join(std::array<T,size> source, std::string join_by){
    std::string joined_str = "";
    for (size_t index=0; index<size-1; index++){
        joined_str += source[index];
        joined_str += join_by;
    }
    joined_str += source[size-1];
    return joined_str;
}

template<typename T, size_t size>
std::string py::join(std::array<T,size> source, char join_by){
    std::string join_by_ = (std::string)""+join_by;
    return py::join(source, join_by_);
}

template<typename T>
std::string py::join(T* source, size_t size, std::string join_by){
    std::string joined_str = "";
    for (int index=0; index<size-1; index++){
        joined_str += *source++;
        joined_str += join_by;
    }
    joined_str += *source;
    return joined_str;
}

template<typename T>
std::string py::join(T* source, size_t size, char join_by){
    std::string join_by_ = (std::string)""+join_by;
    return py::join(source, size, join_by_);
}

template<typename T>
std::string py::join(const T* source, size_t size, std::string join_by){
    std::string joined_str = "";
    for (int index=0; index<size-1; index++){
        joined_str += *source++;
        joined_str += join_by;
    }
    joined_str += *source;
    return joined_str;
}

template<typename T>
std::string py::join(const T* source, size_t size, char join_by){
    std::string join_by_ = (std::string)""+join_by;
    return py::join(source, size, join_by_);
}


#endif
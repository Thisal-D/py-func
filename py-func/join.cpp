#include "join.h"


std::string pyfunc::join(std::string source, std::string join_by) {
    std::string joined_str = "";
    for (size_t index = 0; index < source.length() - 1; index++) {
        joined_str += source[index];
        joined_str += join_by;
    }
    joined_str += source[source.length() - 1];
    return joined_str;
}

std::string pyfunc::join(std::string source, char join_by) {
    std::string join_by_ = (std::string)"" + join_by;
    return pyfunc::join(source, join_by_);
}

template<typename T>
std::string pyfunc::join(std::vector<T> source, std::string join_by) {
    //bool string_convert = false;
    std::string joined_str = "";
    /*if (std::is_same<T,int>::value || std::is_same<T,long>::value || std::is_same<T,long long>::value ||
    std::is_same<T,unsigned int>::value || std::is_same<T,unsigned long>::value ||std::is_same<T,unsigned long long>::value ||
    std::is_same<T,float>::value|| std::is_same<T,double>::value || std::is_same<T,long double>::value ){
        string_convert = true;
    }*/
    for (size_t index = 0; index < source.size() - 1; index++) {
        //if (string_convert) joined_str += std::to_string(source[index]);
        joined_str += source[index];
        joined_str += join_by;
    }
    //if (string_convert) joined_str += std::to_string(source[source.size()-1]);
    joined_str += source[source.size() - 1];
    return joined_str;
}

template<typename T>
std::string pyfunc::join(std::vector<T> source, char join_by) {
    std::string join_by_ = (std::string)"" + join_by;
    return pyfunc::join(source, join_by_);
}

template<typename T, size_t size>
std::string pyfunc::join(std::array<T, size> source, std::string join_by) {
    std::string joined_str = "";
    for (size_t index = 0; index < size - 1; index++) {
        joined_str += source[index];
        joined_str += join_by;
    }
    joined_str += source[size - 1];
    return joined_str;
}

template<typename T, size_t size>
std::string pyfunc::join(std::array<T, size> source, char join_by) {
    std::string join_by_ = (std::string)"" + join_by;
    return pyfunc::join(source, join_by_);
}

template<typename T>
std::string pyfunc::join(T* source, size_t size, std::string join_by) {
    std::string joined_str = "";
    for (int index = 0; index < size - 1; index++) {
        joined_str += *source++;
        joined_str += join_by;
    }
    joined_str += *source;
    return joined_str;
}

template<typename T>
std::string pyfunc::join(T* source, size_t size, char join_by) {
    std::string join_by_ = (std::string)"" + join_by;
    return pyfunc::join(source, size, join_by_);
}

template<typename T>
std::string pyfunc::join(const T* source, size_t size, std::string join_by) {
    std::string joined_str = "";
    for (int index = 0; index < size - 1; index++) {
        joined_str += *source++;
        joined_str += join_by;
    }
    joined_str += *source;
    return joined_str;
}

template<typename T>
std::string pyfunc::join(const T* source, size_t size, char join_by) {
    std::string join_by_ = (std::string)"" + join_by;
    return pyfunc::join(source, size, join_by_);
}
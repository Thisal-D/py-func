#include "range.h"


template<typename T>
std::vector<T> pyfunc::range(T start, T end, T step) {
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

template std::vector<long long> pyfunc::range<long long>(long long, long long, long long);
template std::vector<int> pyfunc::range<int>(int, int, int);
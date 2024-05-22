#include "utils.h"


template<typename T>
void utils::__fix_index_range(T& start_index, T& end_index, size_t size_) {
    long long int size = static_cast<long long int>(size_);
    if (start_index < -size) start_index = -size;
    if (end_index < -size) end_index = -size - 1;
    if (start_index > size) start_index = size;
    if (end_index > size) end_index = size;
    if (start_index < 0) start_index += size;
    if (end_index < 0) end_index += size;
}

template void utils::__fix_index_range<long long>(long long&, long long&, unsigned long long);

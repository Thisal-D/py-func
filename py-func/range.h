#ifndef PY_FUNC_RANGE_H
#define PY_FUNC_RANGE_H

#include <vector>


namespace pyfunc {
    template<typename T>
    std::vector<T> range(T start, T end, T step);
}

#endif
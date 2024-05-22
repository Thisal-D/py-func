#ifndef PY_FUNC_SPLIT_H
#define PY_FUNC_SPLIT_H

#include <vector>
#include <string>


namespace pyfunc {
    std::vector<std::string> split(std::string source, std::string splitter);
    std::vector<std::string> split(std::string source, char splitter);
}

#endif
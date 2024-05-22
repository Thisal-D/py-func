#include "split.h"


std::vector<std::string> pyfunc::split(std::string source, std::string splitter) {
    std::vector<std::string> split_sources;
    std::string split_source = "";
    size_t end_index = 0;
    size_t splitter_len = splitter.length();
    while ((end_index = source.find(splitter)) != std::string::npos) {
        split_sources.push_back(source.substr(0, end_index));
        //split_sources.push_back(range(source ,0, end_index, 1));
        source = source.substr(end_index + splitter_len);
        //source = range(source, end_index+splitter_len, source.length(), 1);
    }
    split_sources.push_back(source);
    return split_sources;
}

std::vector<std::string> pyfunc::split(std::string source, char splitter) {
    std::string splitter_ = (std::string)"" + splitter;
    return pyfunc::split(source, splitter_);
}
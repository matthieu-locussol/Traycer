#include <Core/Parser.hpp>

#include <algorithm>

namespace Parser {
    char * getOption(char ** begin, char ** end, const std::string& option) {
        char ** itr = std::find(begin, end, option);

        if (itr != end && ++itr != end) {
            return *itr;
        }

        return 0;
    }

    bool hasOption(char ** begin, char ** end, const std::string& option) {
        return std::find(begin, end, option) != end;
    }
}
#ifndef HEADER_PARSER_HPP
#define HEADER_PARSER_HPP

#include <string>

namespace Parser {
    char * getOption(char ** begin, char ** end, const std::string& option);
    bool hasOption(char ** begin, char ** end, const std::string& option);
}

#endif // HEADER_PARSER_HPP
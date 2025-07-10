#pragma once
#include <string>
#include <vector>

struct Rules {
    std::string evaluation;
    std::string value;
};

struct Restriction {
    std::string variable;
    std::vector<Rules> rules;
};

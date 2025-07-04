#pragma once
#include <optional>
#include <string>

struct SmartValue {
    std::optional<double> a_double;
    std::optional<double> b_double;
    std::string a_string;
    std::string b_string;
};

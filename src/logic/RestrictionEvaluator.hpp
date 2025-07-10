#pragma once
#include "utils/Restriction.hpp"
#include <functional>
#include <unordered_map>

class RestrictionEvaluator {
public:
    RestrictionEvaluator();
    bool evaluate(const Restriction& restriction, const std::string& variable) const;

private:
    using RestrictionFunction = std::function<bool(const std::string&, const std::string&)>;
    std::unordered_map<std::string, RestrictionFunction> constraints_;
};

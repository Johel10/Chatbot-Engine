#include "logic/RestrictionEvaluator.hpp"
#include <regex>
#include <iostream>

RestrictionEvaluator::RestrictionEvaluator() {
    constraints_["min length"] = [this](const std::string& a, const std::string& b) {
        return a.size() >= std::stoi(b);
    };

    constraints_["max length"] = [this](const std::string& a, const std::string& b) {
        return a.size() <= std::stoi(b);
    };

    constraints_["min value"] = [this](const std::string& a, const std::string& b) {
        return std::stod(a) >= std::stod(b);
    };

    constraints_["max value"] = [this](const std::string& a, const std::string& b) {
        return std::stod(a) <= std::stod(b);
    };

    constraints_["regex"] = [this](const std::string& a, const std::string& b) {
        std::regex regex(b);
        return std::regex_match(a, regex);
    };
}

bool RestrictionEvaluator::evaluate(const Restriction& restriction, const std::string& variable) const {    
    for(const auto& rule : restriction.rules) {
        auto it = constraints_.find(rule.evaluation);
        if (it == constraints_.end()) return false;

        try {
            if (it->second(variable, rule.value) == false) return false;
        } catch (const std::exception& e) {
            std::cerr << "Error evaluating the " << e.what() << " condition" << std::endl;
            return false;
        }
    }

    return true;
}
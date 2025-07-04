#include "logic/ConditionEvaluator.hpp"
#include <iostream>
#include <cstdlib>

ConditionEvaluator::ConditionEvaluator() {
    operators_["equal"] = [this](const std::string& a, const std::string& b) {
        SmartValue smart_value = transform(a, b);
        return smart_compare(smart_value, std::equal_to());
    };

    operators_["not equal"] = [this](const std::string& a, const std::string& b) {
        SmartValue smart_value = transform(a, b);
        return smart_compare(smart_value, std::not_equal_to());
    };

    operators_["greater"] = [this](const std::string& a, const std::string& b) {
        SmartValue smart_value = transform(a, b);
        return smart_compare(smart_value, std::greater());
    };

    operators_["greater equal"] = [this](const std::string& a, const std::string& b) {
        SmartValue smart_value = transform(a, b);
        return smart_compare(smart_value, std::greater_equal());
    };

    operators_["less"] = [this](const std::string& a, const std::string& b) {
        SmartValue smart_value = transform(a, b);
        return smart_compare(smart_value, std::less());
    };

    operators_["less equal"] = [this](const std::string& a, const std::string& b) {
        SmartValue smart_value = transform(a, b);
        return smart_compare(smart_value, std::less_equal());
    };
}

bool ConditionEvaluator::evaluate(Condition& condition, const ChatbotEngine& engine) const {
    auto it = operators_.find(condition.evaluation);
    if (it == operators_.end()) {
        return false;
    }

    std::string actual_value = engine.get_variable(condition.variable);

    try {
        return it->second(actual_value, condition.value);
    } catch (const std::exception& e) {
        std::cerr << "Error evaluating the " << e.what() << " condition" << std::endl;
        return false;
    }
}

SmartValue ConditionEvaluator::transform(const std::string& a, const std::string b) const {
    SmartValue smart_value { std::nullopt, std::nullopt, a, b };

    try {
        std::size_t pos_a, pos_b;
        double value_a = std::stod(a, &pos_a);
        double value_b = std::stod(b, &pos_b);

        if (pos_a == a.size() && pos_b == b.size()) {
            smart_value.a_double = value_a;
            smart_value.b_double = value_b;
        }
    } catch (...) {}

    return smart_value;
}

template <typename T>
bool ConditionEvaluator::smart_compare(const SmartValue& smart_value, const T& compare_operator) const {
    if (smart_value.a_double && smart_value.b_double) {
        return compare_operator(*smart_value.a_double, *smart_value.b_double);
    } else {
        return compare_operator(smart_value.a_string, smart_value.b_string);
    }
}

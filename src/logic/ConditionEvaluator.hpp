#pragma once
#include "engine/ChatbotEngine.hpp"
#include "utils/Condition.hpp"
#include "utils/SmartValue.hpp"
#include <string>
#include <array>
#include <unordered_map>
#include <functional>

class ConditionEvaluator {
public:
    ConditionEvaluator();
    bool evaluate(Condition& condition, const ChatbotEngine& engine) const;

private:
    SmartValue transform(const std::string& a, const std::string b) const;
    template <typename T> bool smart_compare(const SmartValue& smart_value, const T& compare_operator) const;

    using ConditionFunction = std::function<bool(const std::string&, const std::string&)>;
    std::unordered_map<std::string, ConditionFunction> operators_;
};

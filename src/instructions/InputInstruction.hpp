#pragma once
#include "Instruction.hpp"
#include "logic/RestrictionEvaluator.hpp"
#include <string>

class InputInstruction : public Instruction {
public:
    InputInstruction(const std::string& variable_name, const Restriction& restriction);
    void execute(ChatbotEngine& engine) override;

private:
    std::string variable_;
    Restriction restriction_;
};

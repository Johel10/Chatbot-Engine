#pragma once
#include "Instruction.hpp"
#include <string>

class InputInstruction : public Instruction {
public:
    explicit InputInstruction(const std::string& variable_name);
    void execute(ChatbotEngine& engine) override;

private:
    std::string variable_;
};

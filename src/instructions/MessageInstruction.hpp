#pragma once
#include "Instruction.hpp"
#include <string>

class MessageInstruction : public Instruction {
public:
    explicit MessageInstruction(const std::string& text);
    void execute(ChatbotEngine& engine) override;

private:
    void replceVariables(ChatbotEngine& engine);

    std::string text_;
};

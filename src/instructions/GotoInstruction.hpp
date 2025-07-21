#pragma once
#include "instructions/Instruction.hpp"
#include "engine/ChatbotEngine.hpp"
#include <string>

class GotoInstruction : public Instruction {
public:
    GotoInstruction(const std::string& goto_label, const std::string& label = "");
    void execute(ChatbotEngine& engine) override;
private:
    std::string goto_label_;
};

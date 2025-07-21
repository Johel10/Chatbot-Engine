#pragma once
#include "Instruction.hpp"
#include "logic/RestrictionEvaluator.hpp"
#include <string>
#include <vector>
#include <memory>

class InputInstruction : public Instruction {
public:
    InputInstruction(const std::string& variable_name, const Restriction& restriction, const std::string& label = "");
    void add_else_instruction(std::unique_ptr<Instruction> instruction);
    void execute(ChatbotEngine& engine) override;

private:
    std::string variable_;
    Restriction restriction_;
    std::vector<std::unique_ptr<Instruction>> else_block_;
};

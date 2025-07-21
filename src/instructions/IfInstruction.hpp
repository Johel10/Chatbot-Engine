#pragma once
#include "instructions/Instruction.hpp"
#include "logic/ConditionEvaluator.hpp"
#include <vector>
#include <memory>

class IfInstruction : public Instruction {
public:
    IfInstruction(const Condition& condition, const std::string& label = "");
    void add_then_instruction(std::unique_ptr<Instruction> instruction);
    void add_else_instruction(std::unique_ptr<Instruction> instruction);
    void execute(ChatbotEngine& engine) override;

private:
    Condition condition_;
    std::vector<std::unique_ptr<Instruction>> then_block_;
    std::vector<std::unique_ptr<Instruction>> else_block_;
};

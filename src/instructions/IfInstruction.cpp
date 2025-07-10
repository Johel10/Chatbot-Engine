#include "instructions/IfInstruction.hpp"

IfInstruction::IfInstruction(const Condition& condition)
    : condition_(condition) {}

void IfInstruction::add_then_instruction(std::unique_ptr<Instruction> instruction) {
    then_block_.push_back(std::move(instruction));
}

void IfInstruction::add_else_instruction(std::unique_ptr<Instruction> instruction) {
    else_block_.push_back(std::move(instruction));
}

void IfInstruction::execute(ChatbotEngine& engine) {
    static ConditionEvaluator evaluator;

    if (evaluator.evaluate(condition_, engine)) {
        for (auto& instruction : then_block_)
            instruction->execute(engine);
    } else {
        for (auto& instruction : else_block_)
            instruction->execute(engine);
    }
}

#include "InputInstruction.hpp"
#include "engine/ChatbotEngine.hpp"
#include "logic/RestrictionEvaluator.hpp"
#include <iostream>

InputInstruction::InputInstruction(const std::string& variable_name, const Restriction& restriction, const std::string& label)
    : variable_(variable_name), restriction_(restriction), Instruction(label) {}

void InputInstruction::add_else_instruction(std::unique_ptr<Instruction> instruction) {
    else_block_.push_back(std::move(instruction));
}

void InputInstruction::execute(ChatbotEngine& engine) {
    RestrictionEvaluator evaluator;

    std::cout << "User: ";
    std::string input;
    std::getline(std::cin, input);

    if (evaluator.evaluate(restriction_, input)) {
        engine.set_variable(variable_, input);
    } else {
        engine.set_variable(variable_, "");
        for (auto& instruction : else_block_) {
            instruction->execute(engine);
        }
    }
}

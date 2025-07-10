#include "InputInstruction.hpp"
#include "engine/ChatbotEngine.hpp"
#include "logic/RestrictionEvaluator.hpp"
#include <iostream>

InputInstruction::InputInstruction(const std::string& variable_name, const Restriction& restriction)
    : variable_(variable_name), restriction_(restriction) {}

void InputInstruction::execute(ChatbotEngine& engine) {
    RestrictionEvaluator evaluator;

    std::cout << "User: ";
    std::string input;
    std::getline(std::cin, input);

    if (evaluator.evaluate(restriction_, input)) {
        engine.set_variable(variable_, input);
    } else {
        engine.set_variable(variable_, "");
    }
}

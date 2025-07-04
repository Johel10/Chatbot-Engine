#include "InputInstruction.hpp"
#include "engine/ChatbotEngine.hpp"
#include <iostream>

InputInstruction::InputInstruction(const std::string& variable_name)
    : variable_(variable_name) {}

void InputInstruction::execute(ChatbotEngine& engine) {
    std::cout << "User: ";
    std::string input;
    std::getline(std::cin, input);
    engine.set_variable(variable_, input);
}

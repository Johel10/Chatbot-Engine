#include "MessageInstruction.hpp"
#include <iostream>

MessageInstruction::MessageInstruction(const std::string& text)
    : text_(text) {}

void MessageInstruction::execute(ChatbotEngine&) {
    std::cout << "Bot: " << text_ << std::endl;
}

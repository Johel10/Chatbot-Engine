#include "MessageInstruction.hpp"
#include "engine/ChatbotEngine.hpp"
#include <regex>
#include <sstream>
#include <iostream>

MessageInstruction::MessageInstruction(const std::string& text)
    : text_(text) {}

void MessageInstruction::execute(ChatbotEngine& engine) {
    replceVariables(engine);
    std::cout << "Bot: " << text_ << std::endl;
}

void MessageInstruction::replceVariables(ChatbotEngine& engine) {
    std::regex pattern(R"(\[([^\]]+)\])");
    std::ostringstream result;
    size_t last_pos = 0;

    for (auto it = std::sregex_iterator(text_.begin(), text_.end(), pattern); it != std::sregex_iterator(); ++it) {
        std::string variable = (*it)[1];
        result << text_.substr(last_pos, it->position(0) - last_pos) << engine.get_variable(variable);
        last_pos = it->position(0) + it->length(0);
    }

    result << text_.substr(last_pos);
    text_ = result.str();
}
#include "ChatbotEngine.hpp"
#include "instructions/InstructionFactory.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

ChatbotEngine::ChatbotEngine(const std::string& script_path) {
    load_script(script_path);
}

void ChatbotEngine::run() {
    for (auto& instruction : instructions_) {
        instruction->execute(*this);
    }
}

void ChatbotEngine::set_variable(const std::string& key, const std::string& value) {
    variables_[key] = value;
}

std::string ChatbotEngine::get_variable(const std::string& key) const {
    auto it = variables_.find(key);
    return it != variables_.end() ? it->second : "";
}

void ChatbotEngine::load_script(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Error opening " << path << std::endl;
        return;
    }

    json script_json;
    file >> script_json;

    for (const auto& step : script_json) {
        auto instruction = create_instruction(step);
        if (instruction) {
            instructions_.push_back(std::move(instruction));
        }
    }
}

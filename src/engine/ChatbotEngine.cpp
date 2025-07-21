#include "ChatbotEngine.hpp"
#include "instructions/InstructionFactory.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

ChatbotEngine::ChatbotEngine(const std::string& script_path) {
    execution_index_ = 0;
    load_script(script_path);
}

void ChatbotEngine::run() {
    while (execution_index_ < instructions_.size()) {
        instructions_[execution_index_]->execute(*this);
        !jumped_ ? ++execution_index_ : jumped_ = false; // No jump_ flag active represents normal chat flow
    }
}

void ChatbotEngine::set_variable(const std::string& key, const std::string& value) {
    variables_[key] = value;
}

std::string ChatbotEngine::get_variable(const std::string& key) const {
    auto it = variables_.find(key);
    return it != variables_.end() ? it->second : "";
}

void ChatbotEngine::set_next_instruction(const std::string& label) {
    for (size_t instruction_index = 0; instruction_index < instructions_.size(); ++ instruction_index) {
        if (instructions_[instruction_index]->get_label() == label) {
            execution_index_ = instruction_index;
            jumped_ = true;
        }
    }
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

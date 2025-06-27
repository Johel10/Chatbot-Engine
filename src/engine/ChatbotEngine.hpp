#pragma once
#include "instructions/Instruction.hpp"
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

class ChatbotEngine {
public:
    explicit ChatbotEngine(const std::string& script_path);
    void run();
    void set_variable(const std::string& key, const std::string& value);
    std::string get_variable(const std::string& key) const;

private:
    std::vector<std::unique_ptr<Instruction>> instructions_;
    std::unordered_map<std::string, std::string> variables_;

    void load_script(const std::string& path);
};

#pragma once
#include <memory>
#include <string>

class ChatbotEngine;

class Instruction {
public:
    Instruction(const std::string& label) : label_(label){}
    virtual void execute(ChatbotEngine& engine) = 0;
    virtual ~Instruction() = default;
    virtual std::string get_label() { return label_; }
protected:
    std::string label_;
};

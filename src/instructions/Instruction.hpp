#pragma once
#include <memory>

class ChatbotEngine;

class Instruction {
public:
    virtual void execute(ChatbotEngine& engine) = 0;
    virtual ~Instruction() = default;
};

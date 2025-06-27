#include "InstructionFactory.hpp"
#include "MessageInstruction.hpp"
#include "InputInstruction.hpp"

std::unique_ptr<Instruction> create_instruction(const nlohmann::json& json_step) {
    std::string type = json_step["type"];
    
    if (type == "message") {
        return std::make_unique<MessageInstruction>(json_step["text"]);
    } else if (type == "input") {
        return std::make_unique<InputInstruction>(json_step["variable"]);
    }

    return nullptr;
}

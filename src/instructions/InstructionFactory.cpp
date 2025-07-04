#include "instructions/InstructionFactory.hpp"
#include "instructions/MessageInstruction.hpp"
#include "instructions/InputInstruction.hpp"
#include "instructions/IfInstruction.hpp"

std::unique_ptr<Instruction> create_instruction(const nlohmann::json& json_step) {
    std::string type = json_step["type"];
    
    if (type == "message") {
        return std::make_unique<MessageInstruction>(json_step["text"]);
    } else if (type == "input") {
        return std::make_unique<InputInstruction>(json_step["variable"]);
    } else if (type == "if") {
        Condition condition = { json_step["variable"], json_step["operator"], json_step["value"] };
        return std::make_unique<IfInstruction>(condition);
    }

    return nullptr;
}

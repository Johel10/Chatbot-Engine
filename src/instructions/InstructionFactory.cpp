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
        const Condition if_condition = { json_step["variable"], json_step["evaluation"], json_step["value"] };
        auto if_instruction = std::make_unique<IfInstruction>(if_condition);
        const nlohmann::json then_sequence = json_step["then"];
        const nlohmann::json else_sequence = json_step["else"];

        for (const auto& json : then_sequence)
            if_instruction->add_then_instruction(create_instruction(json));

        for (const auto& json : else_sequence)
            if_instruction->add_else_instruction(create_instruction(json));

        return if_instruction;
    }

    return nullptr;
}

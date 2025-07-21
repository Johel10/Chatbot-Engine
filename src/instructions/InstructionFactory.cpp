#include "instructions/InstructionFactory.hpp"
#include "instructions/MessageInstruction.hpp"
#include "instructions/InputInstruction.hpp"
#include "instructions/IfInstruction.hpp"
#include "instructions/GotoInstruction.hpp"
#include <iostream>

std::unique_ptr<Instruction> create_instruction(const nlohmann::json& json_step) {
    
    std::string type = json_step["type"].get<std::string>();
    
    if (type == "message") {
        return std::make_unique<MessageInstruction>(json_step["text"].get<std::string>());

    } else if (type == "input") {

        Restriction restriction = { 
            json_step["variable"].get<std::string>(),
            {}
        };

        for (const auto& evaluations : json_step["restriction"]) {
            restriction.rules.push_back(Rules{
                evaluations["evaluation"].get<std::string>(),
                evaluations["value"].get<std::string>()
            });
        }

        auto input_instruction = std::make_unique<InputInstruction>(json_step["variable"].get<std::string>(), restriction, json_step.value("label", ""));

        if (json_step.contains("else") && json_step["else"].is_array()) {
            for (const auto& json : json_step["else"])
                input_instruction->add_else_instruction(std::move(create_instruction(json)));
        }

        return input_instruction;

    } else if (type == "if") {
        
        const Condition if_condition = { 
            json_step["variable"].get<std::string>(),
            json_step["evaluation"].get<std::string>(),
            json_step["value"].get<std::string>()
        };

        auto if_instruction = std::make_unique<IfInstruction>(if_condition);
        const nlohmann::json then_sequence = json_step["then"];
        const nlohmann::json else_sequence = json_step["else"];

        for (const auto& json : then_sequence)
            if_instruction->add_then_instruction(create_instruction(json));

        for (const auto& json : else_sequence)
            if_instruction->add_else_instruction(create_instruction(json));

        return if_instruction;

    } else if (type == "goto") {
        return std::make_unique<GotoInstruction>(json_step["goto"].get<std::string>(), json_step.value("label", ""));
    }

    return nullptr;
}

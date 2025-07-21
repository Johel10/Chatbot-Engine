#include "instructions/GotoInstruction.hpp"

GotoInstruction::GotoInstruction(const std::string& goto_label, const std::string& label) : 
    goto_label_(goto_label), Instruction(label) {}

void GotoInstruction::execute(ChatbotEngine& engine) {
    engine.set_next_instruction(goto_label_);
}
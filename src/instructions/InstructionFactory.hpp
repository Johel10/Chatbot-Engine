#pragma once
#include <memory>
#include <nlohmann/json.hpp>

class Instruction;

std::unique_ptr<Instruction> create_instruction(const nlohmann::json& json_step);

cmake_minimum_required(VERSION 3.10)
project(ChatbotEngine)

# Usa C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye las cabeceras de nlohmann/json si las pusiste en include/
include_directories(${PROJECT_SOURCE_DIR}/include)

# Incluye las cabeceras de tu propio proyecto (por claridad, aunque src/ suele ser implícito)
include_directories(${PROJECT_SOURCE_DIR}/src)

# Agrega el ejecutable
add_executable(chatbot
    src/main.cpp
    src/engine/ChatbotEngine.cpp
    src/instructions/IfInstruction.cpp
    src/instructions/InputInstruction.cpp
    src/instructions/MessageInstruction.cpp
    src/instructions/InstructionFactory.cpp
    src/logic/ConditionEvaluator.cpp
    src/logic/RestrictionEvaluator.cpp
    src/session/ChatbotSession.cpp
    # agrega aquí otros .cpp que vayas creando
)

# No necesitas linkear librerías externas porque nlohmann/json es un header-only

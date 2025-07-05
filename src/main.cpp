#include "engine/ChatbotEngine.hpp"
#include <iostream>

int main() {
    ChatbotEngine engine("../scripts/chatbot1.json");
    engine.run();
    

    return 0;
}

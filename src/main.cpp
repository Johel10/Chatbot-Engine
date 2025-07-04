#include "engine/ChatbotEngine.hpp"
#include <iostream>

int main() {
    ChatbotEngine engine("../scripts/chatbot1.json");
    engine.run();
    std::cout << "Estado es " << engine.get_variable("estado") << std::endl;

    return 0;
}

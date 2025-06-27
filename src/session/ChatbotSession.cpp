#include "ChatbotSession.hpp"
#include "engine/ChatbotEngine.hpp"

ChatbotSession::ChatbotSession(const std::string& chatbot_name, int session_id)
    : chatbot_name_(chatbot_name), script_path_("../scripts/" + chatbot_name + ".json"),
    session_id_(session_id) {}

void ChatbotSession::run() {
    ChatbotEngine engine(script_path_);
    engine.run();
}

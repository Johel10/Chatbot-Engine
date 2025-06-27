#pragma once
#include <string>

class ChatbotSession {
public:
    ChatbotSession(const std::string& chatbot_name, int session_id);
    void run();

private:
    std::string chatbot_name_;
    std::string script_path_;
    int session_id_;
};

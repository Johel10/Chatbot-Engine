#include "session/ChatbotSession.hpp"
#include <iostream>

int main() {

    ChatbotSession session("chatbot1", 1);
    session.run();
    
    //toDo:
    // para la instrucción input hay que replicar la lógica de agregarle una secuencia else como la instrucción if
    // implementar validaciones en las intrucciones input -> falta agregar un set de instrucciones a ejecutar cuando no se cumplen las validaciones
    // investigar recurrencia y api / web sockets
    // cambiar la consola a respuestas https o respuesta por web socket

    return 0;
}

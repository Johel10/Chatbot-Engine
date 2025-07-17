# Chatbot Engine v0.1

> Este proyecto se inspira en diferentes motores para crear chatbots de forma sencilla. Este motor de chatbot funciona como gestor de múltiples chatbot, definidos siguiendo una sintaxis específica en archivos con formato .json y que definen el comportamiento de estos chatbots. Este motor tiene dos funciones principales: orquestar el flujo de cada uno de los chatbots definidos en los archivos .json y manejar sesiones simultáneas sin causar colisiones y permitiendo estas conexiones por medio de un REST/API.

---

- [Proyecto](#proyecto)
- [Requisitos](#requisitos)
- [Instalación](#instalación)
    - [macOS](#macos)
    - [Linux](#linux)
    - [Windows](#windows)
- [Compilación](#compilación)
- [Ejecución](#ejecución)
- [Sintaxis para chatbot](#sintaxis)
- [Agradecimientos](#agradecimientos)

---

## Proyecto

Este motor permite ejecutar flujos de chatbot creados a partir de un archivo .json que sigue una sintaxis sencilla. El motor interpreta estos archivos para aplicar validaciones de datos, seguir instrucciones específicas y hasta usar condicionales básicas, con el fin de lograr un objetivo específico como recolectar datos de un cliente o brindar ayuda o información en caso de ser requerida.

---

## Requisitos

- CMake >= 3.15
- C++17 o superior
- make
- Compilador (clang, g++, etc...)

---

## Instalación

Se puede clonar el repositorio usando estos comandos:
```bash
git clone https://github.com/usuario/chatbot_engine.git
cd chatbot_engine
```

### macOS

```bash
brew install cmake make
```

### Linux

#### Linux Debian-based

```bash
sudo apt update
sudo apt install build-essential cmake
```

### Windows

- Instalar un compilador como [MinGW](https://sourceforge.net/projects/mingw/)
- Instalar Make, se puede ejecutar el comando de Chocolatey:
```bash
choco install make
```

---

## Compilación

```bash
mkdir build
cd build
cmake ..
make
```

Estas instrucciones generan el ejecutable del proyecto.

- En macOS / Linux: `./build/chatbot`
- En Windows: `.\build\Debug\chatbot.exe`

---

## Ejecución

### macOS / Linux

```bash
cd build
./chatbot
```

### Windows

```bash
cd build
.\Debug\chatbot.exe
```

---

## Sintaxis

Existen diferentes tipos de instrucciones para crear los chatbots, estos archivos de definición consisten en un arreglo de objetos tipo JSON, las instrucciones principales son: "message", "input", e "if".

La definición de los objetos JSON de estas instrucciones son:

- message: 
```json
{ 
    type: "message", 
    text: [mensaje personalizado del chatbot] 
}
```
Se puede usar sintaxis de corchetes para interpolar variables en el texto.

- input: 
```json
{ 
    type: "input", 
    variable: [variable donde guardar la entrada], 
    restriction: [ 
        { 
            evaluation: evaluation, 
            value: value 
        }, 
        ... 
    ] 
}
```
Las posibles `evaluation` son: `[ "min length" | "max length" | "min value" | "max value" | regex ]`.<br/>
Las posibles `value` son números en formato string o una regex, según sea el `evaluation`.

- if: 
```json
{ 
    type: "if", 
    variable: [variable a evaluar], 
    evaluation: evaluation, 
    value: value, 
    then: instructions, 
    else: instructions 
}
```
Las posibles `evaluation` son: `[ "equal" | "not equal", | "greater" | "greater equal" | "less" | "less equal" ]`.<br/>
Las posibles `value` son números en formato string o strings como tal.<br/>
Las posibles `instructions` son arreglos de instrucciones ya definidas (message, input, if).

Ejemplo básico
```json
[
    {
        "type": "message",
        "text": "¿Cuál es tu color favorito?"
    },
    {
        "type": "input",
        "variable": "color_favorito",
        "restriction": [
            {
                "evaluation": "regex",
                "value": "^[a-zA-ZÁÉÍÓÚáéíóú ]{3,15}$"
            }
        ]
    },
    {
        "type": "if",
        "variable": "color_favorito",
        "evaluation": "equal",
        "value": "rojo",
        "then": [
            {
                "type": "message",
                "text": "Mi color favorito también es el [color_favorito]."
            }
        ],
        "else": [
            {
                "type": "message",
                "text": "Mi color favorito es el rojo, pero el [color_favorito] también me agrada."
            }
        ]
    },
    {
        "type": "message",
        "text": "¡Gracias por usar Chatbot Engine!"
    }
]
```

---

## Agradecimientos

Este proyecto hace uso de la librería `nlohmann/json` para el manejo de archivos JSON en C++. Agradecimientos especiales a Niels Lohmann y colaboradores por su aporte. [Librería para manejo de JSON en C++](https://github.com/nlohmann/json).

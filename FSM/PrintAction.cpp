// #include "PrintAction.h"
// #include "StateMachine.h"
// #include <iostream>

// // Constructor
// PrintAction::PrintAction(const std::string& message, bool isVariable)
//     : message(message), isVariable(isVariable) {}

// // Execute function
// void PrintAction::execute(std::map<std::string, int>& variables, StateMachine&) const {
//     if (isVariable) {
//         std::cout << message << ": " << variables[message] << std::endl;
//     } else {
//         std::cout << message << std::endl;
//     }
// }
#include "PrintAction.h"
#include <iostream>
#include <map>
#include <stdexcept>

PrintAction::PrintAction(const std::string& message, bool isVariable) 
    : message(message), isVariable(isVariable) {}

void PrintAction::execute(std::map<std::string, int>& variables, StateMachine& fsm) const {
    if (isVariable) {
        auto it = variables.find(message);
        if (it != variables.end()) {
            std::cout << it->second << std::endl;
        } else {
            throw std::invalid_argument("Variable " + message + " not found.");
        }
    } else {
        std::cout << message << std::endl;
    }
}
std::string PrintAction::description() const {
    return "PRINT(" + message + ")";
}
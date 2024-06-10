#include "WAITAction.h"
#include "StateMachine.h"
#include <iostream>

void WAITAction::execute(std::map<std::string, int>&, StateMachine& fsm) const {
    std::string userInput;
    while (true) {
        std::cin >> userInput;
        if (userInput == "END") {
            fsm.end();
            break;
        }
        int input = std::stoi(userInput);
        if (fsm.transition(input)) {
            break;
        } else {
            std::cerr << "Invalid input, try again." << std::endl;
        }
    }
}

std::string WAITAction::description() const {
    return "WAIT";
}
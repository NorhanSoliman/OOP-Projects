#include "JMPAction.h"
#include "StateMachine.h"
#include <iostream>

JMPAction::JMPAction(const std::string& stateName) : stateName(stateName) {}

void JMPAction::execute(std::map<std::string, int>&, StateMachine& fsm) const {
    std::cout << fsm.getName() << ": Executing JMP action to state " << stateName << std::endl;
    fsm.setCurrentState(stateName);
}

std::string JMPAction::description() const {
    return "JMP(" + stateName + ")";
}

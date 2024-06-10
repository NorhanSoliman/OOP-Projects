#include "JMP0Action.h"
#include "StateMachine.h"
#include "Utils.h" 
#include <stdexcept>
#include <iostream>

JMP0Action::JMP0Action(const std::string& machineName) : machineName(machineName) {}

void JMP0Action::execute(std::map<std::string, int>& variables, StateMachine& fsm) const {
    std::string machineNameWithoutExtension = stripFSMExtension(machineName);
    // Find the target FSM
    StateMachine* targetFSM = StateMachine::getMachine(machineNameWithoutExtension);
    if (targetFSM) {
        const std::string& startState = targetFSM->getStartState();
        if (!startState.empty() && targetFSM->setCurrentState(startState)) {
            fsm.end(); // to end the current FSM
            targetFSM->start(); // to start the target FSM
        } else {
            throw std::runtime_error("Failed to jump to the start state of machine: " + machineName);
        }
    } else {
        throw std::runtime_error("Machine " + machineName + " does not exist.");
    }
}

std::string JMP0Action::description() const {
    return "JMP0(" + machineName + ")";
}
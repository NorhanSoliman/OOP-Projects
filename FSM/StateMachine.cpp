#include "StateMachine.h"
#include <iostream>
#include <stdexcept>

std::map<std::string, StateMachine*> StateMachine::machines;

StateMachine::StateMachine(const std::string& name) : name(name), running(false) {
    StateMachine::addMachine(name, this);
}

void StateMachine::addVariable(const std::string& var) {
    variables[var] = 0; // Initialize variables to 0
    //variables[var]; // Initialize variables to 0

}

void StateMachine::addState(std::shared_ptr<State> state) {
    stateList.push_back(state); // Add state to vector
    states[state->getName()] = state; // Add state to map
    if (startState.empty()) {
        setStartState(state->getName());
    }
}

void StateMachine::addTransition(std::shared_ptr<Transition> transition) {
    transitions.push_back(transition);
}

void StateMachine::start() {
    running = true;
    if (!startState.empty()) {
        setCurrentState(startState);
        while (running && currentState) {
            currentState->execute(variables, *this);
        }
    }
}

bool StateMachine::setCurrentState(const std::string& stateName) {
    auto it = states.find(stateName);
    if (it != states.end()) {
        currentState = it->second;
        return true;
    }
    return false;
}

bool StateMachine::transition(int input) {
    for (const auto& transition : transitions) {
        if (transition->getSource() == currentState->getName() && transition->getInput() == input) {
            return setCurrentState(transition->getDestination());
        }
    }
    return false;
}

void StateMachine::end() {
    running = false;
}

void StateMachine::setStartState(const std::string& stateName) {
    startState = stateName;
}

const std::string& StateMachine::getStartState() const {
    return startState;
}

std::vector<std::string> StateMachine::getStateNames() const {
    std::vector<std::string> names;
    for (const auto& state : stateList) {
        names.push_back(state->getName());
    }
    return names;
}

std::vector<std::string> StateMachine::getTransitions() const {
    std::vector<std::string> result;
    for (const auto& transition : transitions) {
        result.push_back("[" + std::to_string(transition->getInput()) + "] " + transition->getSource() + " >> " + transition->getDestination());
    }
    return result;
}

void StateMachine::clearTransitions() {
    transitions.clear();
}

StateMachine* StateMachine::getMachine(const std::string& name) {
    auto it = machines.find(name);
    if (it != machines.end()) {
        return it->second;
    }
    return nullptr;
}

void StateMachine::addMachine(const std::string& name, StateMachine* machine) {
    machines[name] = machine;
}
const std::string& StateMachine::getName() const {
    return name;
}
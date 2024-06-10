#include "State.h"
#include "StateMachine.h"
#include <iostream>


State::State(const std::string& name) : name(name) {}

const std::string& State::getName() const {
    return name;
}

void State::addAction(std::shared_ptr<Action> action) {
    actions.push_back(action);
}

void State::execute(std::map<std::string, int>& variables, StateMachine& fsm) const {
    std::cout << fsm.getName() << ": State " << name << std::endl;

    // Using a lambda expression to execute each action
    auto executeAction = [&](const std::shared_ptr<Action>& action) {
        std::cout << fsm.getName() << ": Executing " << action->description() << std::endl;
        action->execute(variables, fsm);
    };
    
    for (const auto& action : actions) {
        executeAction(action);
    }
}

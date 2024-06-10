#ifndef STATE_H
#define STATE_H

#include "Action.h"
#include <vector>
#include <memory>
#include <map>
#include <string>
#include <functional>

class State {
public:
    State(const std::string& name);
    const std::string& getName() const;
    void addAction(std::shared_ptr<Action> action);
    void execute(std::map<std::string, int>& variables, class StateMachine& fsm) const;

private:
    std::string name;
    std::vector<std::shared_ptr<Action>> actions;
};

#endif // STATE_H

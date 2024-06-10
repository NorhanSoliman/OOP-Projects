#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include "Transition.h"
#include <map>
#include <vector>
#include <memory>
#include <string>

class StateMachine {
public:
    StateMachine(const std::string& name);
    void addVariable(const std::string& var);
    void addState(std::shared_ptr<State> state);
    void addTransition(std::shared_ptr<Transition> transition);
    void start();
    bool setCurrentState(const std::string& stateName);
    bool transition(int input);
    void end();
    void setStartState(const std::string& stateName);
    const std::string& getStartState() const;
    std::vector<std::string> getStateNames() const;
    std::vector<std::string> getTransitions() const;
    const std::string& getName() const; 
    void clearTransitions();
    static StateMachine* getMachine(const std::string& name);
    static void addMachine(const std::string& name, StateMachine* machine);

private:
    std::string name;
    std::shared_ptr<State> currentState;
    std::vector<std::shared_ptr<State>> stateList; 
    std::map<std::string, std::shared_ptr<State>> states; // Keep a map for quick lookup
    std::vector<std::shared_ptr<Transition>> transitions;
    std::map<std::string, int> variables;
    bool running;
    std::string startState;

    static std::map<std::string, StateMachine*> machines;
};

#endif // STATEMACHINE_H

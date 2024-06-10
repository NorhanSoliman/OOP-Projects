#ifndef ACTION_H
#define ACTION_H
#include <map>
#include <string>

class StateMachine; 

class Action {
public:
    virtual ~Action() = default;
    virtual void execute(std::map<std::string, int>& variables, StateMachine& fsm) const = 0;
    virtual std::string description() const = 0; 

};

#endif // ACTION_H

#ifndef JMPACTION_H
#define JMPACTION_H

#include "Action.h"
#include <string>

class JMPAction : public Action {
public:
    JMPAction(const std::string& stateName);
    void execute(std::map<std::string, int>& variables, StateMachine& fsm) const override;
    std::string description() const override; 

private:
    std::string stateName;
};

#endif // JMPACTION_H

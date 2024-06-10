#ifndef ASSIGNACTION_H
#define ASSIGNACTION_H

#include "Action.h"
#include <vector>
#include <string>

class AssignAction : public Action {
public:
    AssignAction(const std::string& variable, const std::vector<std::string>& operands, char op);
    void execute(std::map<std::string, int>& variables, StateMachine& fsm) const override;
    std::string description() const override;
private:
    std::string variable;
    std::vector<std::string> operands;
    char op;
};

#endif // ASSIGNACTION_H

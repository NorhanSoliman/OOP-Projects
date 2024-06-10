#ifndef PRINTACTION_H
#define PRINTACTION_H
#include "Action.h"
#include <string>

class PrintAction : public Action {
public:
    PrintAction(const std::string& message, bool isVariable);
    void execute(std::map<std::string, int>& variables, StateMachine& fsm) const override;
    std::string description() const override;
private:
    std::string message;
    bool isVariable;
};

#endif // PRINTACTION_H

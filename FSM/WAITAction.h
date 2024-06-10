#ifndef WAITACTION_H
#define WAITACTION_H
#include "Action.h"

class WAITAction : public Action {
public:
    void execute(std::map<std::string, int>& variables, StateMachine& fsm) const override;
    std::string description() const override;
};

#endif // WAITACTION_H

#ifndef ENDACTION_H
#define ENDACTION_H
#include "Action.h"

class ENDACTION : public Action {
public:
    void execute(std::map<std::string, int>& variables, StateMachine& fsm) const override;
    std::string description() const override;
};

#endif // ENDACTION_H

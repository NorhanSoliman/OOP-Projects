#ifndef JMP0ACTION_H
#define JMP0ACTION_H

#include "Action.h"
#include <string>

class JMP0Action : public Action {
public:
    JMP0Action(const std::string& machineName);
    void execute(std::map<std::string, int>& variables, StateMachine& fsm) const override;
    std::string description() const override;
private:
    std::string machineName;
};

#endif // JMP0ACTION_H

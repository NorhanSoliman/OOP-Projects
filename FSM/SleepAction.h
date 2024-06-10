#ifndef SLEEPACTION_H
#define SLEEPACTION_H
#include "Action.h"

class SleepAction : public Action {
public:
    SleepAction(int duration);
    void execute(std::map<std::string, int>& variables, StateMachine& fsm) const override;
    std::string description() const override;
private:
    int duration;
};

#endif // SLEEPACTION_H

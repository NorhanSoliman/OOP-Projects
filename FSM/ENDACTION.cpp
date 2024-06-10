#include "ENDACTION.h"
#include "StateMachine.h"

void ENDACTION::execute(std::map<std::string, int>&, StateMachine& fsm) const {
    fsm.end();
}

std::string ENDACTION::description() const {
    return "END";
}
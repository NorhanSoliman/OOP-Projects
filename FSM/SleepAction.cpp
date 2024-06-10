#include "SleepAction.h"
#include "StateMachine.h"
#include <thread>
#include <chrono>

SleepAction::SleepAction(int duration) : duration(duration) {}

void SleepAction::execute(std::map<std::string, int>&, StateMachine&) const {
    std::this_thread::sleep_for(std::chrono::seconds(duration));
}

std::string SleepAction::description() const {
    return "SLEEP(" + std::to_string(duration) + ")";
}
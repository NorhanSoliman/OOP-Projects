#include "Transition.h"

Transition::Transition(int input, const std::string& source, const std::string& destination)
    : input(input), sourceState(source), destinationState(destination) {}

//gets input
int Transition::getInput() const {
    return input;
}

// Getter for the source state name
std::string Transition::getSource() const {
    return sourceState;
}

//to get the destination state name
std::string Transition::getDestination() const {
    return destinationState;
}

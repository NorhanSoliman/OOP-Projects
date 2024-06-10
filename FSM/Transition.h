#ifndef TRANSITION_H
#define TRANSITION_H
#include <string>
class Transition {
public:
    Transition(int input, const std::string& source, const std::string& destination);
    int getInput() const;
    std::string getSource() const;
    std::string getDestination() const;
private:
    int input;
    std::string sourceState;
    std::string destinationState;
};
#endif // TRANSITION_H

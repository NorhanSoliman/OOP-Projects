#include "AssignAction.h"
#include "StateMachine.h"
#include <cstdlib> // for std::isdigit
#include <iostream> // for debugging

AssignAction::AssignAction(const std::string& variable, const std::vector<std::string>& operands, char op)
    : variable(variable), operands(operands), op(op) {}

void AssignAction::execute(std::map<std::string, int>& variables, StateMachine&) const {
    //std::cout << "operation is: " << op << std::endl;

    // Initialize the result based on the operation
    int result = (op == '+') ? 0 : 1;

    //std::cout << "initialization: " << result << std::endl;
    // for (int i = 0; i < operands.size(); ++i) {
    //     std::cout << "Operands are: " << operands[i] << std::endl;
    // }

    // Ensure the variable is initialized before use
    if (variables.find(variable) == variables.end()) {
        variables[variable] = (op == '+') ? 0 : 1;
    }

    for (const auto& operand : operands) {
        int value;
        if (std::isdigit(operand[0]) || (operand[0] == '-' && std::isdigit(operand[1]))) {
            value = std::stoi(operand);
        } else {
            if (variables.find(operand) == variables.end()) {
                throw std::invalid_argument("Variable " + operand + " not found.");
            }
            value = variables[operand];
        }

        if (op == '+') {
            result += value;
        } else if (op == '*') {
            //std::cout << "Multiplication by " << value << std::endl;
            result *= value;
        }
    }

    // Store the computed result in the variable
    variables[variable] = result;
    //debugging
    std::cout << "Updated variable " << variable << " to " << result << std::endl;
}
std::string AssignAction::description() const {
    std::string desc = variable + " = " + op + "(";
    for (size_t i = 0; i < operands.size(); ++i) {
        desc += operands[i];
        if (i < operands.size() - 1) desc += ", ";
    }
    desc += ")";
    return desc;
}
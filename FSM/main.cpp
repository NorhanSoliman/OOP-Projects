#include "StateMachine.h"
#include "PrintAction.h"
#include "SleepAction.h"
#include "AssignAction.h"
#include "JMPAction.h"
#include "WAITAction.h"
#include "ENDACTION.h"
#include "JMP0Action.h"
#include "Utils.h" 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <memory>
#include <algorithm>
#include <regex>

//a helper function to trim whitespace from a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

//this is a heper function also to extract the contents within parentheses
std::string extractContents(const std::string& str) {
    size_t start = str.find('(');
    size_t end = str.rfind(')');
    if (start == std::string::npos || end == std::string::npos || start >= end) {
        throw std::invalid_argument("Invalid format: " + str);
    }
    return trim(str.substr(start + 1, end - start - 1));
}

// parsing the FSM file
void parseFSMFile(const std::string& filename, StateMachine& fsm) {
    fsm.clearTransitions();  //was used during debugging

    std::ifstream fsmFile(filename);
    if (!fsmFile.is_open()) {
        throw std::runtime_error("Failed to open FSM file: " + filename);
    }

    std::string line;
    std::string section;
    bool firstStateSet = false;
    while (std::getline(fsmFile, line)) {
        line = trim(line);
        if (line.empty()) {
            continue; // to skip empty lines
        }
        if (line.find("FSM") == 0) {
            continue; // to skip FSM line
        } else if (line.find("VAR") == 0) {
            section = "VAR";
            continue;
        } else if (line.find("STATES:") == 0) {
            section = "STATES";
            continue;
        } else if (line.find("TRANSITIONS:") == 0) {
            section = "TRANSITIONS";
            continue;
        }

        std::istringstream iss(line);
        if (section == "VAR") {
            std::string var;
            while (iss >> var) {
                fsm.addVariable(var);
            }
        } else if (section == "STATES") {
            std::string stateName;
            iss >> stateName;
            if (stateName.front() != '[' || stateName.back() != ']') {
                throw std::invalid_argument("Invalid state name: " + stateName);
            }
            stateName = stateName.substr(1, stateName.length() - 2); // Removes [ ]
            std::shared_ptr<State> state = std::make_shared<State>(stateName);

            std::string action;
            std::getline(iss, action);
            std::istringstream actionStream(action);
            std::string singleAction;
            while (std::getline(actionStream, singleAction, ';')) {
                singleAction = trim(singleAction);
                if (singleAction.empty()) {
                    continue; // to skip empty actions
                }
                //std::cout << "Parsing action: " << singleAction << std::endl; // Debug statement
                if (singleAction.find("PRINT") == 0) {
                    std::string message = extractContents(singleAction);
                    //std::cout << "PRINT action message: " << message << std::endl; // Debug statement
                    bool isVariable = isalpha(message[0]) && message.find(' ') == std::string::npos; // Check if it's a variable name
                    state->addAction(std::make_shared<PrintAction>(message, isVariable));
                } else if (singleAction.find("SLEEP") == 0) {
                    std::string durationStr = extractContents(singleAction);
                    int duration = std::stoi(durationStr);
                    state->addAction(std::make_shared<SleepAction>(duration));
                } else if (singleAction.find("=") != std::string::npos) {
                    std::string variable = singleAction.substr(0, singleAction.find('='));
                    variable.erase(std::remove(variable.begin(), variable.end(), ' '), variable.end());

                    std::string operation = singleAction.substr(singleAction.find('=') + 1);
                    operation = trim(operation);  // to trim any leading whitespace
                    char op = operation[0];  // Extract the operation character
                    if (op != '+' && op != '*') {
                        throw std::invalid_argument("Unsupported operation: " + std::string(1, op));
                    }
                    std::string operandsStr = extractContents(operation);
                    std::istringstream opStream(operandsStr);
                    std::vector<std::string> operands;
                    std::string operand;
                    while (std::getline(opStream, operand, ',')) {
                        operands.push_back(trim(operand));
                    }
                    state->addAction(std::make_shared<AssignAction>(variable, operands, op));
                } else if (singleAction.find("JMP0") == 0) {  
                    std::string machineName = extractContents(singleAction);
                    state->addAction(std::make_shared<JMP0Action>(machineName));
                } else if (singleAction.find("JMP") == 0) {
                    std::string stateName = extractContents(singleAction);
                    state->addAction(std::make_shared<JMPAction>(stateName));
                } else if (singleAction.find("WAIT") == 0) {
                    state->addAction(std::make_shared<WAITAction>());
                } else if (singleAction.find("END") == 0) {
                    state->addAction(std::make_shared<ENDACTION>());
                } else {
                    throw std::invalid_argument("Invalid action: " + singleAction);
                }
            }
            fsm.addState(state);
            if (!firstStateSet) {
                fsm.setStartState(state->getName()); // to make sure first state is set as the start state
                firstStateSet = true;
            }
        } else if (section == "TRANSITIONS") {
            std::regex transitionRegex(R"(\[(\d+)\]\s*(\w+)\s*>>\s*(\w+))"); // a regex to match transition lines like "[1] A >> B":
                                                                                // [input] source >> destination
            std::smatch match;
            if (std::regex_match(line, match, transitionRegex)) {
                int input = std::stoi(match[1].str());
                std::string source = match[2].str();
                std::string destination = match[3].str();
                std::shared_ptr<Transition> transition = std::make_shared<Transition>(input, source, destination);
                fsm.addTransition(transition);
            } else {
                throw std::invalid_argument("Invalid transition format: " + line);
            }
        }
    }
}

int main() {
    try {
        std::string filename1, filename2;
        std::cout << "Enter the first FSM file: ";
        std::cin >> filename1;
        std::cout << "Enter the second FSM file: ";
        std::cin >> filename2;

        StateMachine fsm1(stripFSMExtension(filename1));
        parseFSMFile(filename1, fsm1);

        StateMachine fsm2(stripFSMExtension(filename2));
        parseFSMFile(filename2, fsm2);

        // print state names
        std::vector<std::string> stateNames = fsm2.getStateNames();
        std::cout << "States in " << filename2 << ":" << std::endl;
        for (const std::string& stateName : stateNames) {
            std::cout << stateName << std::endl;
        }

        // print transitiond
        std::vector<std::string> transitions = fsm2.getTransitions();
        std::cout << "Transitions in " << filename2 << ":" << std::endl;
        for (const std::string& transition : transitions) {
            std::cout << transition << std::endl;
        }

        fsm2.start();
        //catching errros
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }
    return 0;
}

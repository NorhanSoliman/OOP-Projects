#ifndef UTILS_H
#define UTILS_H

#include <string>

// Function to strip the .fsm extension
inline std::string stripFSMExtension(const std::string& filename) {
    size_t lastdot = filename.find_last_of(".");
    if (lastdot == std::string::npos) return filename;
    return filename.substr(0, lastdot);
}

#endif // UTILS_H

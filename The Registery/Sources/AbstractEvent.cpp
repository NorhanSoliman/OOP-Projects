#include "AbstractEvent.h"

// Constructor
AbstractEvent::AbstractEvent(const std::string& description, const time_t& startTime, const time_t& endTime)
    : m_description(description), m_startTime(startTime), m_endTime(endTime) {}

// Getter methods
std::string AbstractEvent::getDescription() const {
    return m_description;
}

time_t AbstractEvent::getStartTime() const {
    return m_startTime;
}

time_t AbstractEvent::getEndTime() const {
    return m_endTime;
}

// Setter methods
void AbstractEvent::setDescription(const std::string& description) {
    m_description = description;
}

void AbstractEvent::setStartTime(const time_t& startTime) {
    m_startTime = startTime;
}

void AbstractEvent::setEndTime(const time_t& endTime) {
    m_endTime = endTime;
}

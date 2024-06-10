#include "WeeklyEvent.h"

#include <iostream>

//constructor
WeeklyEvent::WeeklyEvent(const std::string& description, const time_t& startTime, const time_t& endTime, const time_t& limitDate)
    : AbstractEvent(description, startTime, endTime), m_limitDate(limitDate), m_currentOccurrence(startTime) {}

//getter and setter for limit date
time_t WeeklyEvent::getLimitDate() const {
    return m_limitDate;
}

void WeeklyEvent::setLimitDate(const time_t& limitDate) {
    m_limitDate = limitDate;
}

// Overridden methods
bool WeeklyEvent::hasMoreOccurrences() const {
    return m_currentOccurrence < m_limitDate;
}

time_t WeeklyEvent::nextOccurrence() const {
    if (m_currentOccurrence >= m_limitDate) {
        // Behavior is undefined if called beyond limit date
        std::cerr << "Cannot call nextOccurrence() beyond limit date." << std::endl;
        return m_endTime; // Return end time as an indication of end of recurrences
    }
    time_t nextTime = m_currentOccurrence + 604800; // 604800 seconds in a week (7 days * 24 hours * 60 minutes * 60 seconds)
    m_currentOccurrence = nextTime;
    return nextTime;
}

void WeeklyEvent::init() const {
    m_currentOccurrence = m_startTime; //To reset current occurrence
}

time_t WeeklyEvent::lastOccurrence() const {
    return m_startTime + ((m_limitDate - m_startTime) / 604800) * 604800; // Find the last occurrence before limit date
}

bool WeeklyEvent::hasRecurrenceOn(const time_t& date) const {
    // A weekly event has recurrence on the same day of the week as the start time
    // and the date is before the limit date
    return (date - m_startTime) % 604800 == 0 && date < m_limitDate;

    //return (date - m_startTime) % 604800 == 0;
    //return date < m_limitDate;

}


std::string WeeklyEvent::toString() const {
    std::string result = "Weekly Event: " + m_description + "\n";
    char startTimeBuffer[26];
    char endTimeBuffer[26];
    char limitDateBuffer[26];
    ctime_s(startTimeBuffer, sizeof(startTimeBuffer), &m_startTime);
    ctime_s(endTimeBuffer, sizeof(endTimeBuffer), &m_endTime);
    ctime_s(limitDateBuffer, sizeof(limitDateBuffer), &m_limitDate);
    result += "Start Time: " + std::string(startTimeBuffer);
    result += "End Time: " + std::string(endTimeBuffer);
    result += "Limit Date: " + std::string(limitDateBuffer);
    return result;
}


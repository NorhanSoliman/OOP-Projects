#include "DailyEvent.h"

#include <iostream>

//constructor
DailyEvent::DailyEvent(const std::string& description, const time_t& startTime, const time_t& endTime, int recurrences)
    : AbstractEvent(description, startTime, endTime), m_recurrences(recurrences), m_currentOccurrence(0) {}

//getter and setters for recurrences
int DailyEvent::getRecurrences() const {
    return m_recurrences;
}

void DailyEvent::setRecurrences(int recurrences) {
    m_recurrences = recurrences;
}

// Overridden methods
bool DailyEvent::hasMoreOccurrences() const {
    return m_currentOccurrence < m_recurrences; //valid case
}

time_t DailyEvent::nextOccurrence() const {
    if (m_currentOccurrence >= m_recurrences) { //invalid case
        //if called more times than recurrences
        std::cerr << "Cannot call nextOccurrence() more than recurrences." << std::endl;
        return m_endTime; //return end time as an indication of end of recurrences
    }
    time_t nextTime = m_startTime + (m_currentOccurrence * 86400); //86400 seconds in a day for a dailyevent
    ++m_currentOccurrence;
    return nextTime;
}

void DailyEvent::init() const {
    m_currentOccurrence = 0; //reset current occurrence
}

time_t DailyEvent::lastOccurrence() const {
    return m_startTime + ((m_recurrences - 1) * 86400);
}

bool DailyEvent::hasRecurrenceOn(const time_t& date) const {
    // Check if the specified date falls between the start and end times (inclusive)
    return (date >= m_startTime );
    //return (date >= m_startTime && date <= m_endTime);
}



std::string DailyEvent::toString() const {
    std::string result = "Daily Event: " + m_description + "\n";
    char startTimeBuffer[26]; //26 characters for the time format
    char endTimeBuffer[26];
    ctime_s(startTimeBuffer, sizeof(startTimeBuffer), &m_startTime);
    ctime_s(endTimeBuffer, sizeof(endTimeBuffer), &m_endTime);
    result += "Start Time: " + std::string(startTimeBuffer);
    result += "End Time: " + std::string(endTimeBuffer);
    result += "Recurrences: " + std::to_string(m_recurrences);
    return result;
}

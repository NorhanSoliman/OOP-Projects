#ifndef WEEKLY_EVENT_H
#define WEEKLY_EVENT_H

#include "AbstractEvent.h"

class WeeklyEvent : public AbstractEvent {
public:
    //constructor
    WeeklyEvent(const std::string& description, const time_t& startTime, const time_t& endTime, const time_t& limitDate);

    //getter and setter for limit date
    time_t getLimitDate() const;
    void setLimitDate(const time_t& limitDate);

    // Overridden methods
    bool hasMoreOccurrences() const override;
    time_t nextOccurrence() const override;
    void init() const override;
    time_t lastOccurrence() const override;
    bool hasRecurrenceOn(const time_t& date) const override;
    std::string toString() const override;

private:
    time_t m_limitDate;
    mutable time_t m_currentOccurrence; // For tracking current occurrence
};

#endif // WEEKLY_EVENT_H

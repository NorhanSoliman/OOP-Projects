#ifndef DAILY_EVENT_H
#define DAILY_EVENT_H

#include "AbstractEvent.h"

class DailyEvent : public AbstractEvent {
public:
    //constructor
    DailyEvent(const std::string& description, const time_t& startTime, const time_t& endTime, int recurrences);

    //getter and setters for recurrences
    int getRecurrences() const;
    void setRecurrences(int recurrences);

    // Overridden methods
    bool hasMoreOccurrences() const override;
    time_t nextOccurrence() const override;
    void init() const override;
    time_t lastOccurrence() const override;
    bool hasRecurrenceOn(const time_t& date) const override;
    std::string toString() const override;

private:
    int m_recurrences;
    mutable int m_currentOccurrence; //for tracking current occurrence  
                                    //and mutable to modify within a const function
};

#endif // DAILY_EVENT_H

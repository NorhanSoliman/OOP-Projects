#ifndef ABSTRACT_EVENT_H
#define ABSTRACT_EVENT_H

#include <string>
#include <ctime>

class AbstractEvent {
public:
    //constructor
    AbstractEvent(const std::string& description, const time_t& startTime, const time_t& endTime);

    //destructor
    virtual ~AbstractEvent() = default;

    //Getters
    std::string getDescription() const;
    time_t getStartTime() const;
    time_t getEndTime() const;

    // Setters
    void setDescription(const std::string& description);
    void setStartTime(const time_t& startTime);
    void setEndTime(const time_t& endTime);

    // virtual methods 
    virtual bool hasMoreOccurrences() const = 0;
    virtual time_t nextOccurrence() const = 0;
    virtual void init() const = 0;
    virtual time_t lastOccurrence() const = 0;
    virtual bool hasRecurrenceOn(const time_t& date) const = 0;
    virtual std::string toString() const = 0;

protected:
    std::string m_description;
    time_t m_startTime;
    time_t m_endTime;
};

#endif // ABSTRACT_EVENT_H

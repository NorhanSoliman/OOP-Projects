#include "Planner.h"
#include <algorithm>
#include <iostream>

//Constructor
Planner::Planner(int capacity) : capacity(capacity) {}

//returns the number of events in the planner
int Planner::size() const {
    return events.size();
}

//adds an event to the planner
bool Planner::addEvent(AbstractEvent* event) {
    if (events.size() < capacity) {
        events.push_back(event);
        return true;
    }
    return false;
}

//returns the event at the specified position
AbstractEvent* Planner::eventAt(int pos) const {
    if (pos >= 0 && pos < events.size()) {
        return events[pos];
    }
    return nullptr;
}

//removes the event at the specified position
AbstractEvent* Planner::remove(int pos) {
    if (pos >= 0 && pos < events.size()) {
        AbstractEvent* removedEvent = events[pos];
        events.erase(events.begin() + pos);
        return removedEvent;
    }
    return nullptr;
}

void Planner::display(time_t date) const {
    //    for (AbstractEvent* event : events) {
    //        if (event->hasRecurrenceOn(date)) {
    //            std::cout << event->toString() << std::endl;
    //        }
    //    }
    bool found = false; //flag to indicate if any event is found on the specified date
    for (const AbstractEvent* event : events) {
        if (event->hasRecurrenceOn(date)) {
            std::cout << event->toString() << std::endl;
            found = true; // Set the flag to true since at least one event is found
        }
    }

    //if no events are found on the specified date and inform the user
    if (!found) {
        std::cout << "No events found on the specified date." << std::endl;
    }
}

// sorts events using given comparator
void Planner::sort(const Comparator& comp) {
    std::sort(events.begin(), events.end(), [&comp](AbstractEvent* e1, AbstractEvent* e2) {
        return comp.compare(*e1, *e2);
        });
}

//returns string representation of events
std::string Planner::toString() const {
    std::string result;
    for (AbstractEvent* event : events) {
        result += event->toString() + "\n";
    }
    return result;
}

// Destructor that deallocates dynamic memory
Planner::~Planner() {
    for (AbstractEvent* event : events) {
        delete event;
    }
}

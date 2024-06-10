#ifndef PLANNER_H
#define PLANNER_H

#include <vector>
#include "AbstractEvent.h"
#include "Comparator.h"

class Planner {
public:
    // Constructor
    Planner(int capacity);

    // Instance methods
    int size() const;
    bool addEvent(AbstractEvent* event);
    AbstractEvent* eventAt(int pos) const;
    AbstractEvent* remove(int pos);
    void display(time_t date) const;
    void sort(const Comparator& comp);
    std::string toString() const;
    ~Planner();

private:
    std::vector<AbstractEvent*> events;
    int capacity;
};

#endif // PLANNER_H

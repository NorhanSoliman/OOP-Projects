#include <iostream>
#include "Planner.h"
#include "Utilis.h"
#include "WeeklyEvent.h"
#include "DailyEvent.h"
#include "FirstOccComparator.h"
#include "LastOccComparator.h"
#include "DescriptionComparator.h"

using namespace std;

int main() {
    Planner p(20);
    time_t input, start, end, limit;
    limit = Utilis::createTime(2023, 5, 25);
    start = Utilis::createTime(2023, 1, 3, 21, 10);
    end = Utilis::createTime(2023, 1, 3, 22, 30);
    p.addEvent(new WeeklyEvent("Shopping Time", start, end, limit));

    start = Utilis::createTime(2023, 3, 23, 18, 0);
    end = Utilis::createTime(2023, 3, 23, 19, 0);
    p.addEvent(new DailyEvent("Breakfast time", start, end, 10));

    start = Utilis::createTime(2023, 2, 5, 15, 30);
    end = Utilis::createTime(2023, 2, 5, 16, 45);
    p.addEvent(new WeeklyEvent("OOD SUN Lecture", start, end, limit));


    start = Utilis::createTime(2023, 1, 11, 10, 0);
    end = Utilis::createTime(2023, 1, 11, 11, 30);
    p.addEvent(new WeeklyEvent("CSCE 1521 Section B", start, end, limit));

    start = Utilis::createTime(2023, 2, 1, 15, 30);
    end = Utilis::createTime(2023, 2, 1, 16, 45);
    p.addEvent(new WeeklyEvent("OOD WED Lecture", start, end, limit));

    start = Utilis::createTime(2023, 1, 10, 11, 30);
    end = Utilis::createTime(2023, 1, 10, 13, 0);
    p.addEvent(new WeeklyEvent("CSCE 1521 Section A", start, end, limit));

    start = Utilis::createTime(2023, 1, 11, 14, 30);
    end = Utilis::createTime(2023, 1, 11, 17, 30);
    p.addEvent(new WeeklyEvent("CSCE 4321 Section A", start, end, limit));

    start = Utilis::createTime(2023, 2, 14, 14, 30);
    end = Utilis::createTime(2023, 2, 14, 17, 0);
    p.addEvent(new WeeklyEvent("TA Office Hours", start, end, limit));

    start = Utilis::createTime(2023, 4, 11, 9, 30);
    end = Utilis::createTime(2023, 4, 11, 17, 30);
    p.addEvent(new DailyEvent("Examination", start, end, 18));

    cout << "############################################################" << endl;
    // Display recurrences of "OOD SUN Lecture" 
    cout << "Recurrences of OOD SUN Lecture:" << endl;
    //code here
    
   // Get the event index for "OOD SUN Lecture"
    int eventIndex = -1;
    for (int i = 0; i < p.size(); ++i) {
        AbstractEvent* event = p.eventAt(i);
        if (event != nullptr && event->getDescription() == "OOD SUN Lecture") {
            eventIndex = i;
            break;
        }
    }

    if (eventIndex != -1) {
        // Display the recurrences
        AbstractEvent* event = p.eventAt(eventIndex);
        if (event != nullptr) {
            WeeklyEvent* weeklyEvent = dynamic_cast<WeeklyEvent*>(event);
            if (weeklyEvent != nullptr) {
                while (weeklyEvent->hasMoreOccurrences()) {
                    time_t nextStartTime = weeklyEvent->nextOccurrence();
                    if (nextStartTime <= limit) {
                        std::cout << Utilis::timeToString(nextStartTime) << std::endl;
                    }
                    else {
                        break; // Stop if the next occurrence is after the limit date
                    }
                }
            }
            else {
                std::cout << "Event is not a WeeklyEvent!" << std::endl;
            }
        }
    }
    else {
        std::cout << "Event not found!" << std::endl;
    }
    //p.display(Utilis::createTime(2023, 2, 5));
    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    // Display recurrences of "Breakfast time"
    cout << "Recurrences of Breakfast time:" << endl;
    //code here

    // Get the event index for "Breakfast time"
        int Index = -1;
        for (int i = 0; i < p.size(); ++i) {
            AbstractEvent* event = p.eventAt(i);
            if (event != nullptr && event->getDescription() == "Breakfast time") {
                Index = i;
                break;
            }
        }

        if (Index != -1) {
            // Display the recurrences
            AbstractEvent* event = p.eventAt(Index);
            if (event != nullptr) {
                DailyEvent* dailyEvent = dynamic_cast<DailyEvent*>(event);
                if (dailyEvent != nullptr) {
                    int recurrenceCount = 0;
                    while (recurrenceCount < 10 && dailyEvent->hasMoreOccurrences()) {
                        time_t nextStartTime = dailyEvent->nextOccurrence();
                        std::cout << Utilis::timeToString(nextStartTime) << std::endl;
                        ++recurrenceCount;
                    }
                }
                else {
                    std::cout << "Event is not a DailyEvent!" << std::endl;
                }
            }
        }
        else {
            std::cout << "Event not found!" << std::endl;
        }
    //p.display(Utilis::createTime(2023, 3, 23));
    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    // Display the start time of last occurrence of all the events
    cout << "The start time of last occurrence of all the events:" << endl;
    //code here //different format
    for (int i = 0; i < p.size(); ++i) {
        AbstractEvent* event = p.eventAt(i);
        if (event != nullptr) {
            std::cout << "Event: " << event->getDescription() << " Last occurrence: ";
            std::cout << Utilis::timeToString(event->lastOccurrence()) << std::endl;
        }
    }
    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    // Display events that have a recurrence on March 28, 2023
    cout << "Events that have a recurrence on March 28, 2023:" << endl;
    //time_t time1 = Utilis::createTime(2023, 1, 1, 12, 0);
    //time_t time1 = Utilis::createTime(2023, 3, 28); 
    //std::cout << "Time 1: " << Utilis::timeToString(time1) << std::endl;
    p.display(Utilis::createTime(2023, 3, 28)); //here
    //p.display(Utilis::createTime(2023, 2, 14, 14, 30));
    
    

    cout << "############################################################" << endl;

    // Remove and add the first event
    p.addEvent(p.remove(0));
    cout << "############################################################" << endl;

    // Display the content of the planner after removal and addition
    cout << "Content of the Planner: " << endl;
    cout << p.toString() << endl;
    cout << "############################################################" << endl;

    // Sort the content of the Planner by first occurrence
    cout << "Sorting the content of the Planner by first occurrence..." << endl;
    p.sort(FirstOccComparator());
    cout << "Content of the Planner: " << endl;
    cout << p.toString() << endl;
    cout << "############################################################" << endl;

    // Sort the content of the Planner by last occurrence
    cout << "Sorting the content of the Planner by last occurrence..." << endl;
    p.sort(LastOccComparator());
    cout << "Content of the Planner: " << endl;
    cout << p.toString() << endl;
    cout << "############################################################" << endl;

    // Sort the content of the Planner by description
    cout << "Sorting the content of the Planner by description..." << endl;
    p.sort(DescriptionComparator());
    cout << "Content of the Planner: " << endl;
    cout << p.toString() << endl;
    cout << "############################################################" << endl;
    cout << "############################################################" << endl;

    return 0;
}

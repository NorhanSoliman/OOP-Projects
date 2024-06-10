# Event Planner Application

## Overview

The Event Planner Application is a C++ program designed to manage and organize events. It allows users to create, store, and manipulate various types of events such as daily and weekly occurrences. The application provides functionality for adding, removing, displaying, and sorting events based on different criteria.

## Features

- Create daily events with a specific start and end time.
- Create weekly events with recurrences on the same day of the week.
- Set a limit date for recurring events.
- Display events occurring on a specified date.
- Sort events by various criteria such as start time, end time, and description.
- Convert time_t objects to string format.
- Create time_t objects with specified date and time parameters.

## Classes

The application consists of the following classes:

1. `AbstractEvent`: An abstract base class representing common characteristics of all events.
2. `DailyEvent`: A concrete subclass of `AbstractEvent` representing events that occur daily.
3. `WeeklyEvent`: A concrete subclass of `AbstractEvent` representing events that occur weekly.
4. `Comparator`: An abstract class for comparing events based on different criteria.
5. `DescriptionComparator`, `FirstOccComparator`, and `LastOccComparator`: Subclasses of `Comparator` for comparing events by description, first occurrence, and last occurrence respectively.
6. `Planner`: A class for managing and organizing events.

## Usage

To use the Event Planner Application:

1. Compile the source files using a C++ compiler (e.g., g++).
2. Execute the compiled program.

## Dependencies

The application depends on the C++ Standard Library and the `<ctime>` header for handling time-related operations.

## Isssues

There is an issue in retriving the events happening in a specified date.

#ifndef UTILIS_H
#define UTILIS_H

#include <ctime>
#include <string>

class Utilis {
public:
    static std::string timeToString(const time_t& time);
    static time_t createTime(int year, int month, int day, int hour = 0, int minute = 0);
};

#endif // UTILIS_H

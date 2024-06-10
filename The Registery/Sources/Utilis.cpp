#include "Utilis.h"
#include <sstream>
#include <cstring> // For memset


std::string Utilis::timeToString(const time_t& time) {
    struct tm timeinfo;
    localtime_s(&timeinfo, &time);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", &timeinfo);
    return std::string(buffer);
}

time_t Utilis::createTime(int year, int month, int day, int hour, int minute) {
    struct tm timeinfo = { 0 };
    timeinfo.tm_year = year - 1900; // Years since 1900
    timeinfo.tm_mon = month - 1;    // Months since January (0-11)
    timeinfo.tm_mday = day;         // Day of the month (1-31)
    timeinfo.tm_hour = hour;        // Hours (0-23)
    timeinfo.tm_min = minute;       // Minutes (0-59)
    timeinfo.tm_sec = 0;            // Seconds (0-60)
    timeinfo.tm_isdst = -1;         // Determine daylight saving time

    return mktime(&timeinfo);
}

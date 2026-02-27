#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>

class Schedule {
private:
    std::string day;
    std::string time;
    std::string room;

public:
    Schedule();
    Schedule(std::string day, std::string time, std::string room = "TBD");

    ~Schedule();

    void display() const;
};

#endif
#include "Schedule.h"
#include <iostream>


Schedule::Schedule() : Schedule("Monday", "08:00", "101") {}

Schedule::Schedule(std::string day, std::string time, std::string room)
    : day(day), time(time), room(room) {}

Schedule::~Schedule() {
    std::cout << "Schedule destroyed\n";
}

void Schedule::display() const {
    std::cout << "Day: " << day
              << ", Time: " << time
              << ", Room: " << room << std::endl;
}
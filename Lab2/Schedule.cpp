#include "Schedule.h"
#include <iostream>


Schedule::Schedule() : Schedule("Monday", "08:00", "101") {}


Schedule::Schedule(std::string day, std::string time, std::string room)
    : day(day), time(time), room(room), course(nullptr) {}


Schedule::Schedule(std::string day, std::string time, std::string room, Course* course)
    : day(day), time(time), room(room), course(course) {}


Schedule::~Schedule() {
    std::cout << "Schedule destroyed\n";
}


void Schedule::display() const {
    std::cout << "Day: " << day
              << ", Time: " << time
              << ", Room: " << room << std::endl;

    if (course)
        course->display();
}




ExamSchedule::ExamSchedule(std::string day, std::string time, std::string room,
                           Course* course, std::string examType)
    : Schedule(day, time, room, course), examType(examType) {}

void ExamSchedule::display() const {
    Schedule::display();
    std::cout << "Exam type: " << examType << std::endl;
}
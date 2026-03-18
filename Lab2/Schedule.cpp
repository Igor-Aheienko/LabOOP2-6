#include "Schedule.h"
#include <iostream>

Schedule::Schedule() : Schedule("Monday", "08:00", "101") {}

Schedule::Schedule(std::string day, std::string time, std::string room)
    : day(day), time(time), room(room), course(nullptr) {}

Schedule::Schedule(std::string day, std::string time, std::string room, Course* course)
    : day(day), time(time), room(room) {

    if (course)
        this->course = new Course(*course); // 🔥 deep copy
    else
        this->course = nullptr;
}

// 🔁 Copy constructor
Schedule::Schedule(const Schedule& other)
    : day(other.day), time(other.time), room(other.room) {

    if (other.course)
        course = new Course(*other.course); // 🔥 deep copy
    else
        course = nullptr;
}

// 🔁 operator=
Schedule& Schedule::operator=(const Schedule& other) {
    if (this != &other) {
        day = other.day;
        time = other.time;
        room = other.room;

        delete course; // 🔥 очистка

        if (other.course)
            course = new Course(*other.course);
        else
            course = nullptr;
    }
    return *this;
}

Schedule::~Schedule() {
    delete course; // 🔥 щоб не було витоку
    std::cout << "Schedule destroyed\n";
}

void Schedule::display() const {
    std::cout << "Day: " << day
              << ", Time: " << time
              << ", Room: " << room << std::endl;

    if (course)
        course->display();
}


// 🔥 ExamSchedule
ExamSchedule::ExamSchedule(std::string day, std::string time, std::string room,
                           Course* course, std::string examType)
    : Schedule(day, time, room, course), examType(examType) {}

void ExamSchedule::display() const {
    Schedule::display();
    std::cout << "Exam type: " << examType << std::endl;
}
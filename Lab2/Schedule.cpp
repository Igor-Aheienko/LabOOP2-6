#include "Schedule.h"
#include <iostream>

Schedule::Schedule() : Schedule("Monday", "08:00", "101") {}

Schedule::Schedule(std::string day, std::string time, std::string room)
    : day(day), time(time), room(room), course(nullptr) {}

Schedule::Schedule(std::string day, std::string time, std::string room, Course* course)
    : day(day), time(time), room(room) {

    
    this->course = course;
}

// Copy constructor
Schedule::Schedule(const Schedule& other)
    : day(other.day), time(other.time), room(other.room) {

    
    course = other.course;
}

// operator=
Schedule& Schedule::operator=(const Schedule& other) {
    if (this != &other) {
        day = other.day;
        time = other.time;
        room = other.room;

        
        course = other.course;
    }
    return *this;
}

Schedule::~Schedule() {
    //  НЕ delete course важливо
    std::cout << "Schedule destroyed\n";
}

void Schedule::display() const {
    std::cout << "Day: " << day
              << ", Time: " << time
              << ", Room: " << room << std::endl;

    if (course) {
        course->display(); //  полiк
        course->info();    //  pure virtual
    }
}

void Schedule::showDetails() const {
    std::cout << "General schedule details\n";
}

void ExamSchedule::showDetails() const {
    std::cout << "Exam type details\n";
}


//  ExamSchedule 

ExamSchedule::ExamSchedule(std::string day, std::string time, std::string room,
                           Course* course, std::string examType)
    : Schedule(day, time, room, course), examType(examType) {}

void ExamSchedule::display() const {
    std::cout << "[Exam]\n";
    Schedule::display();
    std::cout << "Exam type: " << examType << std::endl;
}
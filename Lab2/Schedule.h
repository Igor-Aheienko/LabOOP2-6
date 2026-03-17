#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include "Course.h"   

class Schedule {
private:
    std::string day;
    std::string time;
    std::string room;

    Course* course;  

public:
    Schedule();
    Schedule(std::string day, std::string time, std::string room);

   
    Schedule(std::string day, std::string time, std::string room, Course* course);

    ~Schedule();

    void display() const;
};



class ExamSchedule : public Schedule {
private:
    std::string examType; 

public:
    ExamSchedule(std::string day, std::string time, std::string room,
                 Course* course, std::string examType);

    void display() const;
};

#endif
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

    // Copy + operator=
    Schedule(const Schedule& other);
    Schedule& operator=(const Schedule& other);

    virtual ~Schedule(); 

    virtual void display() const; 

    // щоб було більше поліморфізму
    virtual void showDetails() const;
};


class ExamSchedule final : public Schedule {  
private:
    std::string examType;

public:
    ExamSchedule(std::string day, std::string time, std::string room,
                 Course* course, std::string examType);

    void display() const override;

    // new
    void showDetails() const override;
};

#endif
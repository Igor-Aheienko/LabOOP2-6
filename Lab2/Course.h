#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"

class Course {
private:
    std::string title;
    std::string teacher;
    int credits;

    Teacher* teacherObj;

public:
    Course();
    Course(std::string title, std::string teacher, int credits = 3);

    Course(std::string title, Teacher* teacherObj, int credits = 3);

    Course(const Course& other);
    Course& operator=(const Course& other);

    virtual ~Course(); // 🔥 важливо для наслідування

    virtual void display() const; // 🔥 щоб override працював
};


class OnlineCourse : public Course {
private:
    std::string platform;

public:
    OnlineCourse(std::string title, Teacher* teacherObj, int credits, std::string platform);

    void display() const override; // 🔥 override
};

#endif
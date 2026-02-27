#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    std::string title;
    std::string teacher;
    int credits;

public:
    Course();
    Course(std::string title, std::string teacher, int credits = 3);

    ~Course();

    void display() const;
};

#endif
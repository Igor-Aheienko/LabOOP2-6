#include "Course.h"
#include <iostream>
#include <utility>

// ===== Course =====

Course::Course() : Course("Unknown", "Unknown", 3) {}

Course::Course(std::string title, std::string teacher, int credits)
    : title(title), teacher(teacher), credits(credits), teacherObj(nullptr) {}

// Конструктор з об'єктом Teacher
Course::Course(std::string title, Teacher* teacherObj, int credits)
    : title(title), teacher(""), credits(credits) {

    if (teacherObj)
        this->teacherObj = new Teacher(*teacherObj); // deep copy
    else
        this->teacherObj = nullptr;
}

// COPY constructor
Course::Course(const Course& other)
    : title(other.title),
      teacher(other.teacher),
      credits(other.credits) {

    if (other.teacherObj)
        teacherObj = new Teacher(*other.teacherObj); // deep copy
    else
        teacherObj = nullptr;

    std::cout << "Course copied\n";
}

// operator=
Course& Course::operator=(const Course& other) {
    if (this != &other) {
        title = other.title;
        teacher = other.teacher;
        credits = other.credits;

        delete teacherObj;

        if (other.teacherObj)
            teacherObj = new Teacher(*other.teacherObj);
        else
            teacherObj = nullptr;
    }
    return *this;
}

// destructor
Course::~Course() {
    delete teacherObj;
    std::cout << "Course destroyed\n";
}

// display
void Course::display() const {
    std::cout << "Course: " << title
              << ", Teacher: " << teacher
              << ", Credits: " << credits << std::endl;

    if (teacherObj)
        teacherObj->display();
}


// ===== OnlineCourse =====

OnlineCourse::OnlineCourse(std::string title, Teacher* teacherObj, int credits, std::string platform)
    : Course(title, teacherObj, credits), platform(platform) {}

// override display
void OnlineCourse::display() const {
    std::cout << "[Online Course]\n";
    Course::display();
    std::cout << "Platform: " << platform << std::endl;
}

//  FIX — додали const
void OnlineCourse::info() const {
    std::cout << "This is an online course on platform: " << platform << std::endl;
}
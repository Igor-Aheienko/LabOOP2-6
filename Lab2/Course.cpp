#include "Course.h"
#include <iostream>

Course::Course() : Course("Unknown", "Unknown", 3) {}

Course::Course(std::string title, std::string teacher, int credits)
    : title(title), teacher(teacher), credits(credits), teacherObj(nullptr) {} // 🔥 додали teacherObj

// 🔥 НОВИЙ конструктор
Course::Course(std::string title, Teacher* teacherObj, int credits)
    : title(title), teacher(""), credits(credits), teacherObj(teacherObj) {}

// 🔁 COPY constructor
Course::Course(const Course& other)
    : title(other.title),
      teacher(other.teacher),
      credits(other.credits),
      teacherObj(other.teacherObj) {
    std::cout << "Course copied\n";
}

// 🔁 operator=
Course& Course::operator=(const Course& other) {
    if (this != &other) {
        title = other.title;
        teacher = other.teacher;
        credits = other.credits;
        teacherObj = other.teacherObj;
    }
    return *this;
}

Course::~Course() {
    std::cout << "Course destroyed\n";
}

// 🔥 РОЗШИРЕНИЙ display (старе НЕ чіпаємо)
void Course::display() const {
    std::cout << "Course: " << title
              << ", Teacher: " << teacher
              << ", Credits: " << credits << std::endl;

    if (teacherObj)
        teacherObj->display(); // 🔥 нове
}


// 🔥 OnlineCourse
OnlineCourse::OnlineCourse(std::string title, Teacher* teacherObj, int credits, std::string platform)
    : Course(title, teacherObj, credits), platform(platform) {}

void OnlineCourse::display() const {
    Course::display();
    std::cout << "Platform: " << platform << std::endl;
}
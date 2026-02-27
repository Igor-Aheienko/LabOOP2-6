#include "Course.h"
#include <iostream>


Course::Course() : Course("Unknown", "Unknown", 3) {}

Course::Course(std::string title, std::string teacher, int credits)
    : title(title), teacher(teacher), credits(credits) {}

Course::~Course() {
    std::cout << "Course destroyed\n";
}

void Course::display() const {
    std::cout << "Course: " << title
              << ", Teacher: " << teacher
              << ", Credits: " << credits << std::endl;
}
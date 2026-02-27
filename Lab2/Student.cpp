#include "Student.h"
#include <iostream>


Student::Student() : Student("Unknown", 18, 1) {}

Student::Student(std::string name, int age, int year)
    : name(name), age(age), year(year) {}

Student::~Student() {
    std::cout << "Student destroyed\n";
}

void Student::display() const {
    std::cout << "Name: " << name
              << ", Age: " << age
              << ", Year: " << year << std::endl;
}


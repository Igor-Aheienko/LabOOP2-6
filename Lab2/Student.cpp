#include "Student.h"
#include <iostream>

int Student::studentCount = 0;


Student::Student() : Student("Unknown", 18, 1) {}


Student::Student(std::string name, int age, int year)
    : Person(name), age(age), year(year) {
    studentCount++;
}


Student::Student(const Student& other)
    : Person(other.name), age(other.age), year(other.year) {
    std::cout << "Student copied\n";
}


Student::Student(Student&& other)
    : Person(std::move(other.name)), age(other.age), year(other.year) {
    std::cout << "Student moved\n";
}


Student::~Student() {
    std::cout << "Student destroyed\n";
}


void Student::display() const {
    std::cout << "Name: " << name
              << ", Age: " << age
              << ", Year: " << year << std::endl;
}


void Student::setAge(int age) {
    this->age = age;
}


int Student::getCount() {
    return studentCount;
}


Student Student::operator+(const Student& other) {
    return Student(name + "&" + other.name, age, year);
}


std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.name << " " << s.age << " " << s.year;
    return os;
}


std::istream& operator>>(std::istream& is, Student& s) {
    is >> s.name >> s.age >> s.year;
    return is;
}
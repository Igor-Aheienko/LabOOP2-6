#include "Student.h"
#include <iostream>
#include <utility> // для std::move

int Student::studentCount = 0;

Student::Student() : Student("Unknown", 18, 1) {}

Student::Student(std::string name, int age, int year)
    : Person(name), age(age), year(year) {
    studentCount++;
}

// Copy constructor
Student::Student(const Student& other)
    : Person(other), age(other.age), year(other.year) {
    std::cout << "Student copied\n";
}

// Move constructor
Student::Student(Student&& other) noexcept
    : Person(std::move(other)), age(other.age), year(other.year) {
    std::cout << "Student moved\n";
}

// 🔥 Operator =
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Person::operator=(other); // копіюємо базовий клас
        age = other.age;
        year = other.year;
    }
    return *this;
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
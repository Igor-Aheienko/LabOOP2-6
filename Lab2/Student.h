#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

//  новий інтерфейс
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() {}
};

class Person {
protected:
    std::string name;

public:
    Person() {}
    Person(std::string name) : name(name) {}

    virtual ~Person() {}

    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
    }
};

class Teacher {
private:
    std::string name;
    std::string subject;

public:
    Teacher(std::string name = "Unknown", std::string subject = "Unknown")
        : name(name), subject(subject) {}

    void display() const {
        std::cout << "Teacher: " << name
                  << ", Subject: " << subject << std::endl;
    }
};

class Student : public Person, public Printable { //  новий інтерфейс
private:
    int age;
    int year;

    static int studentCount;

public:
    Student();
    Student(std::string name, int age, int year = 1);

    // Copy / Move
    Student(const Student& other);
    Student(Student&& other) noexcept;

    // Operator
    Student& operator=(const Student& other);

    ~Student();

    void display() const override;

    void setAge(int age);

    static int getCount();

    Student operator+(const Student& other);

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);

    //  нове реалізація інтерфейсу
    void print() const override;
};

#endif
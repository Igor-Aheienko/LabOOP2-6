#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>


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


class Student : public Person {
private:
    int age;
    int year;

    static int studentCount;

public:
    Student();
    Student(std::string name, int age, int year = 1);

    Student(const Student& other);   
    Student(Student&& other);        

    ~Student();

    void display() const;

    void setAge(int age);  

    static int getCount();  

    Student operator+(const Student& other);   

    
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);
};

#endif
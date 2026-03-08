#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int age;
    int year;

    static int studentCount;   // static поле

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
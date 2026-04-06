#include "Student.h"
#include "Course.h"
#include "Schedule.h"
#include <iostream>

//  полiк через reference
void showCourse(const Course& c) {
    c.display();
    c.info();
}

int main() {

    // ===== STUDENTS =====
    Student s1("Ivan", 18, 1);
    Student s2("Petro", 19, 2);

    std::cout << "Students:\n";
    std::cout << "\nTotal students: " << Student::getCount() << std::endl;
    s1.display();
    s2.display();

    Student s3 = s1 + s2;
    std::cout << "\nCombined student:\n";
    s3.display();

    //  interface
    Printable* p = &s1;
    std::cout << "\nInterface (Printable):\n";
    p->print();


    // TEACHER 
    Teacher t1("Dr.Smith", "Math");


    // COURSES  не створюємо Course напряму
    OnlineCourse c1("Algebra", &t1, 3, "Local");
    OnlineCourse c2("Physics", &t1, 4, "Offline");

    std::cout << "\nCourses:\n";
    c1.display();
    c2.display();


    //  ONLINE COURSE 
    OnlineCourse oc1("C++", &t1, 5, "Udemy");

    std::cout << "\nOnline course:\n";
    oc1.display();


    //  POINTER POLYMORPHISM
    Course* ptr = &oc1;
    std::cout << "\nPointer polymorphism:\n";
    ptr->display();
    ptr->info();


    //  REFERENCE POLYMORPHISM
    std::cout << "\nReference polymorphism:\n";
    showCourse(oc1);


    // SCHEDULE
    Schedule sch1("Monday", "10:00", "101", &c2);

    std::cout << "\nSchedule:\n";
    sch1.display();


    //  EXAM SCHEDULE
    ExamSchedule ex1("Friday", "12:00", "202", &c2, "Final");

    std::cout << "\nExam schedule:\n";
    ex1.display();


    //  polymorphism Schedule - ExamSchedule
    Schedule* schPtr = &ex1;
    std::cout << "\nSchedule polymorphism:\n";
    schPtr->display();


    return 0;
}
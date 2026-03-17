#include "Student.h"
#include "Course.h"
#include "Schedule.h"


int main() {

    Student s1;
    Student s2("Igor", 19, 2);

    Course c1;
    Course c2("Programming", "Dr. Smith", 5);

    Schedule sch1;
    Schedule sch2("Tuesday", "10:00", "202");

    Student s3 = s2;          
    Student s4 = std::move(s3); 
    Student s5 = s1 + s2;
    std::cout << Student::getCount() << std::endl;

    Teacher t1("Ivan", "Math");

    Course c1("Algebra", "OldTeacher", 3);   // старий варіант
    Course c2("Physics", &t1, 4);            // новий варіант

    OnlineCourse c3("C++", &t1, 5, "Udemy");

    s1.display();
    s2.display();

    c1.display();
    c2.display();

    sch1.display();
    sch2.display();

    return 0;
}
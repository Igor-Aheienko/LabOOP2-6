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

    s1.display();
    s2.display();

    c1.display();
    c2.display();

    sch1.display();
    sch2.display();

    return 0;
}
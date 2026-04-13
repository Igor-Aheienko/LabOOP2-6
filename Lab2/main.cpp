#include <iostream>
#include <vector>
#include <fstream>
#include "HistoryLogger.h"

using namespace std;

vector<string> courses;
vector<string> users;
string currentUser = "guest";

// ================== FILE COURSES ==================
void saveCourses() {
    ofstream file("courses.txt");
    for (auto& c : courses) file << c << endl;
    file.close();
}

void loadCourses() {
    courses.clear();
    ifstream file("courses.txt");
    string line;
    while (getline(file, line)) courses.push_back(line);
    file.close();
}

// ================== FILE USERS ==================
void saveUsers() {
    ofstream file("users.txt");
    for (auto& u : users) file << u << endl;
    file.close();
}

void loadUsers() {
    users.clear();
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) users.push_back(line);
    file.close();
}

// ================== ADMIN ==================
bool isAdmin() {
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    return password == "1234";
}

void addCourse() {
    string name;
    cout << "Enter course name: ";
    cin >> name;

    courses.push_back(name);
    saveCourses();

    HistoryLogger logger;
    logger.log("admin", "added course: " + name);

    cout << "Course added!\n";
}

void addUser() {
    string name;
    cout << "Enter username: ";
    cin >> name;

    users.push_back(name);
    saveUsers();

    HistoryLogger logger;
    logger.log("admin", "added user: " + name);

    cout << "User added!\n";
}

// ================== DELETE ==================
void deleteCourse() {
    loadCourses();

    if (courses.empty()) {
        cout << "No courses to delete!\n";
        return;
    }

    cout << "\nCourses:\n";
    for (int i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << courses[i] << endl;
    }

    int choice;
    cout << "Enter course number to delete: ";
    cin >> choice;

    if (choice > 0 && choice <= courses.size()) {
        string deleted = courses[choice - 1];
        courses.erase(courses.begin() + choice - 1);
        saveCourses();

        HistoryLogger logger;
        logger.log("admin", "deleted course: " + deleted);

        cout << "Course deleted!\n";
    } else {
        cout << "Invalid choice!\n";
    }
}

void deleteUser() {
    loadUsers();

    if (users.empty()) {
        cout << "No users to delete!\n";
        return;
    }

    cout << "\nUsers:\n";
    for (int i = 0; i < users.size(); i++) {
        cout << i + 1 << ". " << users[i] << endl;
    }

    int choice;
    cout << "Enter user number to delete: ";
    cin >> choice;

    if (choice > 0 && choice <= users.size()) {
        string deleted = users[choice - 1];
        users.erase(users.begin() + choice - 1);
        saveUsers();

        HistoryLogger logger;
        logger.log("admin", "deleted user: " + deleted);

        cout << "User deleted!\n";
    } else {
        cout << "Invalid choice!\n";
    }
}

// ================== VIEW ==================
void showCourses() {
    loadCourses();

    if (courses.empty()) {
        cout << "No courses available!\n";
        return;
    }

    cout << "\nCourses:\n";
    for (int i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << courses[i] << endl;
    }
}

void showUsers() {
    loadUsers();

    if (users.empty()) {
        cout << "No users available!\n";
        return;
    }

    cout << "\nUsers:\n";
    for (int i = 0; i < users.size(); i++) {
        cout << i + 1 << ". " << users[i] << endl;
    }
}

// ================== LOGIN ==================
void selectUser() {
    loadUsers();

    if (users.empty()) {
        cout << "No users! Ask admin to create.\n";
        currentUser = "guest";
        return;
    }

    cout << "\nUsers:\n";
    for (int i = 0; i < users.size(); i++) {
        cout << i + 1 << ". " << users[i] << endl;
    }

    int choice;
    cout << "Choose user: ";
    cin >> choice;

    if (choice > 0 && choice <= users.size()) {
        currentUser = users[choice - 1];
        cout << "Logged as: " << currentUser << endl;
    } else {
        cout << "Invalid choice!\n";
        currentUser = "guest";
    }
}

// ================== MENUS ==================
void adminMenu() {
    if (!isAdmin()) {
        cout << "Wrong password!\n";
        return;
    }

    loadCourses();
    loadUsers();

    int choice;

    do {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Add course\n";
        cout << "2. Add user\n";
        cout << "3. Show courses\n";
        cout << "4. Show users\n";
        cout << "5. Delete course\n";
        cout << "6. Delete user\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        try {
            if (cin.fail()) throw 1;

            switch (choice) {
                case 1: addCourse(); break;
                case 2: addUser(); break;
                case 3: showCourses(); break;
                case 4: showUsers(); break;
                case 5: deleteCourse(); break;
                case 6: deleteUser(); break;
            }

        } catch (...) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (choice != 0);
}

void userMenu() {
    selectUser();

    int choice;

    do {
        cout << "\n=== USER MENU ===\n";
        cout << "1. Show courses\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        try {
            if (cin.fail()) throw 1;

            if (choice == 1) {
                showCourses();

                HistoryLogger logger;
                logger.log(currentUser, "viewed courses");
            }

        } catch (...) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (choice != 0);
}

// ================== MAIN ==================
int main() {
    int choice;

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        try {
            if (cin.fail()) throw 1;

            switch (choice) {
                case 1: adminMenu(); break;
                case 2: userMenu(); break;
            }

        } catch (...) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (choice != 0);

    return 0;
}
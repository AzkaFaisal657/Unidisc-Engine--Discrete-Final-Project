//
//#include "UniversitySystem.h"
//#include "SetOperations.h"
//#include "Relations.h"
//#include "Combinations.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//void loadSampleData(UniversitySystem& system) {
//    // Semester 1 courses
//    system.addCourse(new Course("NS1001", "Applied Physics", 3, "Core", 1));
//    system.addCourse(new Course("MT1003", "Calculus and Analytical Geometry", 3, "Core", 1));
//    system.addCourse(new Course("SS1012", "Functional English", 2, "Core", 1));
//    system.addCourse(new Course("CS1002", "Programming Fundamentals", 3, "Core", 1));
//
//    // Semester 2 courses
//    system.addCourse(new Course("EE1005", "Digital Logic Design", 3, "Core", 2));
//    system.addCourse(new Course("MT1008", "Multivariable Calculus", 3, "Core", 2));
//    system.addCourse(new Course("CS1004", "Object Oriented Programming", 3, "Core", 2));
//
//    // Semester 3 courses
//    system.addCourse(new Course("EE2003", "Computer Organization and Assembly Language", 3, "Core", 3));
//    system.addCourse(new Course("CS2001", "Data Structures", 3, "Core", 3));
//    system.addCourse(new Course("CS1005", "Discrete Structures", 3, "Core", 3));
//    system.addCourse(new Course("SE1001", "Introduction to Software Engineering", 3, "Core", 3));
//    system.addCourse(new Course("MT1004", "Linear Algebra", 3, "Core", 3));
//
//    // Semester 4 courses
//    system.addCourse(new Course("CS2005", "Database Systems", 3, "Core", 4));
//    system.addCourse(new Course("CS2006", "Operating Systems", 3, "Core", 4));
//    system.addCourse(new Course("MT2005", "Probability and Statistics", 3, "Core", 4));
//    system.addCourse(new Course("SE2004", "Software Design and Architecture", 3, "Core", 4));
//    system.addCourse(new Course("SE2001", "Software Requirements Engineering", 3, "Core", 4));
//
//    // Semester 5 courses
//    system.addCourse(new Course("AI2002", "Artificial Intelligence", 3, "Core", 5));
//    system.addCourse(new Course("CS2009", "Design and Analysis of Algorithms", 3, "Core", 5));
//    system.addCourse(new Course("SE3004", "Software Construction and Development", 2, "Core", 5));
//    system.addCourse(new Course("SE3002", "Software Quality Engineering", 3, "Core", 5));
//
//    // Semester 6 courses
//    system.addCourse(new Course("CS3001", "Computer Networks", 3, "Core", 6));
//    system.addCourse(new Course("CS3006", "Parallel and Distributed Computing", 3, "Core", 6));
//    system.addCourse(new Course("SE4002", "Fundamentals of Software Project Management", 3, "Core", 6));
//
//    // Semester 7 courses
//    system.addCourse(new Course("SE4091", "Final Year Project I", 3, "Core", 7));
//    system.addCourse(new Course("MG4011", "Entrepreneurship", 3, "Core", 7));
//
//    // Semester 8 courses
//    system.addCourse(new Course("SE4092", "Final Year Project II", 3, "Core", 8));
//    system.addCourse(new Course("CS3002", "Information Security", 3, "Core", 8));
//    system.addCourse(new Course("CS4001", "Professional Practices in IT", 3, "Core", 8));
//
//    // Initialize prerequisites
//    system.initializePrerequisites();
//
//    // Add sample student
//    Student* student1 = new Student("22K-0001", "Ali Ahmed", 3);
//    student1->completeCourse("CS1002");
//    student1->completeCourse("MT1003");
//    student1->completeCourse("CS1004");
//    student1->completeCourse("MT1008");
//    student1->completeCourse("EE1005");
//    system.addStudent(student1);
//
//    // Add faculty
//    system.addFaculty(new Faculty("F001", "Dr. Qamar uz Zaman", "Assistant Professor"));
//    system.addFaculty(new Faculty("F002", "Dr. Affan Rauf", "Assistant Professor"));
//    system.addFaculty(new Faculty("F003", "Ms. Anmol Bilal", "Lecturer"));
//}
//
//void printLine() {
//    cout << string(80, '=') << endl;
//}
//
//void displayMenu() {
//    printLine();
//    cout << "         FAST UNIVERSITY - COURSE MANAGEMENT SYSTEM" << endl;
//    printLine();
//    cout << "1. View Courses by Semester" << endl;
//    cout << "2. View Student Information" << endl;
//    cout << "3. Check Course Prerequisites" << endl;
//    cout << "4. Check Enrollment Eligibility" << endl;
//    cout << "5. Enroll in Course" << endl;
//    cout << "6. Verify Prerequisite Chain (Induction Module)" << endl;
//    cout << "7. Set Operations Demo (Module 5)" << endl;
//    cout << "8. Relations Demo (Module 6)" << endl;
//    cout << "9. Display System Info" << endl;
//    cout << "0. Exit" << endl;
//    printLine();
//}
//
//void viewCoursesBySemester(UniversitySystem& system) {
//    int semester;
//    cout << "\nEnter semester number (1-8): ";
//    cin >> semester;
//
//    if (semester < 1 || semester > 8) {
//        cout << "Invalid semester!" << endl;
//        return;
//    }
//
//    cout << "\n=== Semester " << semester << " Courses ===" << endl;
//    int count = 0;
//    for (int i = 0; i < system.getCourseCount(); i++) {
//        Course* course = system.getCourseByIndex(i);
//        if (course && course->getSemester() == semester) {
//            course->display();
//            count++;
//        }
//    }
//
//    if (count == 0) {
//        cout << "No courses found for this semester." << endl;
//    }
//}
//
//void viewStudentInfo(UniversitySystem& system) {
//    Student* student = system.getStudent("22K-0001");
//    if (student) {
//        cout << "\n";
//        student->display();
//
//        cout << "\nCompleted Courses:" << endl;
//        for (int i = 0; i < student->getCompletedCount(); i++) {
//            string code = student->getCompletedCourse(i);
//            Course* course = system.getCourse(code);
//            if (course) {
//                cout << "  - " << code << ": " << course->getName() << endl;
//            }
//        }
//
//        if (student->getEnrolledCount() > 0) {
//            cout << "\nCurrently Enrolled:" << endl;
//            for (int i = 0; i < student->getEnrolledCount(); i++) {
//                string code = student->getEnrolledCourse(i);
//                Course* course = system.getCourse(code);
//                if (course) {
//                    cout << "  - " << code << ": " << course->getName() << endl;
//                }
//            }
//        }
//    }
//}
//
//void checkPrerequisites(UniversitySystem& system) {
//    string courseCode;
//    cout << "\nEnter course code: ";
//    cin >> courseCode;
//
//    Course* course = system.getCourse(courseCode);
//    if (!course) {
//        cout << "Course not found!" << endl;
//        return;
//    }
//
//    system.displayAllPrerequisites(courseCode);
//}
//
//void checkEnrollmentEligibility(UniversitySystem& system) {
//    string courseCode;
//    cout << "\nEnter course code to check: ";
//    cin >> courseCode;
//
//    string reason;
//    bool canEnroll = system.canStudentEnroll("22K-0001", courseCode, reason);
//
//    cout << "\n=== Enrollment Check for " << courseCode << " ===" << endl;
//    if (canEnroll) {
//        cout << "Status: ELIGIBLE ?" << endl;
//        cout << "You can enroll in this course!" << endl;
//    }
//    else {
//        cout << "Status: NOT ELIGIBLE ?" << endl;
//        cout << "Reason: " << reason << endl;
//    }
//}
//
//void enrollInCourse(UniversitySystem& system) {
//    string courseCode;
//    cout << "\nEnter course code to enroll: ";
//    cin >> courseCode;
//
//    string errorMsg;
//    if (system.enrollStudent("22K-0001", courseCode, errorMsg)) {
//        cout << "\nSuccessfully enrolled in " << courseCode << "!" << endl;
//    }
//    else {
//        cout << "\nEnrollment failed: " << errorMsg << endl;
//    }
//}
//
//void verifyPrerequisiteChain(UniversitySystem& system) {
//    string courseCode;
//    cout << "\nEnter course code: ";
//    cin >> courseCode;
//
//    system.verifyPrerequisiteChainInduction(courseCode, "22K-0001");
//}
//
//int main() {
//    UniversitySystem system;
//    loadSampleData(system);
//
//    cout << "\n====================================================" << endl;
//    cout << "   Welcome to FAST University Management System" << endl;
//    cout << "   Demonstrating: Induction, Logic, Sets & Relations" << endl;
//    cout << "====================================================" << endl;
//
//    int choice;
//    do {
//        displayMenu();
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            viewCoursesBySemester(system);
//            break;
//        case 2:
//            viewStudentInfo(system);
//            break;
//        case 3:
//            checkPrerequisites(system);
//            break;
//        case 4:
//            checkEnrollmentEligibility(system);
//            break;
//        case 5:
//            enrollInCourse(system);
//            break;
//        case 6:
//            verifyPrerequisiteChain(system);
//            break;
//        case 7:
//            SetOperationsModule::demonstrateSetOperations();
//            break;
//        case 8:
//            RelationsModule::demonstrateRelations();
//            break;
//        case 9:
//            system.displaySystemInfo();
//            break;
//        case 0:
//            cout << "\nThank you for using the system!" << endl;
//            break;
//        default:
//            cout << "\nInvalid choice! Please try again." << endl;
//        }
//
//        if (choice != 0) {
//            cout << "\nPress Enter to continue...";
//            cin.ignore();
//            cin.get();
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}

// SFML GUI version ka main file
// Ye file GUI ke saath university system ko run karti hai

#include "GUI.h"
#include "UniversitySystem.h"
#include "FileHandler.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=====================================================" << endl;
    cout << "   FAST University Management System (GUI Mode)" << endl;
    cout << "   Discrete Mathematics Project" << endl;
    cout << "=====================================================" << endl;

    // University system initialize karo
    UniversitySystem system;

    // Files se data load karo - Courses, teachers, rooms, students
    cout << "\nLoading data from files..." << endl;

    Course courses[100];
    int courseCount = 0;
    FileHandler::loadCourses(courses, courseCount);

    // Courses ko system mein add karo
    for (int i = 0; i < courseCount; i++) {
        system.addCourse(new Course(courses[i]));
    }

    // Faculty load karo
    Faculty faculty[50];
    int facultyCount = 0;
    FileHandler::loadFaculty(faculty, facultyCount);

    for (int i = 0; i < facultyCount; i++) {
        system.addFaculty(new Faculty(faculty[i]));
    }

    // Students load karo
    Student students[200];
    int studentCount = 0;
    FileHandler::loadStudents(students, studentCount);

    for (int i = 0; i < studentCount; i++) {
        system.addStudent(new Student(students[i]));
    }

    // Prerequisites initialize karo
    system.initializePrerequisites();

    cout << "\nData loaded successfully!" << endl;
    cout << "Opening GUI window..." << endl;

    // GUI ko initialize karo aur run karo
    GUI gui(&system);
    gui.run();

    cout << "\nThank you for using FAST University Management System!" << endl;
    return 0;
}

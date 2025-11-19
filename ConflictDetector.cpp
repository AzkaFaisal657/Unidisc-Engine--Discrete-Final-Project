#include "ConflictDetector.h"
#include <iostream>

const int ConflictDetector::MAX_CREDITS_PER_SEMESTER;
const int ConflictDetector::MAX_COURSES_PER_FACULTY;

// Room capacity check karna
bool ConflictDetector::checkRoomCapacity(Room& room, int enrolledStudents) {
    // Agar students zyada hain room ki capacity se to conflict hai
    if (enrolledStudents > room.getCapacity()) {
        cout << "Conflict: Room " << room.getRoomId()
            << " capacity exceeded! Capacity: " << room.getCapacity()
            << ", Enrolled: " << enrolledStudents << endl;
        return false;  // Conflict hai
    }
    return true;  // Sab theek hai
}

// Student ke credit hours check karna
bool ConflictDetector::checkCreditLimit(Student& student, Course courses[], int courseCount, int maxCredits) {
    int totalCredits = 0;

    // Student ki enrolled courses ke credits jodo
    for (int i = 0; i < student.getEnrolledCount(); i++) {
        string courseCode = student.getEnrolledCourse(i);

        // Is course ko courses array mein dhundo
        for (int j = 0; j < courseCount; j++) {
            if (courses[j].getCode() == courseCode) {
                totalCredits += courses[j].getCreditHours();
                break;
            }
        }
    }

    // Check karo limit se zyada to nahi
    if (totalCredits > maxCredits) {
        cout << "Conflict: Student " << student.getId()
            << " has exceeded credit limit! Credits: " << totalCredits
            << ", Max: " << maxCredits << endl;
        return false;
    }

    return true;
}

// Time conflict check karna (basic implementation)
bool ConflictDetector::hasTimeConflict(string time1, string time2) {
    // Agar dono times same hain to conflict hai
    if (time1 == time2 && !time1.empty()) {
        return true;  // Conflict hai
    }
    return false;
}

// Prerequisite violation detect karna
bool ConflictDetector::detectPrerequisiteViolation(Student& student, Course& course,
    Course allCourses[], int courseCount) {
    // Course ke saare prerequisites check karo
    for (int i = 0; i < course.getPrereqCount(); i++) {
        string prereq = course.getPrerequisite(i);

        // Check karo ke student ne ye prerequisite complete kiya hai ya nahi
        if (!student.hasCompleted(prereq)) {
            cout << "Prerequisite Violation: Student " << student.getId()
                << " has not completed " << prereq
                << " (required for " << course.getCode() << ")" << endl;
            return true;  // Violation hai
        }
    }

    return false;  // Koi violation nahi
}

// Faculty teaching load check karna
bool ConflictDetector::detectTeachingOverload(Faculty& faculty, int maxCoursesPerFaculty) {
    if (faculty.getCourseCount() > maxCoursesPerFaculty) {
        cout << "Teaching Overload: " << faculty.getName()
            << " is teaching " << faculty.getCourseCount()
            << " courses (Max: " << maxCoursesPerFaculty << ")" << endl;
        return true;  // Overload hai
    }
    return false;
}

// Complete conflict report generate karna
void ConflictDetector::generateConflictReport(Student students[], int studentCount,
    Course courses[], int courseCount,
    Faculty faculty[], int facultyCount,
    Room rooms[], int roomCount) {
    cout << "\n=== CONFLICT DETECTION REPORT ===" << endl;
    cout << "System ke andar conflicts check kar rahe hain...\n" << endl;

    bool foundConflict = false;

    // 1. Student enrollment conflicts check karo
    cout << "1. Student Enrollment Conflicts:" << endl;
    for (int i = 0; i < studentCount; i++) {
        // Credit limit check
        if (!checkCreditLimit(students[i], courses, courseCount, MAX_CREDITS_PER_SEMESTER)) {
            foundConflict = true;
        }

        // Har enrolled course ke liye prerequisite check
        for (int j = 0; j < students[i].getEnrolledCount(); j++) {
            string courseCode = students[i].getEnrolledCourse(j);

            // Course ko dhundo
            for (int k = 0; k < courseCount; k++) {
                if (courses[k].getCode() == courseCode) {
                    if (detectPrerequisiteViolation(students[i], courses[k], courses, courseCount)) {
                        foundConflict = true;
                    }
                    break;
                }
            }
        }
    }

    if (!foundConflict) {
        cout << "No student enrollment conflicts found." << endl;
    }

    // 2. Faculty teaching load check
    cout << "\n2. Faculty Teaching Load:" << endl;
    bool facultyOverload = false;
    for (int i = 0; i < facultyCount; i++) {
        if (detectTeachingOverload(faculty[i], MAX_COURSES_PER_FACULTY)) {
            facultyOverload = true;
        }
    }

    if (!facultyOverload) {
        cout << "No faculty overload detected." << endl;
    }

    // 3. Room capacity analysis
    cout << "\n3. Room Capacity Analysis:" << endl;
    cout << "Total available rooms: " << roomCount << endl;
    int availableRooms = 0;
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].isAvailable()) {
            availableRooms++;
        }
    }
    cout << "Currently available: " << availableRooms << endl;
    cout << "Currently occupied: " << (roomCount - availableRooms) << endl;

    cout << "\n=== END OF CONFLICT REPORT ===" << endl;
}

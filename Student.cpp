#include "Student.h"

Student::Student() : id(""), name(""), currentSemester(0), completedCount(0), enrolledCount(0) {}

Student::Student(string id, string name, int semester)
    : id(id), name(name), currentSemester(semester), completedCount(0), enrolledCount(0) {
}

void Student::completeCourse(string courseCode) {
    // Remove from enrolled if present
    for (int i = 0; i < enrolledCount; i++) {
        if (enrolledCourses[i] == courseCode) {
            // Shift elements
            for (int j = i; j < enrolledCount - 1; j++) {
                enrolledCourses[j] = enrolledCourses[j + 1];
            }
            enrolledCount--;
            break;
        }
    }

    // Add to completed
    if (completedCount < 50 && !hasCompleted(courseCode)) {
        completedCourses[completedCount] = courseCode;
        completedCount++;
    }
}

void Student::enrollInCourse(string courseCode) {
    if (enrolledCount < 10 && !isEnrolled(courseCode)) {
        enrolledCourses[enrolledCount] = courseCode;
        enrolledCount++;
    }
}

bool Student::hasCompleted(string courseCode) const {
    for (int i = 0; i < completedCount; i++) {
        if (completedCourses[i] == courseCode) {
            return true;
        }
    }
    return false;
}

bool Student::isEnrolled(string courseCode) const {
    for (int i = 0; i < enrolledCount; i++) {
        if (enrolledCourses[i] == courseCode) {
            return true;
        }
    }
    return false;
}

string Student::getId() const { return id; }
string Student::getName() const { return name; }
int Student::getCurrentSemester() const { return currentSemester; }
int Student::getCompletedCount() const { return completedCount; }
int Student::getEnrolledCount() const { return enrolledCount; }

string Student::getCompletedCourse(int index) const {
    if (index >= 0 && index < completedCount) {
        return completedCourses[index];
    }
    return "";
}

string Student::getEnrolledCourse(int index) const {
    if (index >= 0 && index < enrolledCount) {
        return enrolledCourses[index];
    }
    return "";
}

void Student::display() const {
    cout << "Student: " << name << " (ID: " << id << ")" << endl;
    cout << "Current Semester: " << currentSemester << endl;
    cout << "Completed Courses: " << completedCount << endl;
    cout << "Enrolled Courses: " << enrolledCount << endl;
}
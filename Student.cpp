#include "Student.h"

// Default constructor - Khaali student object
Student::Student() : id(""), name(""), currentSemester(0), completedCount(0), enrolledCount(0) {}

// Parameterized constructor - Student ko ID, naam aur semester ke saath banata hai
// File se load karte waqt ya naya student add karte waqt ye use hota hai
Student::Student(string id, string name, int semester)
    : id(id), name(name), currentSemester(semester), completedCount(0), enrolledCount(0) {
}

// Course ko complete mark karna - Jab student exam pass kar le
// Pehle enrolled se remove karo, phir completed mein add karo
void Student::completeCourse(string courseCode) {
    // Pehle enrolled courses se remove karo agar abhi enrolled hai
    for (int i = 0; i < enrolledCount; i++) {
        if (enrolledCourses[i] == courseCode) {
            // Array mein se element remove karne ke liye sab ko shift karo
            for (int j = i; j < enrolledCount - 1; j++) {
                enrolledCourses[j] = enrolledCourses[j + 1];
            }
            enrolledCount--;
            break;
        }
    }

    // Ab completed courses mein add karo
    // Check karo ke pehle se completed to nahi aur limit se zyada to nahi
    if (completedCount < 50 && !hasCompleted(courseCode)) {
        completedCourses[completedCount] = courseCode;
        completedCount++;
    }
}

// Student ko course mein enroll karna - Semester start mein
// Maximum 10 courses mein ek baar mein enroll ho sakte hain
void Student::enrollInCourse(string courseCode) {
    if (enrolledCount < 10 && !isEnrolled(courseCode)) {
        enrolledCourses[enrolledCount] = courseCode;
        enrolledCount++;
    }
}

// Check karo ke student ne ye course complete kiya hai ya nahi
// Prerequisites verify karne ke liye zaroori hai
bool Student::hasCompleted(string courseCode) const {
    for (int i = 0; i < completedCount; i++) {
        if (completedCourses[i] == courseCode) {
            return true;  // Haan, complete ho chuka hai
        }
    }
    return false;  // Nahi, abhi complete nahi hua
}

// Check karo ke student abhi is course mein enrolled hai ya nahi
// Duplicate enrollment se bachne ke liye
bool Student::isEnrolled(string courseCode) const {
    for (int i = 0; i < enrolledCount; i++) {
        if (enrolledCourses[i] == courseCode) {
            return true;  // Haan, enrolled hai
        }
    }
    return false;  // Nahi, enrolled nahi hai
}

// Getter functions - Student ki basic information
string Student::getId() const { return id; }                        // Student ID jaise 22K-0001
string Student::getName() const { return name; }                    // Student ka naam
int Student::getCurrentSemester() const { return currentSemester; } // Abhi kon se semester mein hai
int Student::getCompletedCount() const { return completedCount; }  // Kitne courses complete kiye
int Student::getEnrolledCount() const { return enrolledCount; }    // Abhi kitne courses le raha hai

// Specific index par jo completed course hai wo return karo
// Loop mein saare completed courses access karne ke liye useful
string Student::getCompletedCourse(int index) const {
    if (index >= 0 && index < completedCount) {
        return completedCourses[index];
    }
    return "";  // Agar index out of range hai
}

// Specific index par jo enrolled course hai wo return karo
string Student::getEnrolledCourse(int index) const {
    if (index >= 0 && index < enrolledCount) {
        return enrolledCourses[index];
    }
    return "";  // Agar index out of range hai
}

// Student ki complete information console par display karna
void Student::display() const {
    cout << "Student: " << name << " (ID: " << id << ")" << endl;
    cout << "Current Semester: " << currentSemester << endl;
    cout << "Completed Courses: " << completedCount << endl;
    cout << "Enrolled Courses: " << enrolledCount << endl;
}
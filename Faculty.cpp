#include "Faculty.h"

// Default constructor - Khaali faculty object
Faculty::Faculty() : id(""), name(""), designation(""), courseCount(0) {}

// Parameterized constructor - Teacher ko ID, naam aur designation ke saath banata hai
Faculty::Faculty(string id, string name, string designation)
    : id(id), name(name), designation(designation), courseCount(0) {
}

// Faculty ko course assign karna - Semester start mein
// Ek teacher maximum 20 courses le sakta hai (usually 3-4 hi hote hain)
void Faculty::assignCourse(string courseCode) {
    if (courseCount < 20 && !isTeaching(courseCode)) {
        assignedCourses[courseCount] = courseCode;
        courseCount++;
    }
}

// Check karo ke ye teacher is course ko padha raha hai ya nahia
// Course-faculty mapping verify karne ke liye zaroori
bool Faculty::isTeaching(string courseCode) const {
    for (int i = 0; i < courseCount; i++) {
        if (assignedCourses[i] == courseCode) {
            return true;  // Haan, ye course is teacher ne liya hua hai
        }
    }
    return false;  // Nahi, ye course is teacher ka nahi hai
}

// Kitne courses assigned hain ye count return karta hai
// Teaching overload check karne ke liye useful
int Faculty::getCourseCount() const {
    return courseCount;
}

// Specific index par jo course assigned hai wo return karo
string Faculty::getAssignedCourse(int index) const {
    if (index >= 0 && index < courseCount) {
        return assignedCourses[index];
    }
    return "";  // Agar index galat hai
}

// Getter functions - Faculty ki basic information
string Faculty::getId() const { return id; }                  // Faculty ID jaise F001
string Faculty::getName() const { return name; }              // Teacher ka naam
string Faculty::getDesignation() const { return designation; } // Designation/rank

// Faculty ki information console par display karna
void Faculty::display() const {
    cout << name << " (" << designation << ")" << endl;
    cout << "Teaching " << courseCount << " courses" << endl;
}
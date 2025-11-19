#pragma once
#ifndef CONFLICTDETECTOR_H
#define CONFLICTDETECTOR_H

#include "Course.h"
#include "Student.h"
#include "Faculty.h"
#include "Room.h"
#include <string>
using namespace std;

// ConflictDetector class - System mein conflicts detect karta hai
// Jaise ke: room conflicts, credit hour limits, prerequisite violations
class ConflictDetector {
public:
    // Course scheduling conflicts detect karna
    // Check karta hai ke same room mein same time par 2 courses to nahi
    struct CourseConflict {
        string course1;
        string course2;
        string reason;      // Conflict ki wajah
        bool isConflict;    // Conflict hai ya nahi
    };

    // Student enrollment conflicts detect karna
    struct EnrollmentConflict {
        string studentId;
        string courseCode;
        string issue;       // Kya masla hai
    };

    // Room capacity conflicts check karna
    // Dekho ke kitne students enroll hain aur room ki capacity kya hai
    static bool checkRoomCapacity(Room& room, int enrolledStudents);

    // Credit hour limit check karna - Student zyada courses to nahi le raha
    static bool checkCreditLimit(Student& student, Course courses[], int courseCount, int maxCredits);

    // Overlapping time slots detect karna (agar time info available ho)
    static bool hasTimeConflict(string time1, string time2);

    // Prerequisite violations detect karna
    // Check karo ke student ne saare prerequisites complete kiye hain ya nahi
    static bool detectPrerequisiteViolation(Student& student, Course& course, Course allCourses[], int courseCount);

    // Faculty teaching overload check karna
    // Ek teacher ko zyada courses to nahi assign ho gaye
    static bool detectTeachingOverload(Faculty& faculty, int maxCoursesPerFaculty);

    // Saari conflicts ka summary print karna
    static void generateConflictReport(Student students[], int studentCount,
        Course courses[], int courseCount,
        Faculty faculty[], int facultyCount,
        Room rooms[], int roomCount);

private:
    static const int MAX_CREDITS_PER_SEMESTER = 18;  // Har semester mein max credits
    static const int MAX_COURSES_PER_FACULTY = 4;    // Har teacher max itne courses le sakta hai
};

#endif

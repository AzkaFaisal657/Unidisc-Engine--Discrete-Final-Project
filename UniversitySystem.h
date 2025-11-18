#ifndef UNIVERSITY_SYSTEM_H
#define UNIVERSITY_SYSTEM_H

#include "Course.h"
#include "Student.h"
#include "Faculty.h"
#include <string>
using namespace std;

class UniversitySystem {
private:
    Course* courses[100];
    Student* students[100];
    Faculty* faculty[50];
    int courseCount;
    int studentCount;
    int facultyCount;

    const int MAX_CREDITS_PER_SEMESTER = 21;

    // Helper function to check all prerequisites recursively (for induction)
    bool checkAllPrerequisites(Course* course, Student* student, string checked[], int& checkedCount);

public:
    UniversitySystem();
    ~UniversitySystem();

    void addCourse(Course* course);
    void addStudent(Student* student);
    void addFaculty(Faculty* fac);

    Course* getCourse(string code);
    Student* getStudent(string id);
    Faculty* getFaculty(string id);

    bool enrollStudent(string studentId, string courseCode, string& errorMsg);
    bool canStudentEnroll(string studentId, string courseCode, string& reason);

    void initializePrerequisites();

    int getCourseCount() const;
    int getStudentCount() const;
    int getFacultyCount() const;

    Course* getCourseByIndex(int index) const;
    Course* getCoursesBySemester(int semester, int& count);

    void displaySystemInfo() const;

    // Module functions
    void displayAllPrerequisites(string courseCode);
    void verifyPrerequisiteChainInduction(string courseCode, string studentId);
};

#endif
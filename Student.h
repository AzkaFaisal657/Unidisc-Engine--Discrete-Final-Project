#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    string id;
    string name;
    string completedCourses[50]; // Simple array
    string enrolledCourses[10];
    int completedCount;
    int enrolledCount;
    int currentSemester;

public:
    Student();
    Student(string id, string name, int semester);

    void completeCourse(string courseCode);
    void enrollInCourse(string courseCode);
    bool hasCompleted(string courseCode) const;
    bool isEnrolled(string courseCode) const;

    string getId() const;
    string getName() const;
    int getCurrentSemester() const;
    int getCompletedCount() const;
    int getEnrolledCount() const;
    string getCompletedCourse(int index) const;
    string getEnrolledCourse(int index) const;

    void display() const;
};

#endif
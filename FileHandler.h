#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>
#include "Course.h"
#include "Faculty.h"
#include "Room.h"
#include "Student.h"
using namespace std;

// FileHandler class - Files se data read/write karta hai
// Courses, teachers, rooms, students ki information files mein save karta hai
class FileHandler {
public:
    // Courses ko file se load karna
    // Parameters: courses array, count (kitne courses load hue)
    // Format: CourseCode,Name,Credits,Type,Semester,Prerequisites
    static void loadCourses(Course courses[], int& count);

    // Teachers ko file se load karna
    // Format: FacultyID,Name,Designation,Department
    static void loadFaculty(Faculty faculty[], int& count);

    // Rooms ko file se load karna  
    // Format: RoomID,Type,Capacity,Status
    static void loadRooms(Room rooms[], int& count);

    // Students ko file se load karna
    // Format: StudentID,Name,Semester
    static void loadStudents(Student students[], int& count);

    // Courses ko file mein save karna
    static void saveCourses(Course courses[], int count);

    // Students ki progress save karna
    static void saveStudentProgress(Student students[], int count);

private:
    // Helper function - String ko split karna comma ke basis par
    static void splitString(string str, string arr[], int& arrSize, char delimiter);

    // File paths - Data files kahan hain
    static const string COURSES_FILE;
    static const string FACULTY_FILE;
    static const string ROOMS_FILE;
    static const string STUDENTS_FILE;
};

#endif

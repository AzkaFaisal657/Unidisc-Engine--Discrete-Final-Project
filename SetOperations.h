#pragma once
#ifndef SET_OPERATIONS_H
#define SET_OPERATIONS_H

#include <string>
#include <iostream>
using namespace std;

// Simple Set class using arrays
class Set {
private:
    string elements[100];
    int size;

public:
    Set();

    void add(string element);
    bool contains(string element) const;
    int getSize() const;
    string getElement(int index) const;
    void display(string setName) const;

    // Set operations
    static Set unionSet(const Set& a, const Set& b);
    static Set intersection(const Set& a, const Set& b);
    static Set difference(const Set& a, const Set& b);
    static bool isSubset(const Set& a, const Set& b);
    static bool equals(const Set& a, const Set& b);
};

// Module class for set operations on university entities
class SetOperationsModule {
public:
    static void demonstrateSetOperations();
    static Set getStudentsInCourse(string courseCode);
    static Set getCoursesForStudent(string studentId);
    static void findCommonStudents(string course1, string course2);
};

#endif
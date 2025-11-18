#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course {
private:
    string code;
    string name;
    int creditHours;
    string type;
    int semester;
    string prerequisites[10]; // Simple array instead of set
    int prereqCount;

public:
    Course();
    Course(string code, string name, int credits, string type, int sem);

    void addPrerequisite(string prereqCode);
    bool hasPrerequisite(string prereqCode) const;
    int getPrereqCount() const;
    string getPrerequisite(int index) const;

    string getCode() const;
    string getName() const;
    int getCreditHours() const;
    string getType() const;
    int getSemester() const;

    void display() const;
};

#endif
#include "Course.h"

Course::Course() : code(""), name(""), creditHours(0), type(""), semester(0), prereqCount(0) {}

Course::Course(string code, string name, int credits, string type, int sem)
    : code(code), name(name), creditHours(credits), type(type), semester(sem), prereqCount(0) {
}

void Course::addPrerequisite(string prereqCode) {
    if (prereqCount < 10) {
        prerequisites[prereqCount] = prereqCode;
        prereqCount++;
    }
}

bool Course::hasPrerequisite(string prereqCode) const {
    for (int i = 0; i < prereqCount; i++) {
        if (prerequisites[i] == prereqCode) {
            return true;
        }
    }
    return false;
}

int Course::getPrereqCount() const {
    return prereqCount;
}

string Course::getPrerequisite(int index) const {
    if (index >= 0 && index < prereqCount) {
        return prerequisites[index];
    }
    return "";
}

string Course::getCode() const { return code; }
string Course::getName() const { return name; }
int Course::getCreditHours() const { return creditHours; }
string Course::getType() const { return type; }
int Course::getSemester() const { return semester; }

void Course::display() const {
    cout << code << " - " << name << " (" << creditHours << " credits)" << endl;
    if (prereqCount > 0) {
        cout << "  Prerequisites: ";
        for (int i = 0; i < prereqCount; i++) {
            cout << prerequisites[i];
            if (i < prereqCount - 1) cout << ", ";
        }
        cout << endl;
    }
}
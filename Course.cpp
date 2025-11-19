#include "Course.h"

// Default constructor - Khaali course object banata hai
// Jab koi values nahi hain to sab kuch empty initialize ho jata hai
Course::Course() : code(""), name(""), creditHours(0), type(""), semester(0), prereqCount(0) {}

// Parameterized constructor - Course ko values ke saath banata hai
// Jab file se ya manual course add karte hain to ye use hota hai
Course::Course(string code, string name, int credits, string type, int sem)
    : code(code), name(name), creditHours(credits), type(type), semester(sem), prereqCount(0) {
}

// Course mein prerequisite add karna
// Prerequisite wo course hai jo pehle complete karna zaroori hai
// Example: CS2001 (Data Structures) lene se pehle CS1004 (OOP) zaroori hai
void Course::addPrerequisite(string prereqCode) {
    if (prereqCount < 10) {  // Maximum 10 prerequisites ho sakte hain
        prerequisites[prereqCount] = prereqCode;
        prereqCount++;
    }
}

// Check karo ke koi specific prerequisite hai ya nahi
// Ye function enrollment ke waqt use hota hai
bool Course::hasPrerequisite(string prereqCode) const {
    for (int i = 0; i < prereqCount; i++) {
        if (prerequisites[i] == prereqCode) {
            return true;  // Mil gaya, ye prerequisite hai
        }
    }
    return false;  // Nahi mila, ye prerequisite nahi hai
}

// Kitne prerequisites hain ye count return karta hai
int Course::getPrereqCount() const {
    return prereqCount;
}

// Specific index par jo prerequisite hai wo return karo
// Example: getPrerequisite(0) pehla prerequisite dega
string Course::getPrerequisite(int index) const {
    if (index >= 0 && index < prereqCount) {
        return prerequisites[index];
    }
    return "";  // Agar index galat hai to empty string
}

// Getter functions - Course ki basic information return karte hain
string Course::getCode() const { return code; }          // Course code jaise CS2001
string Course::getName() const { return name; }          // Course ka naam
int Course::getCreditHours() const { return creditHours; } // Credit hours (usually 2-4)
string Course::getType() const { return type; }          // Core ya Elective
int Course::getSemester() const { return semester; }     // Kis semester mein padhaya jata hai

// Course ki complete information display karna
// Ye console par course ko print karne ke liye use hota hai
void Course::display() const {
    cout << code << " - " << name << " (" << creditHours << " credits)" << endl;

    // Agar prerequisites hain to unhe bhi dikhaao
    if (prereqCount > 0) {
        cout << "  Prerequisites: ";
        for (int i = 0; i < prereqCount; i++) {
            cout << prerequisites[i];
            if (i < prereqCount - 1) cout << ", ";  // Comma se separate karo
        }
        cout << endl;
    }
}
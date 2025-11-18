#include "UniversitySystem.h"

UniversitySystem::UniversitySystem() : courseCount(0), studentCount(0), facultyCount(0) {}

UniversitySystem::~UniversitySystem() {
    for (int i = 0; i < courseCount; i++) {
        delete courses[i];
    }
    for (int i = 0; i < studentCount; i++) {
        delete students[i];
    }
    for (int i = 0; i < facultyCount; i++) {
        delete faculty[i];
    }
}

void UniversitySystem::addCourse(Course* course) {
    if (courseCount < 100) {
        courses[courseCount] = course;
        courseCount++;
    }
}

void UniversitySystem::addStudent(Student* student) {
    if (studentCount < 100) {
        students[studentCount] = student;
        studentCount++;
    }
}

void UniversitySystem::addFaculty(Faculty* fac) {
    if (facultyCount < 50) {
        faculty[facultyCount] = fac;
        facultyCount++;
    }
}

Course* UniversitySystem::getCourse(string code) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i]->getCode() == code) {
            return courses[i];
        }
    }
    return nullptr;
}

Student* UniversitySystem::getStudent(string id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i]->getId() == id) {
            return students[i];
        }
    }
    return nullptr;
}

Faculty* UniversitySystem::getFaculty(string id) {
    for (int i = 0; i < facultyCount; i++) {
        if (faculty[i]->getId() == id) {
            return faculty[i];
        }
    }
    return nullptr;
}

// Recursive helper for induction - checks all prereqs
bool UniversitySystem::checkAllPrerequisites(Course* course, Student* student, string checked[], int& checkedCount) {
    // Base case: no prerequisites
    if (course->getPrereqCount() == 0) {
        return true;
    }

    // Check each direct prerequisite
    for (int i = 0; i < course->getPrereqCount(); i++) {
        string prereqCode = course->getPrerequisite(i);

        // Avoid infinite loops
        bool alreadyChecked = false;
        for (int j = 0; j < checkedCount; j++) {
            if (checked[j] == prereqCode) {
                alreadyChecked = true;
                break;
            }
        }
        if (alreadyChecked) continue;

        checked[checkedCount++] = prereqCode;

        // Student must have completed this prerequisite
        if (!student->hasCompleted(prereqCode)) {
            return false;
        }

        // Recursive step (Strong Induction): check prerequisites of this prerequisite
        Course* prereqCourse = getCourse(prereqCode);
        if (prereqCourse && !checkAllPrerequisites(prereqCourse, student, checked, checkedCount)) {
            return false;
        }
    }

    return true;
}

bool UniversitySystem::canStudentEnroll(string studentId, string courseCode, string& reason) {
    Student* student = getStudent(studentId);
    Course* course = getCourse(courseCode);

    if (!student) {
        reason = "Student not found";
        return false;
    }

    if (!course) {
        reason = "Course not found";
        return false;
    }

    if (student->hasCompleted(courseCode)) {
        reason = "Already completed this course";
        return false;
    }

    if (student->isEnrolled(courseCode)) {
        reason = "Already enrolled in this course";
        return false;
    }

    // Check prerequisites using induction
    string checked[50];
    int checkedCount = 0;
    if (!checkAllPrerequisites(course, student, checked, checkedCount)) {
        reason = "Prerequisites not met";
        return false;
    }

    // Check credit hours
    int currentCredits = 0;
    for (int i = 0; i < student->getEnrolledCount(); i++) {
        Course* enrolledCourse = getCourse(student->getEnrolledCourse(i));
        if (enrolledCourse) {
            currentCredits += enrolledCourse->getCreditHours();
        }
    }

    if (currentCredits + course->getCreditHours() > MAX_CREDITS_PER_SEMESTER) {
        reason = "Exceeds maximum credit hours per semester";
        return false;
    }

    reason = "Enrollment allowed";
    return true;
}

bool UniversitySystem::enrollStudent(string studentId, string courseCode, string& errorMsg) {
    if (canStudentEnroll(studentId, courseCode, errorMsg)) {
        Student* student = getStudent(studentId);
        student->enrollInCourse(courseCode);
        return true;
    }
    return false;
}

int UniversitySystem::getCourseCount() const {
    return courseCount;
}

int UniversitySystem::getStudentCount() const {
    return studentCount;
}

int UniversitySystem::getFacultyCount() const {
    return facultyCount;
}

Course* UniversitySystem::getCourseByIndex(int index) const {
    if (index >= 0 && index < courseCount) {
        return courses[index];
    }
    return nullptr;
}

Course* UniversitySystem::getCoursesBySemester(int semester, int& count) {
    static Course* semesterCourses[50];
    count = 0;

    for (int i = 0; i < courseCount; i++) {
        if (courses[i]->getSemester() == semester) {
            semesterCourses[count] = courses[i];
            count++;
        }
    }

    return semesterCourses[0];
}

void UniversitySystem::initializePrerequisites() {
    // Semester 2 prerequisites
    if (Course* cs1004 = getCourse("CS1004")) cs1004->addPrerequisite("CS1002");
    if (Course* mt1008 = getCourse("MT1008")) mt1008->addPrerequisite("MT1003");

    // Semester 3 prerequisites
    if (Course* cs2001 = getCourse("CS2001")) cs2001->addPrerequisite("CS1004");
    if (Course* ee2003 = getCourse("EE2003")) ee2003->addPrerequisite("EE1005");
    if (Course* mt1004 = getCourse("MT1004")) mt1004->addPrerequisite("MT1003");

    // Semester 4 prerequisites
    if (Course* cs2005 = getCourse("CS2005")) cs2005->addPrerequisite("CS2001");
    if (Course* cs2006 = getCourse("CS2006")) cs2006->addPrerequisite("CS2001");
    if (Course* se2004 = getCourse("SE2004")) se2004->addPrerequisite("CS1004");
    if (Course* se2001 = getCourse("SE2001")) se2001->addPrerequisite("SE1001");
    if (Course* mt2005 = getCourse("MT2005")) mt2005->addPrerequisite("MT1008");

    // Semester 5 prerequisites
    if (Course* cs2009 = getCourse("CS2009")) cs2009->addPrerequisite("CS2001");
    if (Course* ai2002 = getCourse("AI2002")) ai2002->addPrerequisite("CS2001");
    if (Course* se3002 = getCourse("SE3002")) se3002->addPrerequisite("SE2001");
    if (Course* se3004 = getCourse("SE3004")) se3004->addPrerequisite("SE2004");

    // Semester 6 prerequisites
    if (Course* cs3001 = getCourse("CS3001")) cs3001->addPrerequisite("CS2006");
    if (Course* cs3006 = getCourse("CS3006")) cs3006->addPrerequisite("CS2006");
    if (Course* se4002 = getCourse("SE4002")) se4002->addPrerequisite("SE3004");

    // Semester 7 prerequisites
    if (Course* se4091 = getCourse("SE4091")) se4091->addPrerequisite("SE4002");

    // Semester 8 prerequisites
    if (Course* se4092 = getCourse("SE4092")) se4092->addPrerequisite("SE4091");
    if (Course* cs3002 = getCourse("CS3002")) cs3002->addPrerequisite("CS3001");
}

void UniversitySystem::displaySystemInfo() const {
    cout << "=== FAST University System ===" << endl;
    cout << "Total Courses: " << courseCount << endl;
    cout << "Total Students: " << studentCount << endl;
    cout << "Total Faculty: " << facultyCount << endl;
}

// Helper to get all prerequisites recursively
static void getAllPrereqsRecursive(Course* course, UniversitySystem* system, string allPrereqs[], int& count, string visited[], int& visitedCount) {
    for (int i = 0; i < course->getPrereqCount(); i++) {
        string prereqCode = course->getPrerequisite(i);

        // Check if already visited
        bool alreadyVisited = false;
        for (int j = 0; j < visitedCount; j++) {
            if (visited[j] == prereqCode) {
                alreadyVisited = true;
                break;
            }
        }

        if (!alreadyVisited) {
            visited[visitedCount++] = prereqCode;
            allPrereqs[count++] = prereqCode;

            // Recurse on this prerequisite
            Course* prereqCourse = system->getCourse(prereqCode);
            if (prereqCourse) {
                getAllPrereqsRecursive(prereqCourse, system, allPrereqs, count, visited, visitedCount);
            }
        }
    }
}

void UniversitySystem::displayAllPrerequisites(string courseCode) {
    Course* course = getCourse(courseCode);
    if (!course) {
        cout << "Course not found!" << endl;
        return;
    }

    cout << "\n=== All Prerequisites for " << courseCode << " ===" << endl;

    string allPrereqs[50];
    string visited[50];
    int count = 0;
    int visitedCount = 0;

    getAllPrereqsRecursive(course, this, allPrereqs, count, visited, visitedCount);

    if (count == 0) {
        cout << "No prerequisites required." << endl;
    }
    else {
        cout << "Total prerequisites: " << count << endl;
        for (int i = 0; i < count; i++) {
            Course* prereqCourse = getCourse(allPrereqs[i]);
            if (prereqCourse) {
                cout << "  - " << allPrereqs[i] << ": " << prereqCourse->getName() << endl;
            }
        }
    }
}

void UniversitySystem::verifyPrerequisiteChainInduction(string courseCode, string studentId) {
    Course* course = getCourse(courseCode);
    Student* student = getStudent(studentId);

    if (!course || !student) {
        cout << "Course or student not found!" << endl;
        return;
    }

    cout << "\n=== Prerequisite Chain Verification (Using Induction) ===" << endl;
    cout << "Target Course: " << courseCode << " - " << course->getName() << endl;
    cout << "Student: " << student->getName() << endl;

    string checked[50];
    int checkedCount = 0;
    bool isValid = checkAllPrerequisites(course, student, checked, checkedCount);

    cout << "\nVerification Result: " << (isValid ? "COMPLETE " : "INCOMPLETE ") << endl;

    if (!isValid) {
        cout << "\nMissing Prerequisites:" << endl;
        string allPrereqs[50];
        string visited[50];
        int count = 0;
        int visitedCount = 0;
        getAllPrereqsRecursive(course, this, allPrereqs, count, visited, visitedCount);

        for (int i = 0; i < count; i++) {
            if (!student->hasCompleted(allPrereqs[i])) {
                Course* prereqCourse = getCourse(allPrereqs[i]);
                cout << "  - " << allPrereqs[i];
                if (prereqCourse) cout << ": " << prereqCourse->getName();
                cout << endl;
            }
        }
    }
    else {
        cout << "Student has completed all " << checkedCount << " required prerequisites!" << endl;
    }
}
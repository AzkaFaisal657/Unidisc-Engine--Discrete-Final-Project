#include "Relations.h"

Relation::Relation() : pairCount(0) {}

void Relation::addPair(string first, string second) {
    if (pairCount < 100) {
        pairs[pairCount].first = first;
        pairs[pairCount].second = second;
        pairCount++;
    }
}

bool Relation::hasPair(string first, string second) const {
    for (int i = 0; i < pairCount; i++) {
        if (pairs[i].first == first && pairs[i].second == second) {
            return true;
        }
    }
    return false;
}

int Relation::getPairCount() const {
    return pairCount;
}

Pair Relation::getPair(int index) const {
    if (index >= 0 && index < pairCount) {
        return pairs[index];
    }
    Pair empty = { "", "" };
    return empty;
}

void Relation::display(string relationName) const {
    cout << relationName << " = { ";
    for (int i = 0; i < pairCount; i++) {
        cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
        if (i < pairCount - 1) cout << ", ";
    }
    cout << " }" << endl;
}

bool Relation::isReflexive(string domain[], int domainSize) const {
    // For each element in domain, check if (a,a) exists
    for (int i = 0; i < domainSize; i++) {
        if (!hasPair(domain[i], domain[i])) {
            return false;
        }
    }
    return true;
}

bool Relation::isSymmetric() const {
    // For each (a,b), check if (b,a) exists
    for (int i = 0; i < pairCount; i++) {
        string a = pairs[i].first;
        string b = pairs[i].second;

        if (a != b) { // Skip reflexive pairs
            if (!hasPair(b, a)) {
                return false;
            }
        }
    }
    return true;
}

bool Relation::isTransitive() const {
    // For each (a,b) and (b,c), check if (a,c) exists
    for (int i = 0; i < pairCount; i++) {
        string a = pairs[i].first;
        string b = pairs[i].second;

        for (int j = 0; j < pairCount; j++) {
            if (pairs[j].first == b) {
                string c = pairs[j].second;
                if (!hasPair(a, c)) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Relation::isEquivalence(string domain[], int domainSize) const {
    return isReflexive(domain, domainSize) && isSymmetric() && isTransitive();
}

bool Relation::isPartialOrder(string domain[], int domainSize) const {
    // Check reflexive
    if (!isReflexive(domain, domainSize)) {
        return false;
    }

    // Check antisymmetric: if (a,b) and (b,a) exist, then a = b
    for (int i = 0; i < pairCount; i++) {
        string a = pairs[i].first;
        string b = pairs[i].second;

        if (a != b && hasPair(b, a)) {
            return false;
        }
    }

    // Check transitive
    return isTransitive();
}

Relation Relation::compose(const Relation& r1, const Relation& r2) {
    Relation result;

    // For each pair (a,b) in r1 and (b,c) in r2, add (a,c) to result
    for (int i = 0; i < r1.pairCount; i++) {
        string a = r1.pairs[i].first;
        string b = r1.pairs[i].second;

        for (int j = 0; j < r2.pairCount; j++) {
            if (r2.pairs[j].first == b) {
                string c = r2.pairs[j].second;
                result.addPair(a, c);
            }
        }
    }

    return result;
}

void RelationsModule::demonstrateRelations() {
    cout << "\n=== RELATIONS MODULE ===" << endl;
    cout << "Demonstrating Binary Relations and Properties\n" << endl;

    // Example: Prerequisite relation
    Relation prereqRelation;
    prereqRelation.addPair("CS2001", "CS1004");
    prereqRelation.addPair("CS1004", "CS1002");
    prereqRelation.addPair("CS2005", "CS2001");

    cout << "Prerequisite Relation (Course, Prerequisite):" << endl;
    prereqRelation.display("PrereqRel");
    cout << endl;

    // Check properties
    cout << "Relation Properties:" << endl;
    cout << "Reflexive: " << (prereqRelation.isReflexive(nullptr, 0) ? "Yes" : "No") << endl;
    cout << "Symmetric: " << (prereqRelation.isSymmetric() ? "Yes" : "No") << endl;
    cout << "Transitive: " << (prereqRelation.isTransitive() ? "Yes" : "No") << endl;
    cout << endl;

    // Example of equivalence relation
    cout << "Example: Semester Equivalence Relation" << endl;
    Relation semesterRel;
    semesterRel.addPair("Student1", "Student1");
    semesterRel.addPair("Student2", "Student2");
    semesterRel.addPair("Student1", "Student2");
    semesterRel.addPair("Student2", "Student1");

    semesterRel.display("SameSemester");

    string domain[] = { "Student1", "Student2" };
    cout << "Is Equivalence Relation? " << (semesterRel.isEquivalence(domain, 2) ? "Yes" : "No") << endl;
}

void RelationsModule::checkStudentCourseRelation() {
    cout << "\n=== Student-Course Relation ===" << endl;
    cout << "Represents enrollment: (Student, Course)" << endl;

    Relation enrollment;
    enrollment.addPair("22K-0001", "CS2001");
    enrollment.addPair("22K-0001", "CS1005");
    enrollment.addPair("22K-0002", "CS2001");

    enrollment.display("Enrollment");
}

void RelationsModule::checkFacultyCourseRelation() {
    cout << "\n=== Faculty-Course Relation ===" << endl;
    cout << "Represents teaching assignment: (Faculty, Course)" << endl;

    Relation teaching;
    teaching.addPair("Dr. Qamar", "CS1002");
    teaching.addPair("Dr. Affan", "CS1004");
    teaching.addPair("Dr. Qamar", "CS2001");

    teaching.display("Teaching");

    cout << "\nChecking if relation is a function (each faculty -> at most one course)" << endl;
    cout << "No, Dr. Qamar teaches multiple courses (not a function)" << endl;
}

void RelationsModule::checkPrerequisiteRelation() {
    cout << "\n=== Prerequisite Partial Order ===" << endl;
    cout << "Prerequisites form a partial order on courses" << endl;

    Relation prereq;
    prereq.addPair("CS1002", "CS1002"); // Reflexive
    prereq.addPair("CS1004", "CS1004");
    prereq.addPair("CS2001", "CS2001");
    prereq.addPair("CS1004", "CS1002"); // CS1004 requires CS1002
    prereq.addPair("CS2001", "CS1004"); // CS2001 requires CS1004
    prereq.addPair("CS2001", "CS1002"); // Transitive

    prereq.display("Prerequisite");

    string courses[] = { "CS1002", "CS1004", "CS2001" };
    cout << "\nIs Partial Order? " << (prereq.isPartialOrder(courses, 3) ? "Yes" : "No") << endl;
    cout << "Interpretation: Course dependencies form a hierarchy" << endl;
}
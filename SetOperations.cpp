#include "SetOperations.h"

Set::Set() : size(0) {}

void Set::add(string element) {
    if (!contains(element) && size < 100) {
        elements[size] = element;
        size++;
    }
}

bool Set::contains(string element) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == element) {
            return true;
        }
    }
    return false;
}

int Set::getSize() const {
    return size;
}

string Set::getElement(int index) const {
    if (index >= 0 && index < size) {
        return elements[index];
    }
    return "";
}

void Set::display(string setName) const {
    cout << setName << " = { ";
    for (int i = 0; i < size; i++) {
        cout << elements[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " }" << endl;
    cout << "Cardinality: " << size << endl;
}

Set Set::unionSet(const Set& a, const Set& b) {
    Set result;

    // Add all elements from set a
    for (int i = 0; i < a.size; i++) {
        result.add(a.elements[i]);
    }

    // Add all elements from set b
    for (int i = 0; i < b.size; i++) {
        result.add(b.elements[i]);
    }

    return result;
}

Set Set::intersection(const Set& a, const Set& b) {
    Set result;

    // Add elements that are in both sets
    for (int i = 0; i < a.size; i++) {
        if (b.contains(a.elements[i])) {
            result.add(a.elements[i]);
        }
    }

    return result;
}

Set Set::difference(const Set& a, const Set& b) {
    Set result;

    // Add elements from a that are not in b
    for (int i = 0; i < a.size; i++) {
        if (!b.contains(a.elements[i])) {
            result.add(a.elements[i]);
        }
    }

    return result;
}

bool Set::isSubset(const Set& a, const Set& b) {
    // Check if all elements of a are in b
    for (int i = 0; i < a.size; i++) {
        if (!b.contains(a.elements[i])) {
            return false;
        }
    }
    return true;
}

bool Set::equals(const Set& a, const Set& b) {
    return isSubset(a, b) && isSubset(b, a);
}

void SetOperationsModule::demonstrateSetOperations() {
    cout << "\n=== SET OPERATIONS MODULE ===" << endl;
    cout << "Demonstrating Set Theory on University Data\n" << endl;

    // Example: Students taking CS courses
    Set csStudents;
    csStudents.add("22K-0001");
    csStudents.add("22K-0002");
    csStudents.add("22K-0003");

    // Example: Students taking Math courses
    Set mathStudents;
    mathStudents.add("22K-0002");
    mathStudents.add("22K-0003");
    mathStudents.add("22K-0004");

    csStudents.display("CS Students");
    cout << endl;
    mathStudents.display("Math Students");
    cout << endl;

    // Union
    Set unionResult = Set::unionSet(csStudents, mathStudents);
    cout << "UNION (CS ∪ Math) - Students in either:" << endl;
    unionResult.display("Result");
    cout << endl;

    // Intersection
    Set intersectionResult = Set::intersection(csStudents, mathStudents);
    cout << "INTERSECTION (CS ∩ Math) - Students in both:" << endl;
    intersectionResult.display("Result");
    cout << endl;

    // Difference
    Set differenceResult = Set::difference(csStudents, mathStudents);
    cout << "DIFFERENCE (CS - Math) - Only CS students:" << endl;
    differenceResult.display("Result");
    cout << endl;

    // Subset check
    Set smallSet;
    smallSet.add("22K-0001");
    cout << "SUBSET CHECK:" << endl;
    cout << "Is {22K-0001} ⊆ CS Students? " << (Set::isSubset(smallSet, csStudents) ? "Yes" : "No") << endl;
}
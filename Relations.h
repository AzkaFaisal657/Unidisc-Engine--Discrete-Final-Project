#ifndef RELATIONS_H
#define RELATIONS_H

#include <string>
#include <iostream>
using namespace std;

// Ordered pair structure
struct Pair {
    string first;
    string second;
};

// Relation class - set of ordered pairs
class Relation {
private:
    Pair pairs[100];
    int pairCount;

public:
    Relation();

    void addPair(string first, string second);
    bool hasPair(string first, string second) const;
    int getPairCount() const;
    Pair getPair(int index) const;
    void display(string relationName) const;

    // Relation properties
    bool isReflexive(string domain[], int domainSize) const;
    bool isSymmetric() const;
    bool isTransitive() const;
    bool isEquivalence(string domain[], int domainSize) const;
    bool isPartialOrder(string domain[], int domainSize) const;

    // Relation operations
    static Relation compose(const Relation& r1, const Relation& r2);
};

// Module for university relations
class RelationsModule {
public:
    static void demonstrateRelations();
    static void checkStudentCourseRelation();
    static void checkFacultyCourseRelation();
    static void checkPrerequisiteRelation();
};

#endif
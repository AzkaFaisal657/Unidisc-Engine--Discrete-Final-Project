#ifndef COMBINATIONS_H
#define COMBINATIONS_H

#include <string>
#include <iostream>
using namespace std;

// Structure to hold student group information
struct StudentGroup {
    string members[10];
    int memberCount;
};

// Module 2: Student Group Combinations
class CombinationsModule {
private:
    static int factorial(int n);
    static void generateCombinationsHelper(string students[], int n, int r,
        int index, string data[], int i,
        StudentGroup groups[], int& groupCount);

public:
    // Calculate nCr (combinations)
    static int calculateCombinations(int n, int r);

    // Calculate nPr (permutations)
    static int calculatePermutations(int n, int r);

    // Generate all possible groups of size r from n students
    static void generateAllGroups(string students[], int n, int r, StudentGroup groups[], int& groupCount);

    // Assign students to project groups
    static void assignProjectGroups(string students[], int studentCount, int groupSize);

    // Assign students to lab sessions
    static void assignLabSessions(string students[], int studentCount, int labCapacity);

    // Choose students for elective courses
    static void assignElectives(string students[], int studentCount, int electiveSlots);

    // Demonstrate all combination operations
    static void demonstrateCombinations();

    // Display a single group
    static void displayGroup(StudentGroup& group, int groupNum);
};

#endif
#pragma once

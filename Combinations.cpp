

#include "Combinations.h"

// Calculate factorial
int CombinationsModule::factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Calculate nCr = n! / (r! * (n-r)!)
int CombinationsModule::calculateCombinations(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    // Optimize by using smaller factorial
    if (r > n - r) {
        r = n - r;
    }

    int result = 1;
    for (int i = 0; i < r; i++) {
        result = result * (n - i) / (i + 1);
    }

    return result;
}

// Calculate nPr = n! / (n-r)!
int CombinationsModule::calculatePermutations(int n, int r) {
    if (r > n) return 0;

    int result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
    }

    return result;
}

// Helper function to generate combinations recursively
void CombinationsModule::generateCombinationsHelper(string students[], int n, int r,
    int index, string data[], int i,
    StudentGroup groups[], int& groupCount) {
    // Current combination is ready
    if (index == r) {
        for (int j = 0; j < r; j++) {
            groups[groupCount].members[j] = data[j];
        }
        groups[groupCount].memberCount = r;
        groupCount++;
        return;
    }

    // When no more elements are there to put in data[]
    if (i >= n) {
        return;
    }

    // Current is included, put next at next location
    data[index] = students[i];
    generateCombinationsHelper(students, n, r, index + 1, data, i + 1, groups, groupCount);

    // Current is excluded, replace it with next
    generateCombinationsHelper(students, n, r, index, data, i + 1, groups, groupCount);
}

// Generate all possible groups
void CombinationsModule::generateAllGroups(string students[], int n, int r,
    StudentGroup groups[], int& groupCount) {
    string data[10];
    groupCount = 0;
    generateCombinationsHelper(students, n, r, 0, data, 0, groups, groupCount);
}

// Display a group
void CombinationsModule::displayGroup(StudentGroup& group, int groupNum) {
    cout << "Group " << groupNum << ": { ";
    for (int i = 0; i < group.memberCount; i++) {
        cout << group.members[i];
        if (i < group.memberCount - 1) cout << ", ";
    }
    cout << " }" << endl;
}

// Assign students to project groups
void CombinationsModule::assignProjectGroups(string students[], int studentCount, int groupSize) {
    cout << "\n=== PROJECT GROUP ASSIGNMENT ===" << endl;
    cout << "Students: " << studentCount << endl;
    cout << "Group Size: " << groupSize << endl;

    int totalGroups = calculateCombinations(studentCount, groupSize);
    cout << "Total Possible Groups (C(" << studentCount << "," << groupSize << ")): " << totalGroups << endl;
    cout << endl;

    if (totalGroups > 20) {
        cout << "Showing first 20 groups (too many to display all):" << endl;
    }
    else {
        cout << "All Possible Group Combinations:" << endl;
    }

    StudentGroup groups[100];
    int groupCount = 0;
    generateAllGroups(students, studentCount, groupSize, groups, groupCount);

    int displayLimit = (groupCount > 20) ? 20 : groupCount;
    for (int i = 0; i < displayLimit; i++) {
        displayGroup(groups[i], i + 1);
    }

    if (groupCount > 20) {
        cout << "... and " << (groupCount - 20) << " more groups" << endl;
    }
}

// Assign students to lab sessions
void CombinationsModule::assignLabSessions(string students[], int studentCount, int labCapacity) {
    cout << "\n=== LAB SESSION ASSIGNMENT ===" << endl;
    cout << "Total Students: " << studentCount << endl;
    cout << "Lab Capacity: " << labCapacity << " per session" << endl;

    int sessionsNeeded = (studentCount + labCapacity - 1) / labCapacity; // Ceiling division
    cout << "Sessions Needed: " << sessionsNeeded << endl;
    cout << endl;

    cout << "Ways to select " << labCapacity << " students for first session:" << endl;
    int ways = calculateCombinations(studentCount, labCapacity);
    cout << "C(" << studentCount << "," << labCapacity << ") = " << ways << " ways" << endl;
    cout << endl;

    cout << "Sample Lab Session Assignment:" << endl;
    int currentStudent = 0;
    for (int session = 1; session <= sessionsNeeded; session++) {
        cout << "Session " << session << ": { ";
        int studentsInSession = 0;
        while (studentsInSession < labCapacity && currentStudent < studentCount) {
            cout << students[currentStudent];
            currentStudent++;
            studentsInSession++;
            if (studentsInSession < labCapacity && currentStudent < studentCount) {
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }
}

// Choose students for elective courses
void CombinationsModule::assignElectives(string students[], int studentCount, int electiveSlots) {
    cout << "\n=== ELECTIVE COURSE ASSIGNMENT ===" << endl;
    cout << "Students Interested: " << studentCount << endl;
    cout << "Available Slots: " << electiveSlots << endl;

    if (electiveSlots > studentCount) {
        cout << "All students can be accommodated!" << endl;
        return;
    }

    int selectionWays = calculateCombinations(studentCount, electiveSlots);
    cout << "Ways to select students: C(" << studentCount << "," << electiveSlots << ") = " << selectionWays << endl;
    cout << endl;

    cout << "Sample selections (first 10):" << endl;
    StudentGroup groups[100];
    int groupCount = 0;
    generateAllGroups(students, studentCount, electiveSlots, groups, groupCount);

    int displayLimit = (groupCount > 10) ? 10 : groupCount;
    for (int i = 0; i < displayLimit; i++) {
        cout << "Selection " << (i + 1) << ": { ";
        for (int j = 0; j < groups[i].memberCount; j++) {
            cout << groups[i].members[j];
            if (j < groups[i].memberCount - 1) cout << ", ";
        }
        cout << " }" << endl;
    }
}

// Main demonstration function
void CombinationsModule::demonstrateCombinations() {
    cout << "\n========================================" << endl;
    cout << "   MODULE 2: COMBINATIONS & COUNTING" << endl;
    cout << "========================================" << endl;

    // Sample students
    string students[] = { "Ali", "Sara", "Ahmed", "Fatima", "Hassan", "Ayesha" };
    int studentCount = 6;

    cout << "\nAvailable Students: ";
    for (int i = 0; i < studentCount; i++) {
        cout << students[i];
        if (i < studentCount - 1) cout << ", ";
    }
    cout << endl;

    // 1. Basic Combination Calculation
    cout << "\n--- PART 1: COMBINATION FORMULAS ---" << endl;
    cout << "C(6,2) = " << calculateCombinations(6, 2) << " (Choose 2 from 6)" << endl;
    cout << "C(6,3) = " << calculateCombinations(6, 3) << " (Choose 3 from 6)" << endl;
    cout << "C(6,4) = " << calculateCombinations(6, 4) << " (Choose 4 from 6)" << endl;
    cout << "\nP(6,2) = " << calculatePermutations(6, 2) << " (Arrange 2 from 6)" << endl;
    cout << "P(6,3) = " << calculatePermutations(6, 3) << " (Arrange 3 from 6)" << endl;

    // 2. Project Groups
    cout << "\n--- PART 2: PROJECT GROUPS (3 members) ---" << endl;
    assignProjectGroups(students, studentCount, 3);

    // 3. Lab Sessions
    cout << "\n--- PART 3: LAB SESSION DISTRIBUTION ---" << endl;
    assignLabSessions(students, studentCount, 2);

    // 4. Elective Selection
    cout << "\n--- PART 4: ELECTIVE COURSE SELECTION ---" << endl;
    assignElectives(students, studentCount, 4);

    // 5. Real-world Scenario
    cout << "\n--- PART 5: REAL-WORLD SCENARIO ---" << endl;
    cout << "Scenario: Software Engineering Final Year Project" << endl;
    cout << "- 20 students need to form groups of 4" << endl;
    cout << "- How many different groups possible?" << endl;
    cout << "\nAnswer: C(20,4) = " << calculateCombinations(20, 4) << " possible groups" << endl;
    cout << "Number of complete groups: 20 / 4 = 5 groups" << endl;

    cout << "\n========================================" << endl;
}
#include "PrerequisiteGraph.h"
#include <iostream>
#include <queue>

void PrerequisiteGraph::addCourse(std::string courseCode) {
    if (adjacencyList.find(courseCode) == adjacencyList.end()) {
        adjacencyList[courseCode] = std::set<std::string>();
    }
}

void PrerequisiteGraph::addPrerequisite(std::string course, std::string prerequisite) {
    addCourse(course);
    addCourse(prerequisite);
    adjacencyList[course].insert(prerequisite);
}

bool PrerequisiteGraph::hasDirectPrerequisite(std::string course, std::string prerequisite) const {
    auto it = adjacencyList.find(course);
    if (it == adjacencyList.end()) return false;
    return it->second.find(prerequisite) != it->second.end();
}

bool PrerequisiteGraph::hasPathDFS(std::string from, std::string to, std::set<std::string>& visited) const {
    if (from == to) return true;

    visited.insert(from);

    auto it = adjacencyList.find(from);
    if (it != adjacencyList.end()) {
        for (const auto& prereq : it->second) {
            if (visited.find(prereq) == visited.end()) {
                if (hasPathDFS(prereq, to, visited)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool PrerequisiteGraph::hasIndirectPrerequisite(std::string course, std::string prerequisite) const {
    std::set<std::string> visited;
    return hasPathDFS(course, prerequisite, visited);
}

std::set<std::string> PrerequisiteGraph::getAllPrerequisites(std::string courseCode) const {
    std::set<std::string> allPrereqs;
    std::queue<std::string> toProcess;

    auto it = adjacencyList.find(courseCode);
    if (it == adjacencyList.end()) return allPrereqs;

    for (const auto& prereq : it->second) {
        toProcess.push(prereq);
    }

    while (!toProcess.empty()) {
        std::string current = toProcess.front();
        toProcess.pop();

        if (allPrereqs.find(current) == allPrereqs.end()) {
            allPrereqs.insert(current);

            auto currentIt = adjacencyList.find(current);
            if (currentIt != adjacencyList.end()) {
                for (const auto& prereq : currentIt->second) {
                    toProcess.push(prereq);
                }
            }
        }
    }

    return allPrereqs;
}

bool PrerequisiteGraph::canEnroll(std::string courseCode, const std::set<std::string>& completedCourses) const {
    auto allPrereqs = getAllPrerequisites(courseCode);

    for (const auto& prereq : allPrereqs) {
        if (completedCourses.find(prereq) == completedCourses.end()) {
            return false;
        }
    }

    return true;
}

bool PrerequisiteGraph::verifyPrerequisiteChain(std::string courseCode, const std::set<std::string>& completedCourses) const {
    return canEnroll(courseCode, completedCourses);
}

void PrerequisiteGraph::display() const {
    std::cout << "Prerequisite Graph:" << std::endl;
    for (const auto& pair : adjacencyList) {
        std::cout << pair.first << " requires: ";
        if (pair.second.empty()) {
            std::cout << "None";
        }
        else {
            for (const auto& prereq : pair.second) {
                std::cout << prereq << " ";
            }
        }
        std::cout << std::endl;
    }
}

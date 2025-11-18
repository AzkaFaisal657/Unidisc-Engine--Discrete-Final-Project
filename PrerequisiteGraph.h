#pragma once
#ifndef PREREQUISITE_GRAPH_H
#define PREREQUISITE_GRAPH_H

#include <string>
#include <map>
#include <set>
#include <vector>

class PrerequisiteGraph {
private:
    std::map<std::string, std::set<std::string>> adjacencyList;

    bool hasPathDFS(std::string from, std::string to, std::set<std::string>& visited) const;

public:
    void addCourse(std::string courseCode);
    void addPrerequisite(std::string course, std::string prerequisite);

    bool hasDirectPrerequisite(std::string course, std::string prerequisite) const;
    bool hasIndirectPrerequisite(std::string course, std::string prerequisite) const;
    std::set<std::string> getAllPrerequisites(std::string courseCode) const;

    bool canEnroll(std::string courseCode, const std::set<std::string>& completedCourses) const;
    bool verifyPrerequisiteChain(std::string courseCode, const std::set<std::string>& completedCourses) const;

    void display() const;
};

#endif


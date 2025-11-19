#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
using namespace std;

// Room class - Kamron ki information store karta hai
// Har room ka ID, type, capacity aur availability track karta hai
class Room {
private:
    string roomId;          // Room ka unique ID jaise R101, L201
    string roomType;        // Room ki type: Lecture Hall, Lab, Seminar Room
    int capacity;           // Kitne students aa sakte hain
    string status;          // Available ya Occupied
    string assignedCourse;  // Agar occupied hai to kis course ke liye

public:
    // Constructors - Room object banane ke liye
    Room();
    Room(string id, string type, int cap, string stat);

    // Setters - Room ki information set karne ke liye
    void assignToCourse(string courseCode);  // Course assign karna
    void releaseRoom();                       // Room ko free karna
    void setStatus(string stat);              // Status change karna

    // Getters - Room ki information lene ke liye
    string getRoomId() const;
    string getRoomType() const;
    int getCapacity() const;
    string getStatus() const;
    string getAssignedCourse() const;
    bool isAvailable() const;                 // Check karo ke room khali hai ya nahi

    // Display - Room ki complete info print karna
    void display() const;
};

#endif

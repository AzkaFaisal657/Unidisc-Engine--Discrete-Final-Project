#include "Room.h"

// Default constructor - Khaali room object banata hai
Room::Room() : roomId(""), roomType(""), capacity(0), status("Available"), assignedCourse("") {}

// Parameterized constructor - Values ke saath room banata hai
Room::Room(string id, string type, int cap, string stat)
    : roomId(id), roomType(type), capacity(cap), status(stat), assignedCourse("") {
}

// Course ko room assign karna
void Room::assignToCourse(string courseCode) {
    assignedCourse = courseCode;
    status = "Occupied";  // Room ab occupied ho gaya
}

// Room ko free karna - course khatam hone ke baad
void Room::releaseRoom() {
    assignedCourse = "";
    status = "Available";  // Room ab khali hai
}

// Room ka status change karna
void Room::setStatus(string stat) {
    status = stat;
}

// Getters - Simple information return karte hain
string Room::getRoomId() const { return roomId; }
string Room::getRoomType() const { return roomType; }
int Room::getCapacity() const { return capacity; }
string Room::getStatus() const { return status; }
string Room::getAssignedCourse() const { return assignedCourse; }

// Check karo ke room available hai ya nahi
bool Room::isAvailable() const {
    return status == "Available";
}

// Room ki complete information display karna
void Room::display() const {
    cout << "Room ID: " << roomId << endl;
    cout << "Type: " << roomType << endl;
    cout << "Capacity: " << capacity << " students" << endl;
    cout << "Status: " << status << endl;
    if (!assignedCourse.empty()) {
        cout << "Assigned to: " << assignedCourse << endl;
    }
}

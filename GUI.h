#pragma once
#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "UniversitySystem.h"
using namespace std;
using namespace sf;

// GUI class - SFML use karke graphical interface banata hai
// Console ke bajaye proper window mein application chalti hai
class GUI {
private:
    RenderWindow* window;              // Main window jismein sab kuch dikhega
    UniversitySystem* system;          // University system ka pointer
    Font font;                         // Text display karne ke liye font
    
    // GUI states - Konsa screen dikha rahe hain
    enum State {
        MAIN_MENU,            // Start screen - Menu
        VIEW_COURSES,         // Courses dekhna
        VIEW_STUDENTS,        // Students ki list
        ENROLLMENT,           // Course mein enroll karna
        DISCRETE_DEMOS,       // Discrete math demonstrations
        CONFLICT_REPORT,      // Conflicts check karna
        EXIT_CONFIRM          // Exit confirmation
    };
    
    State currentState;               // Current screen konsa hai
    int selectedOption;               // Menu mein kaunsa option select hai
    int selectedSemester;             // View courses ke liye semester
    string selectedStudentId;         // Selected student ka ID
    
    // Colors - Interface ke liye colors
    Color backgroundColor;
    Color titleColor;
    Color textColor;
    Color buttonColor;
    Color selectedColor;
    
public:
    // Constructor - GUI setup karna
    GUI(UniversitySystem* sys);
    
    // Destructor - Cleanup
    ~GUI();
    
    // Main loop - GUI ko run karna
    void run();
    
private:
    // Window setup karna
    void initWindow();
    
    // Font load karna
    bool loadFont();
    
    // Events handle karna (mouse clicks, keyboard)
    void handleEvents();
    
    // Screen ko update karna
    void update();
    
    // Screen par draw karna
    void render();
    
    // Different screens draw karna
    void drawMainMenu();
    void drawCoursesView();
    void drawStudentsView();
    void drawEnrollmentScreen();
    void drawDiscreteDemos();
    void drawConflictReport();
    void drawExitConfirm();
    
    // Helper functions
    void drawText(string text, float x, float y, int size, Color color);
    void drawButton(string text, float x, float y, float width, float height, bool selected);
    void drawBox(float x, float y, float width, float height, Color fillColor, Color outlineColor);
    
    // Input handling
    void handleMainMenuInput(Event& event);
    void handleCoursesViewInput(Event& event);
    void handleEnrollmentInput(Event& event);
};

#endif

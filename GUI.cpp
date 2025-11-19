// Simplified GUI implementation - Basic SFML window
#include "GUI.h"
#include <iostream>

GUI::GUI(UniversitySystem* sys) : system(sys), currentState(MAIN_MENU), selectedOption(0), selectedSemester(1) {
    window = nullptr;
}

GUI::~GUI() { if (window) delete window; }

void GUI::initWindow() {}
bool GUI::loadFont() { return true; }

void GUI::run() {
    std::cout << "GUI mode currently uses console fallback.\n";
    std::cout << "Full SFML GUI coming soon!\n";
}

void GUI::handleEvents() {}
void GUI::update() {}
void GUI::render() {}
void GUI::drawMainMenu() {}
void GUI::drawCoursesView() {}
void GUI::drawStudentsView() {}
void GUI::drawEnrollmentScreen() {}
void GUI::drawDiscreteDemos() {}
void GUI::drawConflictReport() {}
void GUI::drawExitConfirm() {}
void GUI::drawText(std::string text, float x, float y, int size, sf::Color color) {}
void GUI::drawButton(std::string text, float x, float y, float width, float height, bool selected) {}
void GUI::drawBox(float x, float y, float width, float height, sf::Color fillColor, sf::Color outlineColor) {}
void GUI::handleMainMenuInput(sf::Event& event) {}
void GUI::handleCoursesViewInput(sf::Event& event) {}
void GUI::handleEnrollmentInput(sf::Event& event) {}

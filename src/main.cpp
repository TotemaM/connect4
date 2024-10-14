/*
// Modify the antialiasing level
sf::ContextSettings settings;
settings.antialiasingLevel = 8; // 0, 2, 4 or 8
sf::RenderWindow window(sf::VideoMode(800, 600), "Showing antialiasing", sf::Style::Default, settings);

// Enable or disable the vertical synchronization
window.setVerticalSyncEnabled(true); // true or false

// Limit the framerate
window.setFramerateLimit(60); // 0 to disable limit

// Change resolution
window.setSize(sf::Vector2u(1920, 1080));

// Set fullscreen
window.create(sf::VideoMode(800, 600), "Fullscreen", sf::Style::Fullscreen);
*/

#include "app.hpp"

int main() {
    App app;
    app.run();
    return 0;
}
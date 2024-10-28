#pragma once
// File inclusions
#include "menus/main_menu.hpp"
#include "menus/game_menu.hpp"
// Standard libraries
#include <iostream>
#include <memory>
using namespace std;
// SFML libraries
#include <SFML/Graphics.hpp>
// Window dimensions
#define WIDHT 512
#define HEIGHT 512
// Class handling the menus of the SFML GUI
class App {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(WIDHT, HEIGHT), "Connect 4");
    unique_ptr<Menu> current_menu = make_unique<MainMenu>();
    Menu::Type change_menu = Menu::Type::MAIN;
    public:
    // Launching SFML GUI
    void run();
};
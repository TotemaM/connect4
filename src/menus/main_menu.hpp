#pragma once
// File inclusions
#include "menu.hpp"
#include "gui/image.hpp"
// Class for the main menu of the SFML GUI
class MainMenu: public Menu {
    Image background = Image("img/main_menu.png", 0, 0);
public:
    MainMenu();
    Type handle_event(sf::Event event) override;
};
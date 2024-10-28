// Reference header
#include "menus/main_menu.hpp"

MainMenu::MainMenu() {
    type = MAIN;
    items = { &background };
}
Menu::Type MainMenu::handle_event(sf::Event event) {
    switch (event.type) {
        case sf::Event::MouseMoved: {
            break;
        }
        case sf::Event::MouseButtonPressed: {
            return Menu::GAME;
        }
        default: break;
    }
    return type;
}
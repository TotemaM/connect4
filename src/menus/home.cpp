// Reference header
#include "menus/home.hpp"

HomeMenu::HomeMenu() {
    type = HOME;
    items = { &background };
}
Menu::Type HomeMenu::handle_event(sf::Event event) {
    switch (event.type) {
        case sf::Event::MouseMoved: {
            break;
        }
        case sf::Event::MouseButtonPressed: {
            return Menu::CONFIG;
        }
        default: break;
    }
    return type;
}
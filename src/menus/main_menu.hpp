#pragma once

#include "menu.hpp"
#include "gui/image.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
using namespace std;

class MainMenu: public Menu {
    Image background = Image("img/main_menu.png", 0, 0);
public:
    MainMenu() {
        type = MAIN;
        items = { &background };
    }
    Type handle_event(sf::Event event) override {
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
};
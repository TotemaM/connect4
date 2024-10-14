#pragma once

#include "menu.hpp"
#include "gui/button.hpp"

class SettingsMenu: public Menu {
    Type type = SETTINGS;
    Button back_button = Button(sf::Vector2f(200, 50), sf::Vector2f(300, 200), "back");
public:
    using Menu::Menu;
    ~SettingsMenu() {}
    Type getType() const override { return type; }
    Type handle_event(sf::Event event) override {
        switch (event.type) {
            case sf::Event::MouseMoved: back_button.hover(event.mouseMove.x, event.mouseMove.y); break;
            case sf::Event::MouseButtonPressed: if (back_button.isHovered(event.mouseButton.x, event.mouseButton.y)) { return Menu::MAIN; } break;
            case sf::Event::KeyPressed: {
                switch(event.key.code) {
                    case sf::Keyboard::Escape: return Menu::MAIN;
                    default: break;
                }
            }
            default: break;
        }
        return type;
    }
    void draw() const override {
        window->draw(back_button);
    }
};
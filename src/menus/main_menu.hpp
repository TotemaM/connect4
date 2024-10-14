#pragma once

#include "menu.hpp"
#include "gui/button.hpp"

class MainMenu: public Menu {
    Type type = MAIN;
    Button play_button = Button(sf::Vector2f(200, 50), sf::Vector2f(300, 200), "Play");
    Button settings_button = Button(sf::Vector2f(200, 50), sf::Vector2f(300, 300), "Settings");
public:
    using Menu::Menu;
    ~MainMenu() {}
    Type getType() const override { return type; }
    Type handle_event(sf::Event event) override {
        switch (event.type) {
            case sf::Event::MouseMoved: {
                play_button.hover(event.mouseMove.x, event.mouseMove.y);
                settings_button.hover(event.mouseMove.x, event.mouseMove.y);
                break;
            }
            case sf::Event::MouseButtonPressed: {
                if (play_button.isHovered(event.mouseButton.x, event.mouseButton.y)) { return Menu::GAME_SETTINGS; }
                if (settings_button.isHovered(event.mouseButton.x, event.mouseButton.y)) { return Menu::SETTINGS; }
                break;
            }
            default: break;
        }
        return type;
    }
    void draw() const override {
        window->draw(play_button);
        window->draw(settings_button);
    }
};
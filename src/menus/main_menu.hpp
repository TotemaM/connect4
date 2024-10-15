#pragma once

#include "menu.hpp"
#include "gui/button.hpp"
#include "gui/text.hpp"

class MainMenu: public Menu {
    Type type = MAIN;
    Text title = Text("Connect 4", window->getSize().x/2, window->getSize().y/2-100);
    Button play_button = Button("Play", window->getSize().x/2, window->getSize().y/2, 200, 50);
    Button settings_button = Button("Settings", window->getSize().x/2, window->getSize().y/2+100, 200, 50);
    Text credits = Text("Totema - 2024", 40, window->getSize().y-10, 12, "font/arial.ttf", sf::Color::Black);
public:
    using Menu::Menu;
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
        window->draw(title);
        window->draw(play_button);
        window->draw(settings_button);
        window->draw(credits);
    }
};
#pragma once

#include "menu.hpp"
#include "menus/gui/button.hpp"
#include "menus/gui/text.hpp"

#include <vector>
using namespace std;

class MainMenu: public Menu {
    Type const type = MAIN;
    Text title = Text("Connect 4", window->getSize().x/2, window->getSize().y/2-100, 50, Anchor::Type::C, "font/8bit.ttf", sf::Color::White);
    Button play_button = Button("Play", window->getSize().x/2, window->getSize().y/2, 200, 50, Anchor::Type::C);
    Button settings_button = Button("Settings", window->getSize().x/2, window->getSize().y/2+100, 200, 50, Anchor::Type::C);
    Text credits = Text("Totema - 2024", 10, window->getSize().y-10, 10, Anchor::Type::SW, "font/arial.ttf", sf::Color::Black);
    vector<sf::Drawable*> items = { &title, &play_button, &settings_button, &credits };
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
    void draw() const override { for (auto item: items) { window->draw(*item); } }
};
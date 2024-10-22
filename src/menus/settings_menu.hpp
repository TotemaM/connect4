#pragma once

#include "menu.hpp"
#include "menus/gui/button.hpp"
#include "settings.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>
using namespace std;

class SettingsMenu: public Menu {
    Type const type = SETTINGS;
    shared_ptr<SettingsManager> settings;
    Text title = Text("Settings", window->getSize().x/2, window->getSize().y/2-100, 50, Anchor::Type::C, "font/8bit.ttf", sf::Color::White);
    Button back_button = Button("Back", window->getSize().x/2, window->getSize().y/2, 200, 50, Anchor::Type::C);
    Button apply_button = Button("Apply", window->getSize().x/2, window->getSize().y/2+100, 200, 50, Anchor::Type::C);
    vector<sf::Drawable*> items = { &title, &back_button, &apply_button };
public:
    SettingsMenu(shared_ptr<sf::RenderWindow> window, shared_ptr<SettingsManager> settings): Menu(window), settings(settings) {}
    Type getType() const override { return type; }
    Type handle_event(sf::Event event) override {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (back_button.isHovered(event.mouseButton.x, event.mouseButton.y)) { return Menu::MAIN; }
            else if (apply_button.isHovered(event.mouseButton.x, event.mouseButton.y)) { /* TODO */ }
        }
        else if (event.type == sf::Event::MouseMoved) {
            back_button.hover(event.mouseMove.x, event.mouseMove.y);
            apply_button.hover(event.mouseMove.x, event.mouseMove.y);
        }
        return type;
    }
    void draw() const override { for (auto item: items) { window->draw(*item); } }
};
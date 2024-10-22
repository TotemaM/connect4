#pragma once

#include "menus/main_menu.hpp"
#include "menus/settings_menu.hpp"
#include "settings.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
using namespace std;

class App {
    shared_ptr<SettingsManager> settings = make_shared<SettingsManager>();
    shared_ptr<sf::RenderWindow> window = make_shared<sf::RenderWindow>(sf::VideoMode(settings->getWidth(), settings->getHeight()), "Connect 4");
    unique_ptr<Menu> current_menu = make_unique<MainMenu>(window);
    Menu::Type change_menu = Menu::Type::MAIN;
    public:
    void run() {
        while(window->isOpen()) {
            sf::Event event;
            while(window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) { window->close(); }
                else if (event.type == sf::Event::Resized) { window->setSize({settings->getWidth(), settings->getHeight()}); }
                else { change_menu = current_menu->handle_event(event); }
            }
            if (change_menu != current_menu->getType()) {
                switch (change_menu) {
                    case Menu::MAIN: current_menu = make_unique<MainMenu>(window); break;
                    case Menu::SETTINGS: current_menu = make_unique<SettingsMenu>(window, settings); break;
                    default: current_menu = make_unique<MainMenu>(window); break;
                }
            }
            window->clear(sf::Color::Blue);
            current_menu->draw();
            window->display();
        }
    }
};
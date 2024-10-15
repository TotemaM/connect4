#pragma once

#include "menus/main_menu.hpp"
#include "menus/settings_menu.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
using namespace std;

class App {
    shared_ptr<sf::RenderWindow> window = make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Connect 4");
    unique_ptr<Menu> current_menu = make_unique<MainMenu>(window);
    Menu::Type change_menu = Menu::Type::MAIN;
    public:
    void run() {
        while(window->isOpen()) {
            if (change_menu != current_menu->getType()) {
                switch (change_menu) {
                    case Menu::MAIN: current_menu = make_unique<MainMenu>(window); break;
                    case Menu::SETTINGS: current_menu = make_unique<SettingsMenu>(window); break;
                    default: break;
                }
            }
            sf::Event event;
            while(window->pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed: window->close(); break;
                    default: change_menu = current_menu->handle_event(event); break;
                }
            }
            window->clear(sf::Color::Blue);
            current_menu->draw();
            window->display();
        }
    }
};
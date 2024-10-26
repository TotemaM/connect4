#pragma once

#include "menus/main_menu.hpp"
#include "menus/game_menu.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
using namespace std;

#define WIDHT 512
#define HEIGHT 512

class App {
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(WIDHT, HEIGHT), "Connect 4");
    unique_ptr<Menu> current_menu = make_unique<MainMenu>();
    Menu::Type change_menu = Menu::Type::MAIN;
    public:
    void run() {
        while(window.isOpen()) {
            sf::Event event;
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) { window.close(); }
                else if (event.type == sf::Event::Resized) { window.setSize({WIDHT, HEIGHT}); }
                else { change_menu = current_menu->handle_event(event); }
            }
            if (change_menu != current_menu->getType()) {
                switch (change_menu) {
                    case Menu::MAIN: current_menu = make_unique<MainMenu>(); break;
                    case Menu::GAME: current_menu = make_unique<GameMenu>(); break;
                    default: current_menu = make_unique<MainMenu>(); break;
                }
            }
            window.clear();
            window.draw(*current_menu);
            window.display();
        }
    }
};
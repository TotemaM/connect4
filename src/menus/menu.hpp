#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <vector>
using namespace std;

class Menu {
public:
    Menu(shared_ptr<sf::RenderWindow> window): window(window) {}
    virtual ~Menu() {}
    enum Type {
        MAIN,
        GAME_SETTINGS,
        SETTINGS
    };
    virtual Type getType() const = 0;
    virtual Type handle_event(sf::Event event) = 0;
    virtual void draw() const = 0;
protected:
    shared_ptr<sf::RenderWindow> window;
};
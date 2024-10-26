#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
using namespace std;

class Menu : public sf::Drawable {
public:
    Menu() = default;
    virtual ~Menu() {}
    enum Type {
        NONE,
        MAIN,
        GAME
    };
    Type getType() const { return type; }
    virtual Type handle_event(sf::Event event) = 0;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        for (auto item: items) { target.draw(*item, states); }
    }
protected:
    vector<sf::Drawable*> items;
    Type type = NONE;
};
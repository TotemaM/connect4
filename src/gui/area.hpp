#pragma once

#include "gui/anchor.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
using namespace std;

class Area: public sf::Drawable {
    Anchor anchor;
    sf::Color outline_hover;
    sf::Color outline_default;
    sf::RectangleShape rectangle;
    bool clicked = false;
public:
    Area(int x, int y, int width, int height, sf::Color outline_hover = sf::Color::Transparent, sf::Color outline_default = sf::Color::Black, Anchor::Type anchor_type = Anchor::Type::NW): outline_hover(outline_hover), outline_default(outline_default) {
        rectangle.setOutlineThickness(2);
        rectangle.setFillColor(sf::Color::Transparent);
        rectangle.setSize(sf::Vector2f(width, height));
        anchor.attach(x, y, width, height, anchor_type);
        rectangle.setPosition(anchor.getX(), anchor.getY());
    }
    // Handling visual change when hovering
    void hover(int x, int y) {
        if (clicked) { return; }
        if (rectangle.getGlobalBounds().contains(x, y)) { rectangle.setOutlineColor(outline_hover); }
        else { rectangle.setOutlineColor(outline_default); }
    }
    bool isHovered(int x, int y) { return rectangle.getGlobalBounds().contains(x, y); }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(rectangle, states);
    }
    void click() {
        if (clicked) { return; }
        clicked = true;
        rectangle.setOutlineColor(outline_hover);
    }
    void unclick() {
        if (!clicked) { return; }
        clicked = false;
        rectangle.setOutlineColor(outline_default);
    }
};
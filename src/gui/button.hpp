#pragma once

#include "gui/anchor.hpp"
#include "gui/text.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
using namespace std;

class Button: public sf::Drawable {
public:
    Button(string txt, int x, int y, int width, int height, Anchor::Type anchor_type = Anchor::Type::NW, string font_path = "font/8bit.ttf", sf::Color fill_color = sf::Color::White, sf::Color outline_color = sf::Color::Black): text(txt, x, y, 42-txt.length()*2.5, Anchor::Type::C, font_path), rectangle(sf::Vector2f(width, height)) {
        rectangle.setFillColor(fill_color);
        rectangle.setOutlineColor(outline_color);
        rectangle.setOutlineThickness(1);
        rectangle.setSize(sf::Vector2f(width, height));
        anchor.attach(x, y, width, height, anchor_type);
        rectangle.setPosition(anchor.getX(), anchor.getY());
    }
    // Handling visual change when hovering
    void hover(int x, int y) {
        if (rectangle.getGlobalBounds().contains(x, y)) { rectangle.setOutlineColor(sf::Color::Red); }
        else { rectangle.setOutlineColor(sf::Color::Black); }
    }
    bool isHovered(int x, int y) {
        return rectangle.getGlobalBounds().contains(x, y);
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(rectangle, states);
        target.draw(text, states);
    }
private:
    Anchor anchor;
    Text text;
    sf::Font font;
    sf::RectangleShape rectangle;
};
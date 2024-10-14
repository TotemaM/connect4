#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
using namespace std;

class Button: public sf::Drawable {
    public:
    Button(sf::Vector2f size, sf::Vector2f position, string txt): rectangle(size) {
        rectangle.setFillColor(sf::Color::White);
        rectangle.setOutlineColor(sf::Color::Black);
        rectangle.setOutlineThickness(1);
        rectangle.setPosition(position);
        font.loadFromFile("font/8bit.ttf");
        text.setFont(font);
        text.setString(txt);
        text.setCharacterSize(24); // TODO set text size based on button size
        text.setFillColor(sf::Color::Black);
        text.setPosition(position.x + 10, position.y + 10); // TODO set better text position
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
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rectangle;
};
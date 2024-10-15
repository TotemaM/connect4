#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
using namespace std;
#include <iostream>

class Button: public sf::Drawable {
    public:
    Button(string txt, int x, int y, int width, int height, string font_path = "font/8bit.ttf", sf::Color fill_color = sf::Color::White, sf::Color outline_color = sf::Color::Black): rectangle(sf::Vector2f(width, height)) {
        text.setString(txt);
        text.setCharacterSize(32-(txt.length()*1.5));
        font.loadFromFile(font_path);
        text.setFont(font);
        text.setPosition(x-this->text.getGlobalBounds().width/2, y-this->text.getGlobalBounds().height/2);
        text.setFillColor(sf::Color::Black);
        rectangle.setFillColor(fill_color);
        rectangle.setOutlineColor(outline_color);
        rectangle.setOutlineThickness(1);
        rectangle.setSize(sf::Vector2f(width, height));
        rectangle.setPosition(x-width/2, y-height/2);
        text.setPosition((x-width/2)+(width/2-text.getGlobalBounds().width/2), (y-height/2)+(height/2-text.getGlobalBounds().height/2)+text.getCharacterSize()*0.18); // TODO set better text position
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
    sf::Text text;
    sf::Font font;
    sf::RectangleShape rectangle;
};
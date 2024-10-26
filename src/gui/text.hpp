#pragma once

#include "gui/anchor.hpp"

#include <SFML/Graphics.hpp>

#include <string>
using namespace std;

class Text : public sf::Drawable {
    Anchor anchor;
    sf::Text text;
    sf::Font font;
public:
    Text(string txt, int x, int y, int size, Anchor::Type anchor_type = Anchor::Type::NW, string font_path = "font/8bit.ttf", sf::Color color = sf::Color::Black) {
        text.setString(txt);
        font.loadFromFile(font_path);
        text.setFont(font);
        text.setCharacterSize(size);
        anchor.attach(x, y, text.getGlobalBounds().width, text.getGlobalBounds().height, anchor_type);
        text.setPosition(anchor.getX(), anchor.getY()+size*0.18);
        text.setFillColor(color);
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override { target.draw(text, states); }
};
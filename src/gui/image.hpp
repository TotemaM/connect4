#pragma once

#include <SFML/Graphics.hpp>

#include <string>
using namespace std;

#include "gui/anchor.hpp"

class Image: public sf::Drawable {
    sf::Texture texture;
    sf::Sprite sprite;
    Anchor anchor;
public:
    Image(string path, int x, int y, Anchor::Type anchor_type = Anchor::NW) {
        if (!texture.loadFromFile(path)) { }
        anchor.attach(x, y, texture.getSize().x, texture.getSize().y, anchor_type);
        sprite.setPosition(anchor.getX(), anchor.getY());
        sprite.setTexture(texture);
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override { target.draw(sprite, states); }
};
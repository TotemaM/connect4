#pragma once

#include "gui/anchor.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
using namespace std;

class Layout: public sf::Drawable {
public:
    enum Orientation { Horizontal, Vertical };
    Layout(vector<sf::Drawable*> elements, Orientation orientation, int x, int y, int width, int height, Anchor::Type anchor_type = Anchor::Type::NE): elements(elements) {
        // TODO
    }
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        for (sf::Drawable* element: elements) { target.draw(*element, states); }
    }
protected:
    vector<sf::Drawable*> elements;
};
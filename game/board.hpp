#pragma once

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable {
    vector<vector<int>> grid = vector<vector<int>>(6, vector<int>(7, 0));
public:
    Board() = default;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        for (short unsigned int i = 0; i < 6; i++) {
            for (short unsigned int j = 0; j < 7; j++) {
                int x = j*64 + 64;
                int y = i*64 + 128;
                switch (grid[i][j]) {
                    case 1: target.draw(Image("img/circle_red.png", x, y, Anchor::Type::C), states); break;
                    case 2: target.draw(Image("img/circle_yellow.png", x, y, Anchor::Type::C), states); break;
                    default: break;
                }
            }
        }
    }
};
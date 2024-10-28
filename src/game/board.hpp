#pragma once
// File inclusions
#include "game/color.hpp"
// Standard library
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
using namespace std;
// SFML library
#include <SFML/Graphics.hpp>
// Coordinate structure for the board
struct Coordinate {
    short unsigned int i;
    short unsigned int j;
};
// Game board
class Board : public sf::Drawable {
    static const int WIDTH = 7;
    static const int HEIGHT = 6;
    Color board[HEIGHT][WIDTH];
    unsigned int MAX_ROUND = WIDTH * HEIGHT;
    unsigned int current_round = 0;
    Color winner = Color(Color::Type::WHITE);
public:
    Board();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void display(const short unsigned int playerID = 2, const Coordinate* lastMove = nullptr) const;
    unsigned int getMaxRound() const;
    bool validPlay(const short unsigned int &column) const;
    /* !!! Check if the play is valid before calling this function */
    Coordinate play(const short unsigned int &column, const Color &color);
    bool checkVictory();
    bool isBoardFull() const { return current_round == MAX_ROUND; }
    vector<short unsigned int> getValidMoves() const;
    Color getWinner() const;
};
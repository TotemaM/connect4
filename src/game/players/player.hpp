#pragma once
#include "game/color.hpp"
#include "game/board.hpp"

class Player {
    Color color;
public:
    enum Type { NONE, USER, RANDOM, MINIMAX, CUSTOM };
    Player(const Color color) : color(color) {}
    virtual ~Player() {}
    Color getColor() const { return color; }
    virtual short unsigned int play(Board board) = 0;
    Type getType() const { return type; }
protected:
    Type type = NONE;
};
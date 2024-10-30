#pragma once

#include "game/players/player.hpp"
#include "game/rng.hpp"

class Custom : public Player {
public:
    Custom(const Color color): Player(color) { type = Type::CUSTOM; }
    // Rewrite the play function to implement your custom player
    short unsigned int play(const Board board [[maybe_unused]]) override {
        vector<short unsigned int> moveset = board.getValidMoves();
        return moveset[RNG::randRange(0, moveset.size() - 1)];
    }
};
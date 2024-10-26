#include "game/players/player.hpp"
#include "game/rng.hpp"

class Random : public Player {
public:
    Random(const Color color): Player(color) {
        type = Type::RANDOM;
    }
    short unsigned int play(const Board board [[maybe_unused]]) override {
        vector<short unsigned int> moveset = board.getValidMoves();
        return moveset[RNG::randRange(0, moveset.size() - 1)];
    }
};
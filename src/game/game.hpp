#pragma once

#include "game/board.hpp"
#include "game/players/user.hpp"
#include "game/players/random.hpp"
#include "game/players/minimax.hpp"
#include "game/players/custom.hpp"
#include "gui/text.hpp"
#include <atomic>

class Game : public sf::Drawable {
public:
    enum Winner { YELLOW = 0, RED = 1, DRAW = 2, NONE = 4};
    Game(Player::Type p1, Player::Type p2);
    void start();
    // Returning true if move is valid
    bool userPlay(short unsigned int column);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    Player::Type getCurrentPlayerType() const;
    int getWinner() const;
private:
    unique_ptr<Board> board;
    unique_ptr<Player> players[2];
    short unsigned int current;
    atomic<int> winner =  Winner::NONE;
};
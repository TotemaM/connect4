#pragma once
// File inclusions
#include "game/players/player.hpp"

struct GameConfig {
    Player::Type player1 = Player::Type::NONE;
    Player::Type player2 = Player::Type::NONE;
};
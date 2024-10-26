#pragma once

#include "game/players/player.hpp"

class User : public Player {
public:
    User() {
        type = Type::USER;
    }
};